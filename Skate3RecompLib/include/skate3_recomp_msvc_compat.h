#pragma once

#if defined(_MSC_VER) && !defined(__clang__)

#include <cmath>
#include <cstdint>
#include <intrin.h>

struct PPCContext;

namespace runtime::boot {
uint8_t Skate3PpcLoadU8(PPCContext& ctx, uint8_t* base, uint64_t address);
uint16_t Skate3PpcLoadU16(PPCContext& ctx, uint8_t* base, uint64_t address);
uint32_t Skate3PpcLoadU32(PPCContext& ctx, uint8_t* base, uint64_t address);
uint64_t Skate3PpcLoadU64(PPCContext& ctx, uint8_t* base, uint64_t address);
void Skate3PpcStoreU8(PPCContext& ctx, uint8_t* base, uint64_t address, uint8_t value);
void Skate3PpcStoreU16(PPCContext& ctx, uint8_t* base, uint64_t address, uint16_t value);
void Skate3PpcStoreU32(PPCContext& ctx, uint8_t* base, uint64_t address, uint32_t value);
void Skate3PpcStoreU64(PPCContext& ctx, uint8_t* base, uint64_t address, uint64_t value);
}

#define __restrict__
#define __attribute__(x)
#define __builtin_assume(x) __assume(x)
#define __builtin_bswap16(x) _byteswap_ushort(static_cast<unsigned short>(x))
#define __builtin_bswap32(x) _byteswap_ulong(static_cast<unsigned long>(x))
#define __builtin_bswap64(x) _byteswap_uint64(static_cast<unsigned long long>(x))
#define __builtin_debugtrap() __debugbreak()
#define __builtin_isnan std::isnan
#define __builtin_rotateleft32(x, y) _rotl(static_cast<unsigned int>(x), static_cast<int>(y))
#define __builtin_rotateleft64(x, y) _rotl64(static_cast<unsigned long long>(x), static_cast<int>(y))

inline int skate3_recomp_clz32(uint32_t value)
{
    unsigned long index = 0;
    return _BitScanReverse(&index, value) ? 31 - static_cast<int>(index) : 32;
}

inline int skate3_recomp_clz64(uint64_t value)
{
    unsigned long index = 0;
    return _BitScanReverse64(&index, value) ? 63 - static_cast<int>(index) : 64;
}

#define __builtin_clz(x) skate3_recomp_clz32(static_cast<uint32_t>(x))
#define __builtin_clzll(x) skate3_recomp_clz64(static_cast<uint64_t>(x))

inline bool skate3_recomp_sync_bool_compare_and_swap(uint32_t* ptr, int32_t expected, uint32_t desired)
{
    const long previous = _InterlockedCompareExchange(
        reinterpret_cast<volatile long*>(ptr),
        static_cast<long>(desired),
        static_cast<long>(expected));
    return previous == static_cast<long>(expected);
}

inline bool skate3_recomp_sync_bool_compare_and_swap(uint64_t* ptr, int64_t expected, uint64_t desired)
{
    const __int64 previous = _InterlockedCompareExchange64(
        reinterpret_cast<volatile __int64*>(ptr),
        static_cast<__int64>(desired),
        static_cast<__int64>(expected));
    return previous == static_cast<__int64>(expected);
}

#define __sync_bool_compare_and_swap(ptr, expected, desired) \
    skate3_recomp_sync_bool_compare_and_swap((ptr), (expected), (desired))

#define PPC_LOAD_U8(x) runtime::boot::Skate3PpcLoadU8(ctx, base, static_cast<uint64_t>(x))
#define PPC_LOAD_U16(x) runtime::boot::Skate3PpcLoadU16(ctx, base, static_cast<uint64_t>(x))
#define PPC_LOAD_U32(x) runtime::boot::Skate3PpcLoadU32(ctx, base, static_cast<uint64_t>(x))
#define PPC_LOAD_U64(x) runtime::boot::Skate3PpcLoadU64(ctx, base, static_cast<uint64_t>(x))
#define PPC_STORE_U8(x, y) runtime::boot::Skate3PpcStoreU8(ctx, base, static_cast<uint64_t>(x), static_cast<uint8_t>(y))
#define PPC_STORE_U16(x, y) runtime::boot::Skate3PpcStoreU16(ctx, base, static_cast<uint64_t>(x), static_cast<uint16_t>(y))
#define PPC_STORE_U32(x, y) runtime::boot::Skate3PpcStoreU32(ctx, base, static_cast<uint64_t>(x), static_cast<uint32_t>(y))
#define PPC_STORE_U64(x, y) runtime::boot::Skate3PpcStoreU64(ctx, base, static_cast<uint64_t>(x), static_cast<uint64_t>(y))

#endif
