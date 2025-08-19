#pragma once
#include <string>
#include "validator.h"

// Copies required files from sourceRoot (extracted folder) to cacheDir.
// Returns false on first failure and writes reason to failReason.
bool ImportToCache(const std::string& sourceRoot,
                   const std::string& cacheDir,
                   const Manifest& m,
                   std::string& failReason);
