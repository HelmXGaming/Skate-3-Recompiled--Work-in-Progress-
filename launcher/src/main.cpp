// launcher/src/main.cpp
#include <filesystem>
#include <string>
#include <vector>
#include <windows.h>
#include <gdiplus.h>
#include <commdlg.h>
#include <shlobj.h>
#include <windowsx.h>

#include "../../runtime/hal/fs.h"
#include "../../runtime/hal/sys.h"
#include "../../runtime/boot/game_boot.h"

#include "asset_locator.h"
#include "importer.h"
#include "iso_utils.h"
#include "resource.h"
#include "validator.h"
#include "win_dialogs.h"

namespace fs = std::filesystem;
using namespace Gdiplus;

namespace {

constexpr int kWindowWidth = 1280;
constexpr int kWindowHeight = 720;
#if defined(SKATE3_HAS_RECOMP_LIB)
constexpr const char* kVersion = "Version 0.1.0 + Recomp";
constexpr const char* kWindowTitle = "Skate 3 Recomp Launcher (Recomp Linked)";
#else
constexpr const char* kVersion = "Version 0.1.0";
constexpr const char* kWindowTitle = "Skate 3 Recomp Launcher";
#endif

enum class Screen {
    Main,
    Settings,
};

enum class Action {
    None,
    Play,
    Settings,
    Quit,
    IsoPath,
    DisplayMode,
    Renderer,
    Audio,
    Back,
};

struct AppState {
    fs::path repo_root;
    fs::path config_path;
    fs::path manifest_path;
    LauncherConfig config;
    std::string source;
    std::string content_root;
    std::string status = "No ISO selected.";
    std::string detail = "Xbox 360";
    Screen screen = Screen::Main;
    Action hover = Action::None;
    Rect play_rect{};
    Rect settings_rect{};
    Rect quit_rect{};
    Rect iso_rect{};
    Rect display_rect{};
    Rect renderer_rect{};
    Rect audio_rect{};
    Rect back_rect{};
    Image* logo = nullptr;
    ULONG_PTR gdiplus_token = 0;
};

static AppState g_app;

static std::wstring Widen(const std::string& value) {
    if (value.empty()) return {};
    int size = MultiByteToWideChar(CP_UTF8, 0, value.c_str(), -1, nullptr, 0);
    UINT code_page = CP_UTF8;
    if (size <= 0) {
        size = MultiByteToWideChar(CP_ACP, 0, value.c_str(), -1, nullptr, 0);
        code_page = CP_ACP;
    }

    std::wstring out(size, L'\0');
    MultiByteToWideChar(code_page, 0, value.c_str(), -1, out.data(), size);
    out.resize(wcslen(out.c_str()));
    return out;
}

static fs::path FindRepoRoot() {
    fs::path p = fs::current_path();
    for (int i = 0; i < 6; ++i) {
        if (fs::exists(p / "CMakeLists.txt") || fs::exists(p / ".git")) return p;
        p = p.parent_path();
        if (p.empty()) break;
    }

    char exe_buf[MAX_PATH]{};
    if (GetModuleFileNameA(nullptr, exe_buf, MAX_PATH)) {
        fs::path q = fs::path(exe_buf).parent_path();
        for (int i = 0; i < 6; ++i) {
            if (fs::exists(q / "CMakeLists.txt") || fs::exists(q / ".git")) return q;
            q = q.parent_path();
            if (q.empty()) break;
        }
    }

    return fs::current_path();
}

static void UpdateStatusFromSource() {
    if (!g_app.content_root.empty()) {
        g_app.status = "Cache ready.";
    } else if (!g_app.source.empty()) {
        g_app.status = "ISO selected.";
    } else {
        g_app.status = "No ISO selected.";
    }
}

static void InitializeConfigAndAssets() {
    g_app.config_path = g_app.repo_root / "skate3_recomp.config.json";
    g_app.manifest_path = g_app.repo_root / "tools" / "manifest_boot.json";

    auto cfg_opt = LoadConfig(g_app.config_path.string());
    g_app.config = cfg_opt.value_or(LauncherConfig{});
    if (g_app.config.cache_dir.empty()) {
        g_app.config.cache_dir = (g_app.repo_root / "cache" / "Skate3").string();
    }

    g_app.source = ResolveGameRoot(g_app.config);
    UpdateStatusFromSource();

    fs::path logo_path = g_app.repo_root / "launcher" / "assets" / "skate3_logo.png";
    std::wstring wide_logo = logo_path.wstring();
    g_app.logo = Image::FromFile(wide_logo.c_str(), FALSE);
    if (!g_app.logo || g_app.logo->GetLastStatus() != Ok) {
        delete g_app.logo;
        g_app.logo = nullptr;
    }
}

static std::string PickIsoFile(HWND owner) {
    char file_name[MAX_PATH]{};
    OPENFILENAMEA ofn{};
    ofn.lStructSize = sizeof(ofn);
    ofn.hwndOwner = owner;
    ofn.lpstrFilter = "Xbox 360 ISO (*.iso)\0*.iso\0All files (*.*)\0*.*\0";
    ofn.lpstrFile = file_name;
    ofn.nMaxFile = MAX_PATH;
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
    ofn.lpstrTitle = "Select Skate 3 ISO";

    return GetOpenFileNameA(&ofn) ? fs::absolute(file_name).string() : std::string{};
}

static void SelectIso(HWND hwnd) {
    std::string picked = PickIsoFile(hwnd);
    if (picked.empty()) return;

    g_app.source = picked;
    g_app.content_root.clear();
    g_app.config.game_root = picked;
    SaveConfig(g_app.config_path.string(), g_app.config);
    UpdateStatusFromSource();
    InvalidateRect(hwnd, nullptr, FALSE);
}

static bool ValidateAndImport(HWND hwnd) {
    if (g_app.source.empty()) {
        SelectIso(hwnd);
        if (g_app.source.empty()) {
            g_app.status = "No ISO selected.";
            InvalidateRect(hwnd, nullptr, FALSE);
            return false;
        }
    }

    g_app.status = "Preparing source...";
    InvalidateRect(hwnd, nullptr, FALSE);
    UpdateWindow(hwnd);

    std::string source = g_app.source;
    std::string fail;

    std::string maybe_extracted = ExtractIsoIfNeeded(source, g_app.config.cache_dir, fail);
    if (maybe_extracted.empty()) {
        g_app.status = "Import failed.";
        ShowErrorDialog("ISO extraction failed.\n" + fail);
        InvalidateRect(hwnd, nullptr, FALSE);
        return false;
    }
    source = maybe_extracted;

    Manifest manifest;
    if (!LoadManifest(g_app.manifest_path.string(), manifest)) {
        g_app.status = "Manifest missing.";
        ShowErrorDialog("Failed to load tools/manifest_boot.json.");
        InvalidateRect(hwnd, nullptr, FALSE);
        return false;
    }

    if (!ValidateFiles(source, manifest, fail)) {
        g_app.status = "Validation failed.";
        ShowErrorDialog("Validation failed on source dump.\n" + fail);
        InvalidateRect(hwnd, nullptr, FALSE);
        return false;
    }

    if (g_app.config.prefer_cache) {
        g_app.status = "Importing assets...";
        InvalidateRect(hwnd, nullptr, FALSE);
        UpdateWindow(hwnd);

        if (!ImportToCache(source, g_app.config.cache_dir, manifest, fail)) {
            g_app.status = "Import failed.";
            ShowErrorDialog("Import to cache failed.\n" + fail);
            InvalidateRect(hwnd, nullptr, FALSE);
            return false;
        }

        g_app.config.game_root = source;
        SaveConfig(g_app.config_path.string(), g_app.config);
        hal::fs::set_game_root(g_app.config.cache_dir);
        g_app.content_root = fs::absolute(g_app.config.cache_dir).string();
    } else {
        hal::fs::set_game_root(source);
        g_app.content_root = fs::absolute(source).string();
    }

    g_app.source = source;
    g_app.status = "Cache ready.";
    InvalidateRect(hwnd, nullptr, FALSE);
    return true;
}

static std::string QuoteArg(const fs::path& path) {
    std::string value = path.string();
    std::string quoted = "\"";
    for (char c : value) {
        if (c == '"' || c == '\\') quoted.push_back('\\');
        quoted.push_back(c);
    }
    quoted.push_back('"');
    return quoted;
}

static fs::path FindReXGlueExe() {
    std::vector<fs::path> candidates = {
        g_app.repo_root / "build-rexglue" / "skate3rexglue.exe",
        g_app.repo_root / "experiments" / "rexglue" / "Skate3RexGlue" /
            "out" / "build" / "win-amd64-release" / "skate3rexglue.exe",
        g_app.repo_root.parent_path() / "Skate-3-ReXGlue-Experiment" / "Skate3RexGlue" /
            "out" / "build" / "win-amd64-release" / "skate3rexglue.exe",
        fs::current_path() / "skate3rexglue.exe",
    };

    char exe_buf[MAX_PATH]{};
    if (GetModuleFileNameA(nullptr, exe_buf, MAX_PATH)) {
        candidates.push_back(fs::path(exe_buf).parent_path() / "skate3rexglue.exe");
    }

    for (const auto& candidate : candidates) {
        std::error_code ec;
        if (fs::exists(candidate, ec) && fs::is_regular_file(candidate, ec)) {
            return fs::absolute(candidate, ec);
        }
    }

    return {};
}

static bool LaunchReXGlueRuntime(HWND hwnd, const std::string& content_root) {
    fs::path exe = FindReXGlueExe();
    if (exe.empty()) {
        ShowErrorDialog(
            "ReXGlue runtime executable was not found.\n\n"
            "Expected build output near:\n"
            "experiments\\rexglue\\Skate3RexGlue\\out\\build\\win-amd64-release\\skate3rexglue.exe\n"
            "or:\n"
            "C:\\Users\\HelmXGaming\\Documents\\GitHub\\Skate-3-ReXGlue-Experiment\\Skate3RexGlue\\out\\build\\win-amd64-release\\skate3rexglue.exe");
        return false;
    }

    fs::path content = fs::absolute(content_root);
    std::string cmd = QuoteArg(exe) + " --game_data_root " + QuoteArg(content);
    std::string mutable_cmd = cmd;

    STARTUPINFOA si{};
    si.cb = sizeof(si);
    PROCESS_INFORMATION pi{};
    std::string work_dir = exe.parent_path().string();

    BOOL ok = CreateProcessA(
        nullptr,
        mutable_cmd.data(),
        nullptr,
        nullptr,
        FALSE,
        0,
        nullptr,
        work_dir.c_str(),
        &si,
        &pi);

    if (!ok) {
        ShowErrorDialog("Failed to launch ReXGlue runtime.\nCreateProcess error " +
                        std::to_string(GetLastError()));
        return false;
    }

    CloseHandle(pi.hThread);
    CloseHandle(pi.hProcess);
    g_app.detail = "ReXGlue standalone";
    return true;
}

static void LaunchGame(HWND hwnd) {
    if (!ValidateAndImport(hwnd)) return;

    g_app.status = "Launching ReXGlue runtime...";
    InvalidateRect(hwnd, nullptr, FALSE);
    UpdateWindow(hwnd);

    bool launched = LaunchReXGlueRuntime(hwnd, g_app.content_root);
    g_app.status = launched ? "Runtime launched." : "Launch failed.";
    InvalidateRect(hwnd, nullptr, FALSE);
}

static Action HitTestMain(int x, int y) {
    Point p(x, y);
    if (g_app.play_rect.Contains(p)) return Action::Play;
    if (g_app.settings_rect.Contains(p)) return Action::Settings;
    if (g_app.quit_rect.Contains(p)) return Action::Quit;
    return Action::None;
}

static Action HitTestSettings(int x, int y) {
    Point p(x, y);
    if (g_app.iso_rect.Contains(p)) return Action::IsoPath;
    if (g_app.display_rect.Contains(p)) return Action::DisplayMode;
    if (g_app.renderer_rect.Contains(p)) return Action::Renderer;
    if (g_app.audio_rect.Contains(p)) return Action::Audio;
    if (g_app.back_rect.Contains(p)) return Action::Back;
    return Action::None;
}

static Action HitTest(int x, int y) {
    return g_app.screen == Screen::Main ? HitTestMain(x, y) : HitTestSettings(x, y);
}

static void DrawTextLine(Graphics& graphics, const wchar_t* text, const FontFamily& family,
    REAL size, INT style, RectF rect, Color color, StringAlignment align = StringAlignmentNear) {
    Font font(&family, size, style, UnitPixel);
    SolidBrush brush(color);
    StringFormat format;
    format.SetAlignment(align);
    format.SetLineAlignment(StringAlignmentCenter);
    format.SetTrimming(StringTrimmingEllipsisCharacter);
    graphics.DrawString(text, -1, &font, rect, &format, &brush);
}

static void DrawPanel(Graphics& graphics, Rect rect, Color fill, Color border) {
    SolidBrush brush(fill);
    Pen pen(border, 1.5f);
    graphics.FillRectangle(&brush, rect);
    graphics.DrawRectangle(&pen, rect);
}

static void DrawMenuButton(Graphics& graphics, const FontFamily& family, Rect rect,
    const wchar_t* label, Action action, bool primary = false) {
    bool hot = g_app.hover == action;
    Color fill = primary ? Color(232, 255, 118, 32) : Color(110, 22, 24, 28);
    if (hot) fill = primary ? Color(255, 255, 143, 50) : Color(155, 52, 56, 64);

    DrawPanel(graphics, rect, fill, hot ? Color(220, 255, 255, 255) : Color(80, 255, 255, 255));
    DrawTextLine(graphics, label, family, primary ? 46.0f : 34.0f, FontStyleRegular,
        RectF(static_cast<REAL>(rect.X + 28), static_cast<REAL>(rect.Y),
            static_cast<REAL>(rect.Width - 56), static_cast<REAL>(rect.Height)),
        primary ? Color(255, 0, 0, 0) : Color(245, 255, 255, 255), StringAlignmentNear);
}

static void DrawSettingRow(Graphics& graphics, const FontFamily& family, Rect rect,
    const wchar_t* label, const std::string& value, Action action, bool enabled = true) {
    bool hot = g_app.hover == action;
    Color fill = hot ? Color(165, 38, 42, 48) : Color(118, 18, 20, 24);
    DrawPanel(graphics, rect, fill, hot ? Color(210, 255, 118, 32) : Color(72, 255, 255, 255));

    Color label_color = enabled ? Color(245, 255, 255, 255) : Color(150, 180, 180, 180);
    Color value_color = enabled ? Color(210, 220, 220, 220) : Color(120, 145, 145, 145);
    DrawTextLine(graphics, label, family, 26.0f, FontStyleRegular,
        RectF(static_cast<REAL>(rect.X + 24), static_cast<REAL>(rect.Y),
            260.0f, static_cast<REAL>(rect.Height)), label_color, StringAlignmentNear);
    DrawTextLine(graphics, Widen(value).c_str(), family, 20.0f, FontStyleRegular,
        RectF(static_cast<REAL>(rect.X + 300), static_cast<REAL>(rect.Y),
            static_cast<REAL>(rect.Width - 324), static_cast<REAL>(rect.Height)),
        value_color, StringAlignmentFar);
}

static void DrawBackground(Graphics& graphics, int width, int height) {
    SolidBrush bg(Color(255, 0, 0, 0));
    graphics.FillRectangle(&bg, 0, 0, width, height);

    LinearGradientBrush shade(
        Rect(0, 0, width, height),
        Color(255, 18, 18, 18),
        Color(255, 0, 0, 0),
        LinearGradientModeForwardDiagonal);
    graphics.FillRectangle(&shade, 0, 0, width, height);

    SolidBrush left_wash(Color(42, 255, 116, 30));
    graphics.FillRectangle(&left_wash, 0, 0, 340, height);
}

static void DrawMain(Graphics& graphics, int width, int height, const FontFamily& family) {
    if (g_app.logo) {
        int logo_w = min(560, width / 2);
        int logo_h = static_cast<int>(logo_w * (static_cast<double>(g_app.logo->GetHeight()) / g_app.logo->GetWidth()));
        graphics.DrawImage(g_app.logo, Rect(78, 82, logo_w, logo_h));
    }

    DrawTextLine(graphics, Widen(kVersion).c_str(), family, 24.0f, FontStyleRegular,
        RectF(static_cast<REAL>(width - 300), 42.0f, 240.0f, 38.0f),
        Color(235, 255, 255, 255), StringAlignmentFar);

    DrawTextLine(graphics, L"NATIVE WINDOWS RECOMP PROJECT", family, 18.0f, FontStyleRegular,
        RectF(84.0f, 246.0f, 440.0f, 28.0f), Color(170, 230, 230, 230), StringAlignmentNear);

    int menu_x = 735;
    g_app.play_rect = Rect(menu_x, 150, 430, 88);
    g_app.settings_rect = Rect(menu_x + 52, 292, 360, 70);
    g_app.quit_rect = Rect(menu_x + 52, 392, 360, 70);

    DrawMenuButton(graphics, family, g_app.play_rect, L"PLAY", Action::Play, true);
    DrawMenuButton(graphics, family, g_app.settings_rect, L"SETTINGS", Action::Settings);
    DrawMenuButton(graphics, family, g_app.quit_rect, L"QUIT", Action::Quit);

    std::wstring status = Widen(g_app.status);
    std::wstring detail = Widen(g_app.detail);
    DrawTextLine(graphics, status.c_str(), family, 26.0f, FontStyleRegular,
        RectF(static_cast<REAL>(width - 424), static_cast<REAL>(height - 108), 360.0f, 40.0f),
        Color(255, 206, 255, 140), StringAlignmentFar);
    DrawTextLine(graphics, detail.c_str(), family, 20.0f, FontStyleRegular,
        RectF(static_cast<REAL>(width - 424), static_cast<REAL>(height - 66), 360.0f, 32.0f),
        Color(175, 205, 205, 205), StringAlignmentFar);

    if (!g_app.source.empty()) {
        std::wstring source = Widen(fs::path(g_app.source).filename().string());
        DrawTextLine(graphics, source.c_str(), family, 16.0f, FontStyleRegular,
            RectF(52.0f, static_cast<REAL>(height - 48), 560.0f, 28.0f),
            Color(155, 210, 210, 210), StringAlignmentNear);
    }
}

static void DrawSettings(Graphics& graphics, int width, int height, const FontFamily& family) {
    DrawTextLine(graphics, L"SETTINGS", family, 48.0f, FontStyleRegular,
        RectF(84.0f, 58.0f, 420.0f, 68.0f), Color(245, 255, 255, 255), StringAlignmentNear);
    DrawTextLine(graphics, L"Launcher options are placeholders while the runtime comes online.", family, 18.0f, FontStyleRegular,
        RectF(88.0f, 122.0f, 760.0f, 30.0f), Color(165, 220, 220, 220), StringAlignmentNear);

    int row_x = 116;
    int row_w = width - 232;
    int row_h = 70;
    g_app.iso_rect = Rect(row_x, 190, row_w, row_h);
    g_app.display_rect = Rect(row_x, 280, row_w, row_h);
    g_app.renderer_rect = Rect(row_x, 370, row_w, row_h);
    g_app.audio_rect = Rect(row_x, 460, row_w, row_h);
    g_app.back_rect = Rect(row_x, 582, 240, 58);

    std::string iso_value = g_app.source.empty() ? "Select Skate3.iso" : fs::path(g_app.source).filename().string();
    DrawSettingRow(graphics, family, g_app.iso_rect, L"Game ISO", iso_value, Action::IsoPath);
    DrawSettingRow(graphics, family, g_app.display_rect, L"Display", "Fullscreen toggle coming later", Action::DisplayMode, false);
    DrawSettingRow(graphics, family, g_app.renderer_rect, L"Renderer", "Direct3D backend placeholder", Action::Renderer, false);
    DrawSettingRow(graphics, family, g_app.audio_rect, L"Audio", "Output device placeholder", Action::Audio, false);
    DrawMenuButton(graphics, family, g_app.back_rect, L"BACK", Action::Back);
}

static void PaintLauncherTo(Graphics& graphics, HWND hwnd) {
    RECT client_rect{};
    GetClientRect(hwnd, &client_rect);
    int width = client_rect.right - client_rect.left;
    int height = client_rect.bottom - client_rect.top;

    graphics.SetSmoothingMode(SmoothingModeAntiAlias);
    graphics.SetTextRenderingHint(TextRenderingHintClearTypeGridFit);
    DrawBackground(graphics, width, height);

    FontFamily font_family(L"Segoe UI");
    if (g_app.screen == Screen::Main) {
        DrawMain(graphics, width, height, font_family);
    } else {
        DrawSettings(graphics, width, height, font_family);
    }
}

static void PaintLauncher(HWND hwnd) {
    PAINTSTRUCT ps{};
    HDC hdc = BeginPaint(hwnd, &ps);

    RECT client_rect{};
    GetClientRect(hwnd, &client_rect);
    int width = client_rect.right - client_rect.left;
    int height = client_rect.bottom - client_rect.top;

    HDC mem_dc = CreateCompatibleDC(hdc);
    HBITMAP bitmap = CreateCompatibleBitmap(hdc, width, height);
    HGDIOBJ old_bitmap = SelectObject(mem_dc, bitmap);
    {
        Graphics graphics(mem_dc);
        PaintLauncherTo(graphics, hwnd);
    }
    BitBlt(hdc, 0, 0, width, height, mem_dc, 0, 0, SRCCOPY);
    SelectObject(mem_dc, old_bitmap);
    DeleteObject(bitmap);
    DeleteDC(mem_dc);

    EndPaint(hwnd, &ps);
}

static void ClickAction(HWND hwnd, Action action) {
    switch (action) {
    case Action::Play:
        LaunchGame(hwnd);
        break;
    case Action::Settings:
        g_app.screen = Screen::Settings;
        g_app.hover = Action::None;
        InvalidateRect(hwnd, nullptr, FALSE);
        break;
    case Action::Quit:
        DestroyWindow(hwnd);
        break;
    case Action::IsoPath:
        SelectIso(hwnd);
        break;
    case Action::DisplayMode:
        g_app.status = "Display settings are not implemented yet.";
        InvalidateRect(hwnd, nullptr, FALSE);
        break;
    case Action::Renderer:
        g_app.status = "Renderer settings are not implemented yet.";
        InvalidateRect(hwnd, nullptr, FALSE);
        break;
    case Action::Audio:
        g_app.status = "Audio settings are not implemented yet.";
        InvalidateRect(hwnd, nullptr, FALSE);
        break;
    case Action::Back:
        g_app.screen = Screen::Main;
        g_app.hover = Action::None;
        InvalidateRect(hwnd, nullptr, FALSE);
        break;
    default:
        break;
    }
}

static LRESULT CALLBACK WindowProc(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam) {
    switch (msg) {
    case WM_CREATE:
        InitializeConfigAndAssets();
        return 0;

    case WM_ERASEBKGND:
        return 1;

    case WM_MOUSEMOVE: {
        TRACKMOUSEEVENT tme{};
        tme.cbSize = sizeof(tme);
        tme.dwFlags = TME_LEAVE;
        tme.hwndTrack = hwnd;
        TrackMouseEvent(&tme);

        Action hover = HitTest(GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam));
        if (hover != g_app.hover) {
            g_app.hover = hover;
            InvalidateRect(hwnd, nullptr, FALSE);
        }
        return 0;
    }

    case WM_MOUSELEAVE:
        if (g_app.hover != Action::None) {
            g_app.hover = Action::None;
            InvalidateRect(hwnd, nullptr, FALSE);
        }
        return 0;

    case WM_LBUTTONUP:
        ClickAction(hwnd, HitTest(GET_X_LPARAM(lparam), GET_Y_LPARAM(lparam)));
        return 0;

    case WM_SETCURSOR:
        if (g_app.hover != Action::None) {
            SetCursor(LoadCursor(nullptr, IDC_HAND));
            return TRUE;
        }
        break;

    case WM_KEYDOWN:
        if (wparam == VK_ESCAPE && g_app.screen == Screen::Settings) {
            g_app.screen = Screen::Main;
            g_app.hover = Action::None;
            InvalidateRect(hwnd, nullptr, FALSE);
            return 0;
        }
        break;

    case WM_PAINT:
        PaintLauncher(hwnd);
        return 0;

    case WM_DESTROY:
        delete g_app.logo;
        g_app.logo = nullptr;
        PostQuitMessage(0);
        return 0;
    }

