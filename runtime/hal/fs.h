#pragma once
#include <string>
#include <vector>

namespace hal::fs {
	void set_game_root(std::string root);
	std::string map_path(std::string_view p);
	bool read_file(const std::string& xenon_like_path, std::vector<uint8_t>& out);
}
