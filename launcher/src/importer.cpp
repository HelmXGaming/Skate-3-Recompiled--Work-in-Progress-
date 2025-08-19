#include "importer.h"
#include <filesystem>
#include <fstream>

namespace fs = std::filesystem;

static bool copy_file_bin(const fs::path& src, const fs::path& dst) {
  fs::create_directories(dst.parent_path());
  std::ifstream in(src, std::ios::binary);
  if (!in) return false;
  std::ofstream out(dst, std::ios::binary | std::ios::trunc);
  if (!out) return false;
  out << in.rdbuf();
  return true;
}

bool ImportToCache(const std::string& sourceRoot,
                   const std::string& cacheDir,
                   const Manifest& m,
                   std::string& failReason) {
  if (!fs::exists(sourceRoot)) {
    failReason = "Source folder not found: " + sourceRoot;
    return false;
  }
  for (const auto& e : m.required) {
    fs::path src = fs::path(sourceRoot) / e.path;
    fs::path dst = fs::path(cacheDir)  / e.path;
    if (!fs::exists(src)) {
      failReason = "Missing in source: " + src.string();
      return false;
    }
    if (!copy_file_bin(src, dst)) {
      failReason = "Copy failed: " + src.string();
      return false;
    }
  }
  return true;
}
