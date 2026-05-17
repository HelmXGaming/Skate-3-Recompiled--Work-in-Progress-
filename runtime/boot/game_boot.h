#pragma once

#include <cstdint>
#include <string>

namespace runtime::boot {

struct BootResult {
    bool ok = false;
    bool ready_to_enter_guest = false;
    uint32_t entry_point = 0;
    uint32_t image_base = 0;
    uint32_t image_size = 0;
    uint16_t encryption_type = 0;
    uint16_t compression_type = 0;
    std::string message;
};

BootResult LaunchFromContentRoot(const std::string& content_root);

}
