#include "game_boot.h"

#include "../hal/fs.h"
#include "../hal/sys.h"

#include <cstring>
#include <iomanip>
#include <sstream>
#include <vector>

#if defined(_WIN32)
#include <windows.h>
#endif

namespace {

constexpr uint32_t kXexHeaderEntryPoint = 0x00010100;
constexpr uint32_t kXexHeaderImageBaseAddress = 0x00010201;
constexpr uint32_t kXexHeaderFileFormatInfo = 0x000003FF;
constexpr uint16_t kXexEncryptionNone = 0;
constexpr uint16_t kXexCompressionNone = 0;
constexpr uint16_t kXexCompressionBasic = 1;
constexpr uint64_t kGuestMemorySize = 0x100000000ull;

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
    if (result.encryption_type != kXexEncryptionNone) {
        load_error = "Encrypted XEX images need the XenonRecomp/XEX decrypt path wired into the runtime.";
    } else if (result.compression_type == kXexCompressionNone) {
        loaded = load_uncompressed_image(xex, header_size, result.image_base, result.image_size, guest, load_error);
    } else if (result.compression_type == kXexCompressionBasic) {
        loaded = load_basic_image(xex, file_format, header_size, result.image_base, result.image_size, guest, load_error);
    } else {
        load_error = "Normal/delta-compressed XEX images need LZX/delta decompression wired into the runtime.";
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

    result.message = message.str();
    result.ok = true;
    result.ready_to_enter_guest = true;
    return result;
}

}
