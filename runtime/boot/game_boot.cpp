#include "game_boot.h"
#include "recomp_bridge.h"

#include "../hal/fs.h"
#include "../hal/sys.h"

#include <algorithm>
#include <cassert>
#include <climits>
#include <cstdlib>
#include <cstring>
#include <iomanip>
#include <memory>
#include <sstream>
#include <vector>

#include <aes.hpp>
#include <lzx.h>
#include <mspack.h>
#include <TinySHA1.hpp>

#if defined(_WIN32)
#include <intrin.h>
#include <windows.h>
#endif

namespace {

constexpr uint32_t kXexHeaderEntryPoint = 0x00010100;
constexpr uint32_t kXexHeaderImageBaseAddress = 0x00010201;
constexpr uint32_t kXexHeaderFileFormatInfo = 0x000003FF;
constexpr uint16_t kXexEncryptionNone = 0;
constexpr uint16_t kXexCompressionNone = 0;
constexpr uint16_t kXexCompressionBasic = 1;
constexpr uint16_t kXexCompressionNormal = 2;
constexpr uint64_t kGuestMemorySize = 0x100000000ull;
constexpr uint8_t kXex2RetailKey[16] = { 0x20, 0xB1, 0x85, 0xA5, 0x9D, 0x28, 0xFD, 0xC3, 0x40, 0x58, 0x3F, 0xBB, 0x08, 0x96, 0xBF, 0x91 };
constexpr uint8_t kAesBlankIv[16] = {};

struct mspack_memory_file {
    mspack_system sys;
    void* buffer;
    size_t buffer_size;
    size_t offset;
};

static mspack_memory_file* mspack_memory_open(mspack_system*, void* buffer, size_t buffer_size)
{
    assert(buffer_size < INT_MAX);
    if (buffer_size >= INT_MAX) return nullptr;

    auto* memory_file = static_cast<mspack_memory_file*>(std::calloc(1, sizeof(mspack_memory_file)));
    if (!memory_file) return nullptr;

    memory_file->buffer = buffer;
    memory_file->buffer_size = buffer_size;
    return memory_file;
}

static void mspack_memory_close(mspack_memory_file* file)
{
    std::free(file);
}

static int mspack_memory_read(mspack_file* file, void* buffer, int chars)
{
    auto* memory_file = reinterpret_cast<mspack_memory_file*>(file);
    const size_t remaining = memory_file->buffer_size - memory_file->offset;
    const size_t total = std::min(size_t(chars), remaining);
    std::memcpy(buffer, static_cast<uint8_t*>(memory_file->buffer) + memory_file->offset, total);
    memory_file->offset += total;
    return int(total);
}

static int mspack_memory_write(mspack_file* file, void* buffer, int chars)
{
    auto* memory_file = reinterpret_cast<mspack_memory_file*>(file);
    const size_t remaining = memory_file->buffer_size - memory_file->offset;
    const size_t total = std::min(size_t(chars), remaining);
    std::memcpy(static_cast<uint8_t*>(memory_file->buffer) + memory_file->offset, buffer, total);
    memory_file->offset += total;
    return int(total);
}

static void* mspack_memory_alloc(mspack_system*, size_t chars)
{
    return std::calloc(chars, 1);
}

static void mspack_memory_free(void* ptr)
{
    std::free(ptr);
}

static void mspack_memory_copy(void* src, void* dest, size_t chars)
{
    std::memcpy(dest, src, chars);
}

static mspack_system* mspack_memory_sys_create()
{
    auto* sys = static_cast<mspack_system*>(std::calloc(1, sizeof(mspack_system)));
    if (!sys) return nullptr;

    sys->read = mspack_memory_read;
    sys->write = mspack_memory_write;
    sys->alloc = mspack_memory_alloc;
    sys->free = mspack_memory_free;
    sys->copy = mspack_memory_copy;
    return sys;
}

static void mspack_memory_sys_destroy(mspack_system* sys)
{
    std::free(sys);
}

bool bit_scan_forward(uint32_t value, uint32_t* out_first_set_index)
{
#if defined(_MSC_VER)
    return _BitScanForward(reinterpret_cast<unsigned long*>(out_first_set_index), value) != 0;
#else
    int index = __builtin_ffs(value);
    *out_first_set_index = index - 1;
    return index != 0;
#endif
}

int lzx_decompress(const void* lzx_data, size_t lzx_length, void* dst, size_t dst_length, uint32_t window_size)
{
    uint32_t window_bits = 0;
    if (!bit_scan_forward(window_size, &window_bits)) return 1;

    int result_code = 1;
    mspack_system* sys = mspack_memory_sys_create();
    mspack_memory_file* lzx_src = sys ? mspack_memory_open(sys, const_cast<void*>(lzx_data), lzx_length) : nullptr;
    mspack_memory_file* lzx_dst = sys ? mspack_memory_open(sys, dst, dst_length) : nullptr;
    lzxd_stream* lzxd = (sys && lzx_src && lzx_dst)
        ? lzxd_init(sys, reinterpret_cast<mspack_file*>(lzx_src), reinterpret_cast<mspack_file*>(lzx_dst), window_bits, 0, 0x8000, dst_length, 0)
        : nullptr;

    if (lzxd) {
        result_code = lzxd_decompress(lzxd, dst_length);
        lzxd_free(lzxd);
    }

    if (lzx_src) mspack_memory_close(lzx_src);
    if (lzx_dst) mspack_memory_close(lzx_dst);
    if (sys) mspack_memory_sys_destroy(sys);
    return result_code;
}

uint16_t read_be16(const uint8_t* p)
{
    return (uint16_t(p[0]) << 8) | uint16_t(p[1]);
}

uint32_t read_be32(const uint8_t* p)
{
    return (uint32_t(p[0]) << 24) | (uint32_t(p[1]) << 16) | (uint32_t(p[2]) << 8) | uint32_t(p[3]);
}

std::string hex32(uint32_t value)
{
    std::ostringstream out;
    out << "0x" << std::uppercase << std::hex << std::setw(8) << std::setfill('0') << value;
    return out.str();
}

const uint8_t* get_opt_header_ptr(const std::vector<uint8_t>& module, uint32_t header_key)
{
    if (module.size() < 24) return nullptr;

    const uint32_t header_count = read_be32(module.data() + 20);
    const size_t opt_table = 24;
    const size_t opt_table_size = size_t(header_count) * 8;
    if (module.size() < opt_table + opt_table_size) return nullptr;

    for (uint32_t i = 0; i < header_count; ++i) {
        const uint8_t* opt = module.data() + opt_table + (size_t(i) * 8);
        const uint32_t key = read_be32(opt);
        if (key != header_key) continue;

        if ((header_key & 0xFF) == 0 || (header_key & 0xFF) == 1) {
            return opt + 4;
        }

        const uint32_t offset = read_be32(opt + 4);
        if (offset >= module.size()) return nullptr;
        return module.data() + offset;
    }

    return nullptr;
}

struct GuestMemory {
    uint8_t* base = nullptr;
    size_t size = 0;

