#pragma once
#include <cstdint>
#include <utility>
struct ppc_context; // placeholder; real type will come from XenonRecomp
namespace hal::mem {
	std::pair<ppc_context*, uint8_t*> create_guest_state();
}
