#include <filesystem>
#include <iostream>
#include <string>
#include "iso_utils.h"
#include "../../runtime/hal/fs.h"
#include "asset_locator.h"
#include "validator.h"
#include "importer.h"
#include "win_dialogs.h"

using std::cout;
using std::endl;
namespace fs = std::filesystem;

static const char* kConfigPath = "skate3_recomp.config.json";
static const char* kManifestPath = "tools/manifest_boot.json";

#include <filesystem>
std::cout << "[Launcher] CWD: " << std::filesystem::current_path().string() << "\n";


int main() {
    cout << "[Launcher] Starting...\n";

    // 1) Load config (or defaults)
    auto cfgOpt = LoadConfig(kConfigPath);
    LauncherConfig cfg = cfgOpt.value_or(LauncherConfig{});
    if (cfg.cache_dir.empty()) cfg.cache_dir = "./cache/Skate3";

    // 2) Find source (config → ./game → ./game/Skate3.iso → none)
    std::string sourceRoot = ResolveGameRoot(cfg);
    if (sourceRoot.empty()) {
        ShowErrorDialog("Could not find your Skate 3 dump. Place an extracted dump in ./game/ (with default.xex) "
            "or put Skate3.iso in ./game/, or set game_root in skate3_recomp.config.json.");
        return 2;
    }
    std::cout << "[Launcher] Source: " << sourceRoot << "\n";

    // 2b) If an ISO was chosen, auto-extract it to cache/iso_extracted
    {
        std::string failIso;
        std::string maybeExtracted = ExtractIsoIfNeeded(sourceRoot, cfg.cache_dir, failIso);
        if (maybeExtracted.empty()) {
            ShowErrorDialog("ISO extraction failed.\n" + failIso);
            return 21;
        }
        if (maybeExtracted != sourceRoot) {
            std::cout << "[Launcher] ISO extracted to: " << maybeExtracted << "\n";
            sourceRoot = maybeExtracted;
        }
    }

    // 3) Load manifest
    Manifest manifest;
    if (!LoadManifest(kManifestPath, manifest)) {
        ShowErrorDialog("Failed to load tools/manifest_boot.json. Ensure it exists.");
        return 3;
    }
    cout << "[Launcher] Manifest entries: " << manifest.required.size() << "\n";

    // 4) Validate source (quick fail if the dump is wrong)
    std::string fail;
    if (!ValidateFiles(sourceRoot, manifest, fail)) {
        ShowErrorDialog("Validation failed on source dump.\n" + fail);
        return 4;
    }
    cout << "[Launcher] Source validated.\n";

    // 5) Import to cache (first-run)
    if (cfg.prefer_cache) {
        cout << "[Launcher] Importing required files to cache: " << cfg.cache_dir << "\n";
        if (!ImportToCache(sourceRoot, cfg.cache_dir, manifest, fail)) {
            ShowErrorDialog("Import to cache failed.\n" + fail);
            return 5;
        }
        // Persist config with detected root
        cfg.game_root = sourceRoot;
        SaveConfig(kConfigPath, cfg);
        
        // Point runtime to cache
        hal::fs::set_game_root(cfg.cache_dir);
        cout << "[Launcher] Cache ready.\n";
    }
    else {
        // Point runtime directly at source root
        hal::fs::set_game_root(sourceRoot);
    }

    cout << "[Launcher] ✅ Ready to start the game (stub).\n";
    cout << "[Launcher] (Next step: spawn recompiled game exe and pass content path.)\n";
    return 0;
}
