#pragma once
#include <string>
#include <optional>

struct LauncherConfig {
  std::string game_root;          // ISO path or extracted folder
  bool        prefer_cache = true;
  std::string cache_dir    = "./cache/Skate3";
  bool        apply_title_update = false;
  std::string title_update_path;
};

std::optional<LauncherConfig> LoadConfig(const std::string& path);
bool SaveConfig(const std::string& path, const LauncherConfig& cfg);

// Returns absolute path to either a folder (preferred) or ISO file.
// Search order: config.game_root -> ./game/default.xex -> ./game/Skate3.iso
std::string ResolveGameRoot(const LauncherConfig& cfg);