    return DefWindowProcA(hwnd, msg, wparam, lparam);
}

} // namespace

int WINAPI WinMain(HINSTANCE instance, HINSTANCE, LPSTR, int show_cmd) {
    hal::sys::init_logging();
    CoInitializeEx(nullptr, COINIT_APARTMENTTHREADED);

    GdiplusStartupInput gdiplus_input;
    if (GdiplusStartup(&g_app.gdiplus_token, &gdiplus_input, nullptr) != Ok) {
        ShowErrorDialog("Failed to initialize graphics.");
        return 1;
    }

    g_app.repo_root = FindRepoRoot();
    std::error_code ec;
    fs::current_path(g_app.repo_root, ec);
    if (ec) {
        ShowErrorDialog("Failed to set working directory to repo root.\n" + ec.message());
        GdiplusShutdown(g_app.gdiplus_token);
        CoUninitialize();
        return 1;
    }

    const char* class_name = "Skate3RecompLauncherWindow";
    WNDCLASSA wc{};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = instance;
    wc.lpszClassName = class_name;
    wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wc.hIcon = LoadIconA(instance, MAKEINTRESOURCEA(IDI_SKATE3));
    wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(BLACK_BRUSH));
    RegisterClassA(&wc);

    HWND hwnd = CreateWindowExA(0, class_name, kWindowTitle,
        WS_OVERLAPPED | WS_CAPTION | WS_SYSMENU | WS_MINIMIZEBOX,
        CW_USEDEFAULT, CW_USEDEFAULT, kWindowWidth, kWindowHeight,
        nullptr, nullptr, instance, nullptr);
    if (!hwnd) {
        GdiplusShutdown(g_app.gdiplus_token);
        CoUninitialize();
        return 1;
    }

    SendMessageA(hwnd, WM_SETICON, ICON_SMALL, reinterpret_cast<LPARAM>(LoadIconA(instance, MAKEINTRESOURCEA(IDI_SKATE3))));
    SendMessageA(hwnd, WM_SETICON, ICON_BIG, reinterpret_cast<LPARAM>(LoadIconA(instance, MAKEINTRESOURCEA(IDI_SKATE3))));

    ShowWindow(hwnd, show_cmd);
    UpdateWindow(hwnd);

    MSG msg{};
    while (GetMessageA(&msg, nullptr, 0, 0) > 0) {
        TranslateMessage(&msg);
        DispatchMessageA(&msg);
    }

    GdiplusShutdown(g_app.gdiplus_token);
    CoUninitialize();
    return static_cast<int>(msg.wParam);
}
