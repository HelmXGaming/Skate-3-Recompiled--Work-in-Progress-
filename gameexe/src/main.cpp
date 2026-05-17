#include <iostream>
#include <filesystem>
#include <vector>
#include "../../runtime/hal/fs.h"

int main(int argc, char** argv) {
    std::cout << "[Game] Boot stub\n";
    std::string content;

    // parse --content=...
    for (int i = 1; i < argc; ++i) {
        std::string a = argv[i];
        if (a.rfind("--content=", 0) == 0) content = a.substr(10);
    }

    if (content.empty()) {
        std::cerr << "[Game] Missing --content=PATH\n";
        return 2;
    }
    std::cout << "[Game] Content root: " << content << "\n";

    // tell runtime where the game files live
    hal::fs::set_game_root(content);

    // quick smoke test: try to read default.xex via runtime mapping
    std::vector<uint8_t> buf;
    if (!hal::fs::read_file("game:/default.xex", buf)) {
        std::cerr << "[Game] Failed to read game:/default.xex\n";
        return 3;
    }
    std::cout << "[Game] default.xex size: " << buf.size() << " bytes\n";
    std::cout << "[Game] OK. (Next: initialize recompiled code here)\n";
    return 0;
}
