#pragma once
#include <string>

// If sourceRootOrIso is an ISO path, extracts it to <cacheDir>/iso_extracted
// and returns that folder. If it's already a folder, returns it unchanged.
// On failure, returns empty string and sets failReason.
std::string ExtractIsoIfNeeded(const std::string& sourceRootOrIso,
    const std::string& cacheDir,
    std::string& failReason);
