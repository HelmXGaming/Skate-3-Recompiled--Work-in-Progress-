#include "asset_locator.h"
#include <filesystem>
#include <fstream>
#include <string>

namespace fs = std::filesystem;

static bool exists_file(const fs::path& p) { return fs::exists(p) && fs::is_regular_file(p); }
static bool exists_dir(const fs::path& p) { return fs::exists(p) && fs::is_directory(p); }

std::optional<LauncherConfig> LoadConfig(const std::string& path) {
    LauncherConfig cfg;
    if (!exists_file(path)) return cfg; // default-initialized

    std::ifstream f(path);
    if (!f) return cfg;

    std::string s((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());

    auto find_string = [&](const std::string& key)->std::string {
        auto i = s.find("\"" + key + "\"");
        if (i == std::string::npos) return {};
        auto q1 = s.find('"', s.find(':', i));
        if (q1 == std::string::npos) return {};
        auto q2 = s.find('"', q1 + 1);
        if (q2 == std::string::npos) return {};
        return s.substr(q1 + 1, q2 - (q1 + 1));
        };

    auto gr = find_string("game_root");
    auto cd = find_string("cache_dir");
    auto tu = find_string("title_update_path");

    if (!gr.empty()) cfg.game_root = gr;
    if (!cd.empty()) cfg.cache_dir = cd;
    if (!tu.empty()) cfg.title_update_path = tu;

    // rely on defaults for prefer_cache/apply_title_update
    return cfg;
}

bool SaveConfig(const std::string& path, const LauncherConfig& cfg) {
    fs::create_directories(fs::path(path).parent_path());
    std::ofstream f(path, std::ios::trunc);
    if (!f) return false;
    f << "{\n";
    f << "  \"game_root\": \"" << cfg.game_root << "\",\n";
    f << "  \"prefer_cache\": " << (cfg.prefer_cache ? "true" : "false") << ",\n";
    f << "  \"cache_dir\": \"" << cfg.cache_dir << "\",\n";
    f << "  \"apply_title_update\": " << (cfg.apply_title_update ? "true" : "false") << ",\n";
    f << "  \"title_update_path\": \"" << cfg.title_update_path << "\"\n";
    f << "}\n";
    return true;
}

std::string ResolveGameRoot(const LauncherConfig& cfg) {
    // 1) config override
    if (!cfg.game_root.empty() && fs::exists(cfg.game_root))
        return fs::absolute(cfg.game_root).string();

    // 2) ./game (extracted)
    if (exists_dir("game") && exists_file(fs::path("game") / "default.xex"))
        return fs::absolute("game").string();

    // 3) ./game/Skate3.iso
    if (exists_file(fs::path("game") / "Skate3.iso"))
        return fs::absolute(fs::path("game") / "Skate3.iso").string();

    // 4) ../game fallbacks (common if CWD is build/bin)
    if (exists_dir("../game") && exists_file(fs::path("../game") / "default.xex"))
        return fs::absolute("../game").string();
    if (exists_file(fs::path("../game") / "Skate3.iso"))
        return fs::absolute(fs::path("../game") / "Skate3.iso").string();

    return {};
}
