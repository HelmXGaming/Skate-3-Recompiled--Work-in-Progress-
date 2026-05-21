#include "recomp_bridge.h"

#include <algorithm>
#include <iomanip>
#include <sstream>

#if defined(SKATE3_HAS_RECOMP_LIB)
#include <windows.h>

#include "skate3_recomp_msvc_compat.h"
#include "ppc_recomp_shared.h"
#endif

namespace runtime::boot {

#if defined(SKATE3_HAS_RECOMP_LIB)
namespace {

struct GuestException {
    uint32_t code = 0;
    void* address = nullptr;
    uintptr_t access_address = 0;
    uintptr_t access_kind = 0;
    bool has_access_details = false;
    uint32_t lr = 0;
    uint32_t ctr = 0;
    uint32_t r1 = 0;
    uint32_t r3 = 0;
    uint32_t r4 = 0;
    uint32_t r5 = 0;
    uint32_t r6 = 0;
    uint32_t r7 = 0;
    uint32_t r8 = 0;
    uint32_t r9 = 0;
    uint32_t r10 = 0;
    uint32_t r11 = 0;
    uint32_t r12 = 0;
    uint32_t r27 = 0;
    uint32_t r28 = 0;
    uint32_t r29 = 0;
    uint32_t r30 = 0;
    uint32_t r31 = 0;
    uint64_t guest_memory_address = 0;
    uint32_t guest_memory_size = 0;
    bool guest_memory_write = false;
    bool has_guest_memory_access = false;
    const char* guest_memory_source_file = nullptr;
    int guest_memory_source_line = 0;
    uint32_t memory_r3 = 0;
    uint32_t memory_r4 = 0;
    uint32_t memory_r5 = 0;
    uint32_t memory_r6 = 0;
    uint32_t memory_r7 = 0;
    uint32_t memory_r8 = 0;
    uint32_t memory_r9 = 0;
    uint32_t memory_r10 = 0;
    uint32_t memory_r11 = 0;
    uint32_t memory_r12 = 0;
    const char* last_import_stub = "none";
    uint32_t import_r3 = 0;
    uint32_t import_r4 = 0;
    uint32_t import_r5 = 0;
    uint32_t import_r6 = 0;
    uint32_t import_r7 = 0;
};

GuestException g_last_guest_exception;
PPCContext* g_exception_context = nullptr;
const char* g_last_import_stub = "none";
uint32_t g_last_import_r3 = 0;
uint32_t g_last_import_r4 = 0;
uint32_t g_last_import_r5 = 0;
uint32_t g_last_import_r6 = 0;
uint32_t g_last_import_r7 = 0;
uint32_t g_next_virtual_alloc = 0x00100000;
uint64_t g_last_guest_memory_address = 0;
uint32_t g_last_guest_memory_size = 0;
bool g_last_guest_memory_write = false;
bool g_has_last_guest_memory_access = false;
const char* g_last_guest_memory_source_file = nullptr;
int g_last_guest_memory_source_line = 0;
uint32_t g_last_memory_r3 = 0;
uint32_t g_last_memory_r4 = 0;
uint32_t g_last_memory_r5 = 0;
uint32_t g_last_memory_r6 = 0;
uint32_t g_last_memory_r7 = 0;
uint32_t g_last_memory_r8 = 0;
uint32_t g_last_memory_r9 = 0;
uint32_t g_last_memory_r10 = 0;
uint32_t g_last_memory_r11 = 0;
uint32_t g_last_memory_r12 = 0;

} // namespace

extern "C" void Skate3RecordImportStub(const char* name)
{
    g_last_import_stub = name;
    if (g_exception_context != nullptr) {
        g_last_import_r3 = g_exception_context->r3.u32;
        g_last_import_r4 = g_exception_context->r4.u32;
        g_last_import_r5 = g_exception_context->r5.u32;
        g_last_import_r6 = g_exception_context->r6.u32;
        g_last_import_r7 = g_exception_context->r7.u32;
    }
}

uint32_t ReadGuestU32(uint8_t* base, uint32_t address)
{
    return __builtin_bswap32(*reinterpret_cast<volatile uint32_t*>(base + address));
}

void WriteGuestU32(uint8_t* base, uint32_t address, uint32_t value)
{
    *reinterpret_cast<volatile uint32_t*>(base + address) = __builtin_bswap32(value);
}

void WriteGuestU8(uint8_t* base, uint32_t address, uint8_t value)
{
    *reinterpret_cast<volatile uint8_t*>(base + address) = value;
}

bool GuestRangeFits(uint32_t address, uint32_t size)
{
    return static_cast<uint64_t>(address) + size <= 0x100000000ull;
}

int32_t ReadGuestS32(uint8_t* base, uint32_t address)
{
    return static_cast<int32_t>(ReadGuestU32(base, address));
}

uint32_t AlignUp(uint32_t value, uint32_t alignment)
{
    return (value + alignment - 1) & ~(alignment - 1);
}

void RecordGuestMemoryAccess(
    PPCContext& ctx,
    uint64_t address,
    uint32_t size,
    bool write,
    const char* source_file,
    int source_line)
{
    g_last_guest_memory_address = address;
    g_last_guest_memory_size = size;
    g_last_guest_memory_write = write;
    g_has_last_guest_memory_access = true;
    g_last_guest_memory_source_file = source_file;
    g_last_guest_memory_source_line = source_line;
    g_last_memory_r3 = ctx.r3.u32;
    g_last_memory_r4 = ctx.r4.u32;
    g_last_memory_r5 = ctx.r5.u32;
    g_last_memory_r6 = ctx.r6.u32;
    g_last_memory_r7 = ctx.r7.u32;
    g_last_memory_r8 = ctx.r8.u32;
    g_last_memory_r9 = ctx.r9.u32;
    g_last_memory_r10 = ctx.r10.u32;
    g_last_memory_r11 = ctx.r11.u32;
    g_last_memory_r12 = ctx.r12.u32;
}

void RaiseGuestMemoryFault(uint64_t address, bool write)
{
    ULONG_PTR details[2] = { write ? 1ull : 0ull, static_cast<ULONG_PTR>(address) };
    RaiseException(EXCEPTION_ACCESS_VIOLATION, 0, 2, details);
}

void CheckGuestMemoryAccess(
    PPCContext& ctx,
    uint64_t address,
    uint32_t size,
    bool write,
    const char* source_file,
    int source_line)
{
    RecordGuestMemoryAccess(ctx, address, size, write, source_file, source_line);
    if (address + size < address || address + size > 0x100000000ull) {
        RaiseGuestMemoryFault(address, write);
    }
}

uint8_t Skate3PpcLoadU8(PPCContext& ctx, uint8_t* base, uint64_t address, const char* source_file, int source_line)
{
    CheckGuestMemoryAccess(ctx, address, 1, false, source_file, source_line);
    return *reinterpret_cast<volatile uint8_t*>(base + address);
}

uint16_t Skate3PpcLoadU16(PPCContext& ctx, uint8_t* base, uint64_t address, const char* source_file, int source_line)
{
    CheckGuestMemoryAccess(ctx, address, 2, false, source_file, source_line);
    return __builtin_bswap16(*reinterpret_cast<volatile uint16_t*>(base + address));
}

uint32_t Skate3PpcLoadU32(PPCContext& ctx, uint8_t* base, uint64_t address, const char* source_file, int source_line)
{
    CheckGuestMemoryAccess(ctx, address, 4, false, source_file, source_line);
    return __builtin_bswap32(*reinterpret_cast<volatile uint32_t*>(base + address));
}

uint64_t Skate3PpcLoadU64(PPCContext& ctx, uint8_t* base, uint64_t address, const char* source_file, int source_line)
{
    CheckGuestMemoryAccess(ctx, address, 8, false, source_file, source_line);
    return __builtin_bswap64(*reinterpret_cast<volatile uint64_t*>(base + address));
}

void Skate3PpcStoreU8(PPCContext& ctx, uint8_t* base, uint64_t address, uint8_t value, const char* source_file, int source_line)
{
    CheckGuestMemoryAccess(ctx, address, 1, true, source_file, source_line);
    *reinterpret_cast<volatile uint8_t*>(base + address) = value;
}

void Skate3PpcStoreU16(PPCContext& ctx, uint8_t* base, uint64_t address, uint16_t value, const char* source_file, int source_line)
{
    CheckGuestMemoryAccess(ctx, address, 2, true, source_file, source_line);
    *reinterpret_cast<volatile uint16_t*>(base + address) = __builtin_bswap16(value);
}

void Skate3PpcStoreU32(PPCContext& ctx, uint8_t* base, uint64_t address, uint32_t value, const char* source_file, int source_line)
{
    CheckGuestMemoryAccess(ctx, address, 4, true, source_file, source_line);
    *reinterpret_cast<volatile uint32_t*>(base + address) = __builtin_bswap32(value);
}

void Skate3PpcStoreU64(PPCContext& ctx, uint8_t* base, uint64_t address, uint64_t value, const char* source_file, int source_line)
{
    CheckGuestMemoryAccess(ctx, address, 8, true, source_file, source_line);
    *reinterpret_cast<volatile uint64_t*>(base + address) = __builtin_bswap64(value);
}

void Skate3ImportNtAllocateVirtualMemory(PPCContext& ctx, uint8_t* base)
{
    constexpr uint32_t status_success = 0;
    constexpr uint32_t status_no_memory = 0xC0000017;
    constexpr uint32_t page_size = 0x1000;

    const uint32_t base_address_ptr = ctx.r3.u32;
    const uint32_t region_size_ptr = ctx.r4.u32;
    if (base_address_ptr == 0 || region_size_ptr == 0) {
        ctx.r3.u64 = status_no_memory;
        return;
    }

    uint32_t guest_address = ReadGuestU32(base, base_address_ptr);
    uint32_t region_size = ReadGuestU32(base, region_size_ptr);
    if (region_size == 0) {
        region_size = page_size;
    }

    const uint32_t commit_size = AlignUp(region_size, page_size);
    if (guest_address == 0) {
        guest_address = AlignUp(g_next_virtual_alloc, page_size);
        g_next_virtual_alloc = guest_address + std::max(commit_size, page_size);
    } else {
        guest_address = AlignUp(guest_address, page_size);
    }

    void* committed = VirtualAlloc(base + guest_address, commit_size, MEM_COMMIT, PAGE_READWRITE);
    if (!committed) {
        ctx.r3.u64 = status_no_memory;
        return;
    }

    std::memset(base + guest_address, 0, commit_size);
    WriteGuestU32(base, base_address_ptr, guest_address);
    WriteGuestU32(base, region_size_ptr, commit_size);
    ctx.r3.u64 = status_success;
}

void Skate3ImportNtFreeVirtualMemory(PPCContext& ctx, uint8_t*)
{
    ctx.r3.u64 = 0;
}

void SeedXboxHeapListHeads(uint8_t* base, uint32_t heap)
{
    constexpr uint32_t small_list_start = 384;
    constexpr uint32_t small_list_count = 128;
    constexpr uint32_t small_list_stride = 8;
    constexpr uint32_t small_list_bytes = small_list_count * small_list_stride;

    if (!GuestRangeFits(heap + small_list_start, small_list_bytes)) {
        return;
    }

    if (ReadGuestU32(base, heap + small_list_start) != 0) {
        return;
    }

    for (uint32_t i = 0; i < small_list_count; ++i) {
        const uint32_t list_head = heap + small_list_start + (i * small_list_stride);
        WriteGuestU32(base, list_head + 0, list_head);
        WriteGuestU32(base, list_head + 4, list_head);
    }

    const uint32_t root = heap + 88;
    if (GuestRangeFits(root, 8) && ReadGuestU32(base, root) == 0 && ReadGuestU32(base, root + 4) == 0) {
        WriteGuestU32(base, root + 0, root);
        WriteGuestU32(base, root + 4, root);
    }
}

void Skate3ImportRtlInitializeCriticalSection(PPCContext& ctx, uint8_t* base)
{
    const uint32_t cs = ctx.r3.u32;
    if (cs == 0) {
        ctx.r3.u64 = 0xC000000D;
        return;
    }

    constexpr uint32_t heap_from_critical_section = 0x60;
    if (GuestRangeFits(cs, heap_from_critical_section)) {
        SeedXboxHeapListHeads(base, cs + heap_from_critical_section);
    }

    ctx.r3.u64 = 0;
}

void Skate3ImportRtlEnterCriticalSection(PPCContext& ctx, uint8_t* base)
{
    (void)ctx;
    (void)base;
}

void Skate3ImportRtlLeaveCriticalSection(PPCContext& ctx, uint8_t* base)
{
    (void)ctx;
    (void)base;
}

void Skate3ImportRtlFillMemoryUlong(PPCContext& ctx, uint8_t* base)
{
    const uint32_t destination = ctx.r3.u32;
    const uint32_t length = ctx.r4.u32;
    const uint32_t pattern = ctx.r5.u32;

    for (uint32_t offset = 0; offset + sizeof(uint32_t) <= length; offset += sizeof(uint32_t)) {
        WriteGuestU32(base, destination + offset, pattern);
    }

    const uint32_t remaining = length & 3u;
    const uint32_t tail = length - remaining;
    for (uint32_t i = 0; i < remaining; ++i) {
        const uint32_t shift = 24u - (i * 8u);
        WriteGuestU8(base, destination + tail + i, static_cast<uint8_t>((pattern >> shift) & 0xFFu));
    }
}

void Skate3ImportRtlCompareMemoryUlong(PPCContext& ctx, uint8_t* base)
{
    const uint32_t source = ctx.r3.u32;
    const uint32_t length = ctx.r4.u32;
    const uint32_t pattern = ctx.r5.u32;
    uint32_t matching_bytes = 0;

    for (; matching_bytes + sizeof(uint32_t) <= length; matching_bytes += sizeof(uint32_t)) {
        if (ReadGuestU32(base, source + matching_bytes) != pattern) {
            ctx.r3.u64 = matching_bytes;
            return;
        }
    }

    ctx.r3.u64 = matching_bytes;
}

namespace {

int CaptureGuestException(EXCEPTION_POINTERS* exception)
{
    g_last_guest_exception.code = exception->ExceptionRecord->ExceptionCode;
    g_last_guest_exception.address = exception->ExceptionRecord->ExceptionAddress;
    if (g_last_guest_exception.code == EXCEPTION_ACCESS_VIOLATION &&
        exception->ExceptionRecord->NumberParameters >= 2) {
        g_last_guest_exception.access_kind =
            static_cast<uintptr_t>(exception->ExceptionRecord->ExceptionInformation[0]);
        g_last_guest_exception.access_address =
            static_cast<uintptr_t>(exception->ExceptionRecord->ExceptionInformation[1]);
        g_last_guest_exception.has_access_details = true;
    }
    if (g_exception_context != nullptr) {
        g_last_guest_exception.lr = g_exception_context->lr;
        g_last_guest_exception.ctr = g_exception_context->ctr.u32;
        g_last_guest_exception.r1 = g_exception_context->r1.u32;
        g_last_guest_exception.r3 = g_exception_context->r3.u32;
        g_last_guest_exception.r4 = g_exception_context->r4.u32;
        g_last_guest_exception.r5 = g_exception_context->r5.u32;
        g_last_guest_exception.r6 = g_exception_context->r6.u32;
        g_last_guest_exception.r7 = g_exception_context->r7.u32;
        g_last_guest_exception.r8 = g_exception_context->r8.u32;
        g_last_guest_exception.r9 = g_exception_context->r9.u32;
        g_last_guest_exception.r10 = g_exception_context->r10.u32;
        g_last_guest_exception.r11 = g_exception_context->r11.u32;
        g_last_guest_exception.r12 = g_exception_context->r12.u32;
        g_last_guest_exception.r27 = g_exception_context->r27.u32;
        g_last_guest_exception.r28 = g_exception_context->r28.u32;
        g_last_guest_exception.r29 = g_exception_context->r29.u32;
        g_last_guest_exception.r30 = g_exception_context->r30.u32;
        g_last_guest_exception.r31 = g_exception_context->r31.u32;
    }
    g_last_guest_exception.has_guest_memory_access = g_has_last_guest_memory_access;
    g_last_guest_exception.guest_memory_address = g_last_guest_memory_address;
    g_last_guest_exception.guest_memory_size = g_last_guest_memory_size;
    g_last_guest_exception.guest_memory_write = g_last_guest_memory_write;
    g_last_guest_exception.guest_memory_source_file = g_last_guest_memory_source_file;
    g_last_guest_exception.guest_memory_source_line = g_last_guest_memory_source_line;
    g_last_guest_exception.memory_r3 = g_last_memory_r3;
    g_last_guest_exception.memory_r4 = g_last_memory_r4;
    g_last_guest_exception.memory_r5 = g_last_memory_r5;
    g_last_guest_exception.memory_r6 = g_last_memory_r6;
    g_last_guest_exception.memory_r7 = g_last_memory_r7;
    g_last_guest_exception.memory_r8 = g_last_memory_r8;
    g_last_guest_exception.memory_r9 = g_last_memory_r9;
    g_last_guest_exception.memory_r10 = g_last_memory_r10;
    g_last_guest_exception.memory_r11 = g_last_memory_r11;
    g_last_guest_exception.memory_r12 = g_last_memory_r12;
    g_last_guest_exception.last_import_stub = g_last_import_stub;
    g_last_guest_exception.import_r3 = g_last_import_r3;
    g_last_guest_exception.import_r4 = g_last_import_r4;
    g_last_guest_exception.import_r5 = g_last_import_r5;
    g_last_guest_exception.import_r6 = g_last_import_r6;
    g_last_guest_exception.import_r7 = g_last_import_r7;
    return EXCEPTION_EXECUTE_HANDLER;
}

bool CallGeneratedEntry(PPCFunc* entry, PPCContext& ctx, uint8_t* guest_base)
{
    g_last_guest_exception = {};
    g_has_last_guest_memory_access = false;
    g_last_guest_memory_source_file = nullptr;
    g_last_guest_memory_source_line = 0;
    g_exception_context = &ctx;

    __try {
        entry(ctx, guest_base);
        g_exception_context = nullptr;
        return true;
    } __except (CaptureGuestException(GetExceptionInformation())) {
        g_exception_context = nullptr;
        return false;
    }
}

void AppendNearestGeneratedFunction(std::ostringstream& message, void* host_address)
{
    const auto target = reinterpret_cast<uintptr_t>(host_address);
    uint32_t nearest_guest = 0;
    uintptr_t nearest_host = 0;

    for (size_t i = 0; PPCFuncMappings[i].guest != 0; ++i) {
        const auto host = reinterpret_cast<uintptr_t>(PPCFuncMappings[i].host);
        if (host != 0 && host <= target && host >= nearest_host) {
            nearest_host = host;
            nearest_guest = PPCFuncMappings[i].guest;
        }
    }

    if (nearest_guest == 0) {
        message << "Generated function: unknown\n";
        return;
    }

    message << "Generated function: 0x" << std::hex << std::uppercase
        << std::setw(8) << std::setfill('0') << nearest_guest
        << " + 0x" << (target - nearest_host) << "\n";
}

void AppendGuestAddressFunction(std::ostringstream& message, const char* label, uint32_t guest_address)
{
    uint32_t nearest_guest = 0;

    for (size_t i = 0; PPCFuncMappings[i].guest != 0; ++i) {
        if (PPCFuncMappings[i].guest <= guest_address && PPCFuncMappings[i].guest >= nearest_guest) {
            nearest_guest = PPCFuncMappings[i].guest;
        }
    }

    if (nearest_guest == 0) {
        return;
    }

    message << label << " function: 0x" << std::hex << std::uppercase
        << std::setw(8) << std::setfill('0') << nearest_guest
        << " + 0x" << (guest_address - nearest_guest) << "\n";
}

void AppendAccessViolationDetails(std::ostringstream& message, uint8_t* guest_base)
{
    if (!g_last_guest_exception.has_access_details) {
        return;
    }

    const char* access = "access";
    if (g_last_guest_exception.access_kind == 0) {
        access = "read";
    } else if (g_last_guest_exception.access_kind == 1) {
        access = "write";
    } else if (g_last_guest_exception.access_kind == 8) {
        access = "execute";
    }

    message << "Access: " << access << " at 0x" << std::hex << std::uppercase
        << g_last_guest_exception.access_address << "\n";

    const auto guest_start = reinterpret_cast<uintptr_t>(guest_base);
    const auto guest_end = guest_start + 0x100000000ull;
    if (g_last_guest_exception.access_address >= guest_start &&
        g_last_guest_exception.access_address < guest_end) {
        message << "Guest VA: 0x" << std::setw(8) << std::setfill('0')
            << (g_last_guest_exception.access_address - guest_start) << "\n";
    }
}

void AppendRegisterSnapshot(std::ostringstream& message)
{
    message << "LR: 0x" << std::hex << std::uppercase << std::setw(8) << std::setfill('0')
        << g_last_guest_exception.lr << "\n"
        << "r1/ctr: 0x" << std::setw(8) << g_last_guest_exception.r1
        << " 0x" << std::setw(8) << g_last_guest_exception.ctr << "\n"
        << "r3/r4/r5: 0x" << std::setw(8) << g_last_guest_exception.r3
        << " 0x" << std::setw(8) << g_last_guest_exception.r4
        << " 0x" << std::setw(8) << g_last_guest_exception.r5 << "\n"
        << "r6/r7/r8: 0x" << std::setw(8) << g_last_guest_exception.r6
        << " 0x" << std::setw(8) << g_last_guest_exception.r7
        << " 0x" << std::setw(8) << g_last_guest_exception.r8 << "\n"
        << "r9-r12: 0x" << std::setw(8) << g_last_guest_exception.r9
        << " 0x" << std::setw(8) << g_last_guest_exception.r10
        << " 0x" << std::setw(8) << g_last_guest_exception.r11
        << " 0x" << std::setw(8) << g_last_guest_exception.r12 << "\n"
        << "r27-r31: 0x" << std::setw(8) << g_last_guest_exception.r27
        << " 0x" << std::setw(8) << g_last_guest_exception.r28
        << " 0x" << std::setw(8) << g_last_guest_exception.r29
        << " 0x" << std::setw(8) << g_last_guest_exception.r30
        << " 0x" << std::setw(8) << g_last_guest_exception.r31 << "\n";
}

void AppendGuestMemorySnapshot(std::ostringstream& message)
{
    if (!g_last_guest_exception.has_guest_memory_access) {
        return;
    }

    message << "Generated memory: "
        << (g_last_guest_exception.guest_memory_write ? "write" : "read")
        << " " << std::dec << g_last_guest_exception.guest_memory_size
        << " byte(s) at guest 0x" << std::hex << std::uppercase
        << g_last_guest_exception.guest_memory_address << "\n";

    if (g_last_guest_exception.guest_memory_source_file != nullptr) {
        const char* source_name = g_last_guest_exception.guest_memory_source_file;
        for (const char* current = source_name; *current != '\0'; ++current) {
            if (*current == '\\' || *current == '/') {
                source_name = current + 1;
            }
        }

        message << "Memory source: " << source_name
            << ":" << std::dec << g_last_guest_exception.guest_memory_source_line << "\n";
    }

    message << std::hex << std::uppercase
        << "Memory r3-r7: 0x" << std::setw(8) << std::setfill('0') << g_last_guest_exception.memory_r3
        << " 0x" << std::setw(8) << g_last_guest_exception.memory_r4
        << " 0x" << std::setw(8) << g_last_guest_exception.memory_r5
        << " 0x" << std::setw(8) << g_last_guest_exception.memory_r6
        << " 0x" << std::setw(8) << g_last_guest_exception.memory_r7 << "\n"
        << "Memory r8-r12: 0x" << std::setw(8) << g_last_guest_exception.memory_r8
        << " 0x" << std::setw(8) << g_last_guest_exception.memory_r9
        << " 0x" << std::setw(8) << g_last_guest_exception.memory_r10
        << " 0x" << std::setw(8) << g_last_guest_exception.memory_r11
        << " 0x" << std::setw(8) << g_last_guest_exception.memory_r12 << "\n";
}

void AppendImportSnapshot(std::ostringstream& message)
{
    message << "Last import stub: " << g_last_guest_exception.last_import_stub << "\n"
        << "Import r3-r7: 0x" << std::hex << std::uppercase << std::setw(8) << std::setfill('0')
        << g_last_guest_exception.import_r3
        << " 0x" << std::setw(8) << g_last_guest_exception.import_r4
        << " 0x" << std::setw(8) << g_last_guest_exception.import_r5
        << " 0x" << std::setw(8) << g_last_guest_exception.import_r6
        << " 0x" << std::setw(8) << g_last_guest_exception.import_r7 << "\n";
}

} // namespace
#endif

bool GetGeneratedFunctionTableRange(uint32_t& start, uint32_t& size)
{
#if defined(SKATE3_HAS_RECOMP_LIB)
    start = uint32_t(PPC_IMAGE_BASE + PPC_IMAGE_SIZE);
    size = uint32_t(PPC_CODE_SIZE * 2);
    return true;
#else
    start = 0;
    size = 0;
    return false;
#endif
}

RecompEntryResult TryEnterGeneratedGuest(uint32_t entry_point, uint8_t* guest_base, uint32_t stack_top)
{
    RecompEntryResult result;

#if defined(SKATE3_HAS_RECOMP_LIB)
    result.available = true;
    g_last_import_stub = "none";
    g_last_import_r3 = 0;
    g_last_import_r4 = 0;
    g_last_import_r5 = 0;
    g_last_import_r6 = 0;
    g_last_import_r7 = 0;
    g_next_virtual_alloc = 0x00100000;

    for (size_t i = 0; PPCFuncMappings[i].guest != 0; ++i) {
        if (PPCFuncMappings[i].host != nullptr) {
            PPC_LOOKUP_FUNC(guest_base, PPCFuncMappings[i].guest) = PPCFuncMappings[i].host;
        }
    }

    PPCFunc* entry = PPC_LOOKUP_FUNC(guest_base, entry_point);
    if (!entry) {
        std::ostringstream message;
        message << "Generated PPC function mapping does not contain entry 0x"
            << std::hex << std::uppercase << entry_point << ".";
        result.message = message.str();
        return result;
    }

    PPCContext ctx{};
    ctx.r1.u64 = stack_top;
    ctx.r13.u64 = 0;
    ctx.fpscr.loadFromHost();

    result.attempted = true;
    if (CallGeneratedEntry(entry, ctx, guest_base)) {
        result.returned = true;
        result.message = "Generated PPC entry returned to the host.";
    } else {
        std::ostringstream message;
        message << "Generated PPC entry raised a host exception before returning.\n"
            << "Exception: 0x" << std::hex << std::uppercase << std::setw(8) << std::setfill('0')
            << g_last_guest_exception.code << "\n"
            << "Host address: " << g_last_guest_exception.address << "\n";
        AppendNearestGeneratedFunction(message, g_last_guest_exception.address);
        AppendAccessViolationDetails(message, guest_base);
        AppendGuestAddressFunction(message, "LR", g_last_guest_exception.lr);
        AppendRegisterSnapshot(message);
        AppendGuestMemorySnapshot(message);
        AppendImportSnapshot(message);
        message
            << "This is expected at this stage; the next step is wiring the first missing guest runtime service.";
        result.message = message.str();
    }
    return result;
#else
    result.message = "Generated PPC code is not linked. Configure with SKATE3_ENABLE_RECOMP_LIB=ON after running tools/run_recomp.bat.";
    return result;
#endif
}

}
