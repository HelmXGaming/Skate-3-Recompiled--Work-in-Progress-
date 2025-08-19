#include "validator.h"
#include <filesystem>
#include <fstream>
#include <string>

namespace fs = std::filesystem;

static bool parse_manifest(const std::string& s, Manifest& out) {
  // Minimal JSON sniffing: scan entries for "path" and "size"
  size_t pos = 0;
  while (true) {
    auto p = s.find("\"path\"", pos);
    if (p == std::string::npos) break;
    auto q1 = s.find('"', s.find(':', p) + 1);
    if (q1 == std::string::npos) break;
    auto q2 = s.find('"', q1 + 1);
    if (q2 == std::string::npos) break;
    std::string path = s.substr(q1 + 1, q2 - (q1 + 1));

    unsigned long long size = 0;
    auto sp = s.find("\"size\"", q2);
    if (sp != std::string::npos) {
      auto sc = s.find(':', sp);
      if (sc != std::string::npos) {
        size_t i = sc + 1;
        std::string num;
        while (i < s.size() && (isdigit((unsigned char)s[i]) || s[i] == ' ')) {
          if (isdigit((unsigned char)s[i])) num.push_back(s[i]);
          ++i;
        }
        if (!num.empty()) size = std::stoull(num);
      }
    }
    out.required.push_back({ path, size });
    pos = q2 + 1;
  }
  return !out.required.empty();
}

bool LoadManifest(const std::string& path, Manifest& out) {
  std::ifstream f(path);
  if (!f) return false;
  std::string s((std::istreambuf_iterator<char>(f)), std::istreambuf_iterator<char>());
  return parse_manifest(s, out);
}

bool ValidateFiles(const std::string& root, const Manifest& m, std::string& failReason) {
  for (const auto& e : m.required) {
    fs::path full = fs::path(root) / e.path;
    if (!fs::exists(full)) {
      failReason = "Missing: " + full.string();
      return false;
    }
    if (e.size > 0) {
      auto st = fs::file_size(full);
      if (st != e.size) {
        failReason = "Size mismatch: " + full.string();
        return false;
      }
    }
  }
  return true;
}
