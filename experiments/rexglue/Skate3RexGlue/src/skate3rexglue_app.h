// skate3rexglue - ReXGlue Recompiled Project
//
// Customize your app by overriding virtual hooks from rex::ReXApp.

#pragma once

#include <filesystem>
#include <rex/system/flags.h>
#include <rex/rex_app.h>
#include <rex/filesystem.h>

class Skate3rexglueApp : public rex::ReXApp {
 public:
  using rex::ReXApp::ReXApp;

  static std::unique_ptr<rex::ui::WindowedApp> Create(
      rex::ui::WindowedAppContext& ctx) {
    return std::unique_ptr<Skate3rexglueApp>(new Skate3rexglueApp(ctx, "skate3rexglue",
        PPCImageConfig));
  }

  // Override virtual hooks for customization:
  // void OnPostInitLogging() override {}
  // void OnPreSetup(rex::RuntimeConfig& config) override {}
  // void OnLoadXexImage(std::string& xex_image) override {}
  // void OnPostSetup() override {}
  // void OnCreateDialogs(rex::ui::ImGuiDrawer* drawer) override {}
  // void OnShutdown() override {}
  void OnPreSetup(rex::RuntimeConfig& config) override {
    (void)config;
    REXCVAR_SET(protect_zero, false);
  }

  void OnConfigurePaths(rex::PathConfig& paths) override {
    if (!paths.game_data_root.empty()) {
      return;
    }

    const auto exe_dir = rex::filesystem::GetExecutableFolder();
    const auto cwd = std::filesystem::current_path();
    const std::filesystem::path candidates[] = {
        exe_dir / "game",
        exe_dir / "iso_extracted",
        cwd / "game",
        cwd / "iso_extracted",
        exe_dir / ".." / ".." / ".." / ".." / ".." / ".." / "game",
        cwd / ".." / ".." / ".." / ".." / ".." / ".." / "game",
        exe_dir / ".." / ".." / ".." / ".." / ".." / "Skate-3-Recomp-PC" / "game",
        cwd / ".." / ".." / ".." / ".." / ".." / "Skate-3-Recomp-PC" / "game",
        "C:/Users/HelmXGaming/Documents/GitHub/Skate-3-Recomp-PC/game",
    };

    for (const auto& candidate : candidates) {
      std::error_code ec;
      if (std::filesystem::is_regular_file(candidate / "default.xex", ec)) {
        paths.game_data_root = std::filesystem::weakly_canonical(candidate, ec);
        if (ec) {
          paths.game_data_root = std::filesystem::absolute(candidate);
        }
        return;
      }
    }
  }
};
