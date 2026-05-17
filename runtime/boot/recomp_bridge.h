#pragma once

#include <cstddef>
#include <cstdint>
#include <string>

namespace runtime::boot {

struct RecompEntryResult {
    bool available = false;
    bool attempted = false;
    bool returned = false;
    std::string message;
};

bool GetGeneratedFunctionTableRange(uint32_t& start, uint32_t& size);
RecompEntryResult TryEnterGeneratedGuest(uint32_t entry_point, uint8_t* guest_base, uint32_t stack_top);

}
