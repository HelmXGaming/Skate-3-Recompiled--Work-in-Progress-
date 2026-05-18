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
    uint32_t r3 = 0;
    uint32_t r4 = 0;
    uint32_t r5 = 0;
    uint32_t r27 = 0;
    uint32_t r28 = 0;
    uint32_t r29 = 0;
    uint32_t r30 = 0;
    uint32_t r31 = 0;
    uint64_t guest_memory_address = 0;
    uint32_t guest_memory_size = 0;
    bool guest_memory_write = false;
    bool has_guest_memory_access = false;
};

GuestException g_last_guest_exception;
PPCContext* g_exception_context = nullptr;
const char* g_last_import_stub = "none";
uint32_t g_next_virtual_alloc = 0x00100000;
uint64_t g_last_guest_memory_address = 0;
uint32_t g_last_guest_memory_size = 0;
bool g_last_guest_memory_write = false;
bool g_has_last_guest_memory_access = false;

} // namespace

extern "C" void Skate3RecordImportStub(const char* name)
{
    g_last_import_stub = name;
}

uint32_t ReadGuestU32(uint8_t* base, uint32_t address)
{
    return __builtin_bswap32(*reinterpret_cast<volatile uint32_t*>(base + address));
}

void WriteGuestU32(uint8_t* base, uint32_t address, uint32_t value)
{
    *reinterpret_cast<volatile uint32_t*>(base + address) = __builtin_bswap32(value);
}

int32_t ReadGuestS32(uint8_t* base, uint32_t address)
{
    return static_cast<int32_t>(ReadGuestU32(base, address));
}

uint32_t AlignUp(uint32_t value, uint32_t alignment)
{
    return (value + alignment - 1) & ~(alignment - 1);
}

void RecordGuestMemoryAccess(uint64_t address, uint32_t size, bool write)
{
    g_last_guest_memory_address = address;
    g_last_guest_memory_size = size;
    g_last_guest_memory_write = write;
    g_has_last_guest_memory_access = true;
}

void RaiseGuestMemoryFault(uint64_t address, bool write)
{
    ULONG_PTR details[2] = { write ? 1ull : 0ull, static_cast<ULONG_PTR>(address) };
    RaiseException(EXCEPTION_ACCESS_VIOLATION, 0, 2, details);
}

void CheckGuestMemoryAccess(uint64_t address, uint32_t size, bool write)
{
    RecordGuestMemoryAccess(address, size, write);
    if (address + size < address || address + size > 0x100000000ull) {
        RaiseGuestMemoryFault(address, write);
    }
}

uint8_t Skate3PpcLoadU8(uint8_t* base, uint64_t address)
{
    CheckGuestMemoryAccess(address, 1, false);
    return *reinterpret_cast<volatile uint8_t*>(base + address);
}

uint16_t Skate3PpcLoadU16(uint8_t* base, uint64_t address)
{
    CheckGuestMemoryAccess(address, 2, false);
    return __builtin_bswap16(*reinterpret_cast<volatile uint16_t*>(base + address));
}

uint32_t Skate3PpcLoadU32(uint8_t* base, uint64_t address)
{
    CheckGuestMemoryAccess(address, 4, false);
    return __builtin_bswap32(*reinterpret_cast<volatile uint32_t*>(base + address));
}

uint64_t Skate3PpcLoadU64(uint8_t* base, uint64_t address)
{
    CheckGuestMemoryAccess(address, 8, false);
    return __builtin_bswap64(*reinterpret_cast<volatile uint64_t*>(base + address));
}

void Skate3PpcStoreU8(uint8_t* base, uint64_t address, uint8_t value)
{
    CheckGuestMemoryAccess(address, 1, true);
    *reinterpret_cast<volatile uint8_t*>(base + address) = value;
}

void Skate3PpcStoreU16(uint8_t* base, uint64_t address, uint16_t value)
{
    CheckGuestMemoryAccess(address, 2, true);
    *reinterpret_cast<volatile uint16_t*>(base + address) = __builtin_bswap16(value);
}

void Skate3PpcStoreU32(uint8_t* base, uint64_t address, uint32_t value)
{
    CheckGuestMemoryAccess(address, 4, true);
    *reinterpret_cast<volatile uint32_t*>(base + address) = __builtin_bswap32(value);
}

void Skate3PpcStoreU64(uint8_t* base, uint64_t address, uint64_t value)
{
    CheckGuestMemoryAccess(address, 8, true);
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

void Skate3ImportRtlInitializeCriticalSection(PPCContext& ctx, uint8_t* base)
{
    const uint32_t cs = ctx.r3.u32;
    if (cs == 0) {
        ctx.r3.u64 = 0xC000000D;
        return;
    }

    // Xbox critical sections begin with a 16-byte dispatch header, followed by
    // LockCount, RecursionCount, and OwningThread.
    WriteGuestU32(base, cs + 0, 0);
    WriteGuestU32(base, cs + 4, 0);
    WriteGuestU32(base, cs + 8, 0);
    WriteGuestU32(base, cs + 12, 0);
    WriteGuestU32(base, cs + 16, 0xFFFFFFFF);
    WriteGuestU32(base, cs + 20, 0);
    WriteGuestU32(base, cs + 24, 0);
    ctx.r3.u64 = 0;
}

void Skate3ImportRtlEnterCriticalSection(PPCContext& ctx, uint8_t* base)
{
    const uint32_t cs = ctx.r3.u32;
    if (cs == 0) {
        return;
    }

    const uint32_t thread_id = ctx.r13.u32 != 0 ? ctx.r13.u32 : 1;
    const uint32_t recursion = ReadGuestU32(base, cs + 20);
    WriteGuestU32(base, cs + 16, 0);
    WriteGuestU32(base, cs + 20, recursion + 1);
    WriteGuestU32(base, cs + 24, thread_id);
}

void Skate3ImportRtlLeaveCriticalSection(PPCContext& ctx, uint8_t* base)
{
    const uint32_t cs = ctx.r3.u32;
    if (cs == 0) {
        return;
    }

    const int32_t recursion = ReadGuestS32(base, cs + 20);
    if (recursion <= 1) {
        WriteGuestU32(base, cs + 16, 0xFFFFFFFF);
        WriteGuestU32(base, cs + 20, 0);
        WriteGuestU32(base, cs + 24, 0);
    } else {
        WriteGuestU32(base, cs + 20, static_cast<uint32_t>(recursion - 1));
    }
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
        g_last_guest_exception.r3 = g_exception_context->r3.u32;
        g_last_guest_exception.r4 = g_exception_context->r4.u32;
        g_last_guest_exception.r5 = g_exception_context->r5.u32;
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
    return EXCEPTION_EXECUTE_HANDLER;
}

bool CallGeneratedEntry(PPCFunc* entry, PPCContext& ctx, uint8_t* guest_base)
{
    g_last_guest_exception = {};
    g_has_last_guest_memory_access = false;
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
        << "r3/r4/r5: 0x" << std::setw(8) << g_last_guest_exception.r3
        << " 0x" << std::setw(8) << g_last_guest_exception.r4
        << " 0x" << std::setw(8) << g_last_guest_exception.r5 << "\n"
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
}

void AppendImportSnapshot(std::ostringstream& message)
{
    message << "Last import stub: " << g_last_import_stub << "\n";
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
