#include "fs.h"
#include <filesystem>
#include <fstream>
static std::string g_root = "../game";

void hal::fs::set_game_root(std::string root) { g_root = std::move(root); }

std::string hal::fs::map_path(std::string_view p) {
    if (p.rfind("game:/", 0) == 0)
        return (std::filesystem::path(g_root) / std::string(p.substr(6))).string();
    return (std::filesystem::path(g_root) / std::string(p)).string();
}

bool hal::fs::read_file(const std::string& p, std::vector<uint8_t>& out) {
    auto host = map_path(p);
    std::ifstream f(host, std::ios::binary);
    if (!f) return false;
    f.seekg(0, std::ios::end);
    size_t sz = (size_t)f.tellg();
    f.seekg(0);
    out.resize(sz);
    f.read(reinterpret_cast<char*>(out.data()), sz);
    return true;
}