    ~GuestMemory()
    {
#if defined(_WIN32)
        if (base) VirtualFree(base, 0, MEM_RELEASE);
#endif
    }

    bool reserve(size_t bytes)
    {
#if defined(_WIN32)
        base = static_cast<uint8_t*>(VirtualAlloc(nullptr, bytes, MEM_RESERVE, PAGE_READWRITE));
        size = base ? bytes : 0;
        return base != nullptr;
#else
        (void)bytes;
        return false;
#endif
    }

    bool commit(uint32_t address, uint32_t bytes)
    {
        if (!base || uint64_t(address) + bytes > size) return false;

#if defined(_WIN32)
        constexpr size_t page_size = 0x1000;
        const uintptr_t begin = reinterpret_cast<uintptr_t>(base + address) & ~(page_size - 1);
        const uintptr_t end = (reinterpret_cast<uintptr_t>(base + address + bytes) + page_size - 1) & ~(page_size - 1);
        return VirtualAlloc(reinterpret_cast<void*>(begin), end - begin, MEM_COMMIT, PAGE_READWRITE) != nullptr;
#else
        return false;
#endif
    }
};

bool load_uncompressed_image(const std::vector<uint8_t>& xex, uint32_t header_size, uint32_t image_base,
    uint32_t image_size, GuestMemory& memory, std::string& error)
{
    if (header_size > xex.size()) {
        error = "XEX header size is larger than the file.";
        return false;
    }

    const size_t image_bytes_available = xex.size() - header_size;
    if (image_bytes_available < image_size) {
        error = "XEX image data is smaller than the declared image size.";
        return false;
    }

    if (!memory.commit(image_base, image_size)) {
        error = "Failed to commit guest memory for the XEX image.";
        return false;
    }

    std::memcpy(memory.base + image_base, xex.data() + header_size, image_size);
    return true;
}

bool load_basic_image(const std::vector<uint8_t>& xex, const uint8_t* file_format, uint32_t header_size,
    uint32_t image_base, uint32_t image_size, GuestMemory& memory, std::string& error)
{
    const uint32_t info_size = read_be32(file_format);
    if (info_size < 16) {
        error = "Basic-compression file-format info is too small.";
        return false;
    }

    const size_t block_count = (info_size / 8) - 1;
    const uint8_t* blocks = file_format + 8;
    const uint8_t* src = xex.data() + header_size;

    if (!memory.commit(image_base, image_size)) {
        error = "Failed to commit guest memory for the XEX image.";
        return false;
    }

    uint8_t* dest = memory.base + image_base;
    uint32_t written = 0;

    for (size_t i = 0; i < block_count; ++i) {
        const uint32_t data_size = read_be32(blocks + i * 8);
        const uint32_t zero_size = read_be32(blocks + i * 8 + 4);
        const uint64_t next_written = uint64_t(written) + data_size + zero_size;

        if (next_written > image_size || src + data_size > xex.data() + xex.size()) {
            error = "Basic-compressed XEX image block exceeds the available data.";
            return false;
        }

        std::memcpy(dest + written, src, data_size);
        written += data_size;
        src += data_size;
        std::memset(dest + written, 0, zero_size);
        written += zero_size;
    }

    return true;
}

std::vector<uint8_t> get_decrypted_payload(const std::vector<uint8_t>& xex, const uint8_t* security,
    uint32_t header_size, uint16_t encryption_type, std::string& error)
{
    if (header_size > xex.size()) {
        error = "XEX header size is larger than the file.";
        return {};
    }

    std::vector<uint8_t> payload(xex.begin() + header_size, xex.end());
    if (encryption_type == kXexEncryptionNone) {
        return payload;
    }

    if (encryption_type != 1) {
        error = "Unsupported XEX encryption type.";
        return {};
    }

    if ((payload.size() % 16) != 0) {
        error = "Encrypted XEX payload size is not AES-block aligned.";
        return {};
    }

    constexpr uint32_t key_size = 16;
    uint8_t decrypted_key[key_size]{};
    std::memcpy(decrypted_key, security + 0x150, key_size);

    AES_ctx aes_context;
    AES_init_ctx_iv(&aes_context, kXex2RetailKey, kAesBlankIv);
    AES_CBC_decrypt_buffer(&aes_context, decrypted_key, key_size);

    AES_init_ctx_iv(&aes_context, decrypted_key, kAesBlankIv);
    AES_CBC_decrypt_buffer(&aes_context, payload.data(), payload.size());
    return payload;
}

bool load_normal_image(const std::vector<uint8_t>& payload, const uint8_t* file_format,
    uint32_t image_base, uint32_t image_size, GuestMemory& memory, std::string& error)
{
    const uint32_t window_size = read_be32(file_format + 8);
    const uint8_t* block_ptr = file_format + 12;
    const uint8_t* payload_ptr = payload.data();
    const uint8_t* payload_end = payload.data() + payload.size();

    std::vector<uint8_t> compressed;
    sha1::SHA1 sha;

    while (read_be32(block_ptr) != 0) {
        const uint32_t block_size = read_be32(block_ptr);
        if (payload_ptr + block_size > payload_end || block_size < 24) {
            error = "Normal-compressed XEX block exceeds the encrypted payload.";
            return false;
        }

        const uint8_t* next_block = payload_ptr;
        sha.reset();
        sha.processBytes(payload_ptr, block_size);
        uint8_t digest[0x14]{};
        sha.finalize(digest);
        if (std::memcmp(digest, block_ptr + 4, sizeof(digest)) != 0) {
            error = "Normal-compressed XEX block hash mismatch.";
            return false;
        }

        payload_ptr += 24;
        while (true) {
            if (payload_ptr + 2 > payload_end) {
                error = "Normal-compressed XEX chunk table is truncated.";
                return false;
            }

            const size_t chunk_size = (size_t(payload_ptr[0]) << 8) | payload_ptr[1];
            payload_ptr += 2;
            if (chunk_size == 0) break;

            if (payload_ptr + chunk_size > payload_end) {
                error = "Normal-compressed XEX chunk exceeds the encrypted payload.";
                return false;
            }

            compressed.insert(compressed.end(), payload_ptr, payload_ptr + chunk_size);
            payload_ptr += chunk_size;
        }

        payload_ptr = next_block + block_size;
        block_ptr = next_block;
    }

    if (!memory.commit(image_base, image_size)) {
        error = "Failed to commit guest memory for the XEX image.";
        return false;
    }

    int result = lzx_decompress(compressed.data(), compressed.size(), memory.base + image_base, image_size, window_size);
    if (result != 0) {
        error = "LZX decompression failed with code " + std::to_string(result) + ".";
        return false;
    }

    return true;
}

}

