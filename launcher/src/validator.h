#pragma once
#include <string>
#include <vector>

struct ManifestEntry {
  std::string path;
  unsigned long long size = 0; // 0 = ignore size
};
struct Manifest {
  std::vector<ManifestEntry> required;
};

bool LoadManifest(const std::string& path, Manifest& out);
bool ValidateFiles(const std::string& root, const Manifest& m, std::string& failReason);
