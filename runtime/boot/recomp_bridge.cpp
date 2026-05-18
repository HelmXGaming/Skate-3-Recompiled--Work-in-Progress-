#include "recomp_bridge.h"

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
};

GuestException g_last_guest_exception;

int CaptureGuestException(EXCEPTION_POINTERS* exception)
{
    g_last_guest_exception.code = exception->ExceptionRecord->ExceptionCode;
    g_last_guest_exception.address = exception->ExceptionRecord->ExceptionAddress;
    return EXCEPTION_EXECUTE_HANDLER;
}

bool CallGeneratedEntry(PPCFunc* entry, PPCContext& ctx, uint8_t* guest_base)
{
    g_last_guest_exception = {};

    __try {
        entry(ctx, guest_base);
        return true;
    } __except (CaptureGuestException(GetExceptionInformation())) {
        return false;
    }
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
            << "Host address: " << g_last_guest_exception.address << "\n"
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