namespace runtime::boot {

BootResult LaunchFromContentRoot(const std::string& content_root)
{
    BootResult result;
    hal::fs::set_game_root(content_root);
    hal::sys::log("[boot] Mounting content root: " + content_root);

    std::vector<uint8_t> xex;
    if (!hal::fs::read_file("game:/default.xex", xex)) {
        result.message = "Failed to read game:/default.xex from " + content_root;
        return result;
    }

    if (xex.size() < 0x120) {
        result.message = "default.xex is too small to be a valid XEX2 image.";
        return result;
    }

    const uint32_t magic = read_be32(xex.data());
    if (magic != 0x58455832) {
        result.message = "default.xex does not have the XEX2 magic.";
        return result;
    }

    const uint32_t header_size = read_be32(xex.data() + 8);
    const uint32_t security_offset = read_be32(xex.data() + 16);
    if (security_offset + 0x114 > xex.size()) {
        result.message = "default.xex security header is outside the file.";
        return result;
    }

    const uint8_t* security = xex.data() + security_offset;
    result.image_size = read_be32(security + 4);
    result.image_base = read_be32(security + 0x110);

    if (const uint8_t* image_base_ptr = get_opt_header_ptr(xex, kXexHeaderImageBaseAddress)) {
        result.image_base = read_be32(image_base_ptr);
    }

    const uint8_t* entry_ptr = get_opt_header_ptr(xex, kXexHeaderEntryPoint);
    if (!entry_ptr) {
        result.message = "default.xex is missing an entry-point optional header.";
        return result;
    }
    result.entry_point = read_be32(entry_ptr);

    const uint8_t* file_format = get_opt_header_ptr(xex, kXexHeaderFileFormatInfo);
    if (!file_format || file_format + 8 > xex.data() + xex.size()) {
        result.message = "default.xex is missing file-format info.";
        return result;
    }
    result.encryption_type = read_be16(file_format + 4);
    result.compression_type = read_be16(file_format + 6);

    GuestMemory guest;
    if (!guest.reserve(size_t(kGuestMemorySize))) {
        result.message = "Failed to reserve the 4 GB guest address space required by generated PPC code.";
        return result;
    }

    std::string load_error;
    bool loaded = false;
    std::vector<uint8_t> payload = get_decrypted_payload(xex, security, header_size, result.encryption_type, load_error);
    if (!payload.empty()) {
        if (result.compression_type == kXexCompressionNone) {
            std::vector<uint8_t> decrypted_xex = xex;
            decrypted_xex.resize(header_size);
            decrypted_xex.insert(decrypted_xex.end(), payload.begin(), payload.end());
            loaded = load_uncompressed_image(decrypted_xex, header_size, result.image_base, result.image_size, guest, load_error);
        } else if (result.compression_type == kXexCompressionBasic) {
            std::vector<uint8_t> decrypted_xex = xex;
            decrypted_xex.resize(header_size);
            decrypted_xex.insert(decrypted_xex.end(), payload.begin(), payload.end());
            loaded = load_basic_image(decrypted_xex, file_format, header_size, result.image_base, result.image_size, guest, load_error);
        } else if (result.compression_type == kXexCompressionNormal) {
            loaded = load_normal_image(payload, file_format, result.image_base, result.image_size, guest, load_error);
        } else {
            load_error = "Delta-compressed XEX images need delta decompression wired into the runtime.";
        }
    } else {
        if (load_error.empty()) load_error = "Failed to decrypt XEX payload.";
    }

    std::ostringstream message;
    message << "default.xex parsed.\n"
        << "Entry: " << hex32(result.entry_point) << "\n"
        << "Image base: " << hex32(result.image_base) << "\n"
        << "Image size: " << result.image_size << " bytes\n"
        << "Encryption: " << result.encryption_type << ", compression: " << result.compression_type;

    if (!loaded) {
        message << "\n\nBoot stopped before guest entry: " << load_error;
        result.message = message.str();
        result.ok = true;
        result.ready_to_enter_guest = false;
        return result;
    }

    message << "\n\nXEX image loaded into guest memory. Next step is linking generated PPC code and starting a guest thread at "
        << hex32(result.entry_point) << ".";

    uint32_t function_table_start = 0;
    uint32_t function_table_size = 0;
    if (GetGeneratedFunctionTableRange(function_table_start, function_table_size)) {
        constexpr uint32_t stack_base = 0x70000000;
        constexpr uint32_t stack_size = 0x00100000;
        constexpr uint32_t stack_top = stack_base + stack_size - 0x100;

        if (!guest.commit(function_table_start, function_table_size)) {
            message << "\n\nGenerated PPC is linked, but the runtime could not commit the function lookup table.";
        } else if (!guest.commit(stack_base, stack_size)) {
            message << "\n\nGenerated PPC is linked, but the runtime could not commit the initial guest stack.";
        } else {
            RecompEntryResult entry_result = TryEnterGeneratedGuest(result.entry_point, guest.base, stack_top);
            message << "\n\n" << entry_result.message;
        }
    } else {
        RecompEntryResult entry_result = TryEnterGeneratedGuest(result.entry_point, guest.base, 0);
        message << "\n\n" << entry_result.message;
    }

    result.message = message.str();
    result.ok = true;
    result.ready_to_enter_guest = true;
    return result;
}

}
