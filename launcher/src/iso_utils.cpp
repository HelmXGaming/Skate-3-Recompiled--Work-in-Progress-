#include "iso_utils.h"
#include <filesystem>
#include <windows.h>
#include <string>

namespace fs = std::filesystem;

static bool is_iso_path(const std::string& p) {
    auto ext = fs::path(p).extension().string();
    for (auto& c : ext) c = (char)tolower((unsigned char)c);
    return ext == ".iso";
}

static std::string tool_extract_xiso() {
    auto find_from = [](fs::path start)->std::string {
        std::error_code ec;
        start = fs::absolute(start, ec);
        if (ec) return {};

        for (int i = 0; i < 8 && !start.empty(); ++i) {
            fs::path candidate = start / "tools" / "bin" / "extract-xiso.exe";
            if (fs::exists(candidate) && fs::is_regular_file(candidate)) {
                return candidate.string();
            }

            fs::path parent = start.parent_path();
            if (parent == start) break;
            start = parent;
        }

        return {};
        };

    if (auto p = find_from(fs::current_path()); !p.empty()) return p;

    char exe_buf[MAX_PATH]{};
    if (GetModuleFileNameA(nullptr, exe_buf, MAX_PATH)) {
        if (auto p = find_from(fs::path(exe_buf).parent_path()); !p.empty()) return p;
    }

    return {};
}

static bool run_process(const std::string& cmd, const std::string& workdir, std::string& fail) {
    STARTUPINFOA si{ sizeof(si) };
    PROCESS_INFORMATION pi{};
    std::string mutableCmd = cmd;

    BOOL ok = CreateProcessA(
        nullptr,
        mutableCmd.data(),
        nullptr, nullptr, FALSE,
        CREATE_NO_WINDOW,
        nullptr,
        workdir.empty() ? nullptr : workdir.c_str(),
        &si, &pi);

    if (!ok) {
        fail = "CreateProcess failed, code " + std::to_string(GetLastError());
        return false;
    }

    WaitForSingleObject(pi.hProcess, INFINITE);
    DWORD exitCode = 1; GetExitCodeProcess(pi.hProcess, &exitCode);
    CloseHandle(pi.hThread); CloseHandle(pi.hProcess);

    if (exitCode != 0) {
        fail = "extract-xiso exited with code " + std::to_string(exitCode);
        return false;
    }
    return true;
}

std::string ExtractIsoIfNeeded(const std::string& sourceRootOrIso,
    const std::string& cacheDir,
    std::string& failReason) {
    if (!is_iso_path(sourceRootOrIso))
        return sourceRootOrIso; // already a folder

    auto tool = tool_extract_xiso();
    if (tool.empty()) {
        failReason = "tools/bin/extract-xiso.exe not found near the launcher or repository root.";
        return {};
    }

    fs::path outDir = fs::path(cacheDir) / "iso_extracted";
    try { fs::create_directories(outDir); }
    catch (...) {}

    // extract-xiso -x -d "<outDir>" "<iso>"
    std::string cmd = "\"" + tool + "\" -x -d \"" + outDir.string() + "\" \"" + fs::path(sourceRootOrIso).string() + "\"";
    if (!run_process(cmd, "", failReason)) return {};

    // Look for default.xex in a subfolder or root
    fs::path candidate = outDir;
    bool found = false;
    for (auto& e : fs::directory_iterator(outDir)) {
        if (e.is_directory() && fs::exists(e.path() / "default.xex")) {
            candidate = e.path();
            found = true;
            break;
        }
    }
    if (!found && fs::exists(outDir / "default.xex")) {
        candidate = outDir;
        found = true;
    }
    if (!found) {
        failReason = "Extraction completed but default.xex not found under " + outDir.string();
        return {};
    }
    return fs::absolute(candidate).string();
}
