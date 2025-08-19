#include "mem.h"
#include <cstring>

#if defined(_MSC_VER)
#include <malloc.h> // _aligned_malloc/_aligned_free
static inline void* host_aligned_alloc(size_t alignment, size_t size) {
    return _aligned_malloc(size, alignment);
}
static inline void host_aligned_free(void* p) { _aligned_free(p); }
#else
#include <cstdlib>  // std::aligned_alloc/free
static inline void* host_aligned_alloc(size_t alignment, size_t size) {
    // size must be a multiple of alignment per spec
    size = (size + alignment - 1) & ~(alignment - 1);
    return std::aligned_alloc(alignment, size);
}
static inline void host_aligned_free(void* p) { std::free(p); }
#endif

struct ppc_context { uint64_t regs[64]; }; // placeholder

std::pair<ppc_context*, uint8_t*> hal::mem::create_guest_state() {
    auto* ctx = new ppc_context{};
    const size_t guest_size = size_t(512) * 1024 * 1024; // 512 MB
    auto* base = static_cast<uint8_t*>(host_aligned_alloc(64, guest_size));
    std::memset(base, 0, guest_size);
    return { ctx, base };
}
