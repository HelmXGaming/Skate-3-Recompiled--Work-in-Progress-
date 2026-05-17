# Skate 3 Recompilation Project

This project is an early Skate 3 native Windows recompilation experiment using the XenonRecomp toolchain. The current milestone is a launchable Windows launcher UI that can select, extract, validate, and cache the required game files. Native game boot is not wired yet.

## Current Status

- `Skate3Launcher.exe` resolves the repo root even when run from the build output directory.
- The launcher has a native Windows menu UI with Skate 3 logo art, Play/Settings/Quit actions, a settings screen, and bottom-right asset status.
- It accepts either `game/default.xex` from an extracted dump or `game/Skate3.iso`.
- ISO extraction uses `tools/bin/extract-xiso.exe`.
- Required files are checked through `tools/manifest_boot.json`.
- Validated files are copied into `cache/Skate3`.
- The build currently produces only `Skate3Launcher.exe`; game boot code will be wired behind the launcher later.

## Quick Start

1. Install Visual Studio 2022 with the **Desktop development with C++** workload.
2. Put your extracted Skate 3 dump in `game/` with `default.xex`, or put `Skate3.iso` in `game/`.
3. Run:

   ```bat
   setup.bat
   ```

4. Launch:

   ```bat
   build-msvc\bin\Release\Skate3Launcher.exe
   ```

Press **PLAY** to select/import an ISO when needed. **SETTINGS** opens a placeholder settings menu; the Game ISO row already works and lets you pick `Skate3.iso`. If validation succeeds, the cache is prepared and the launcher reports that the cache is ready. If files are missing, it shows a clear error.

## Manual Build

```bat
cmake --preset windows-msvc-release
cmake --build --preset msvc-release
```

The launcher is written to `build-msvc/bin/Release/Skate3Launcher.exe`.

## Layout

```text
launcher/      Windows launcher and asset validation/import logic
launcher/assets/ Logo and icon assets used by the launcher
runtime/       Early host runtime/HAL shims
gameexe/       Optional boot stub placeholder for future recompiled game entry
tools/         Helper tools and manifests
third_party/   XenonRecomp dependency
game/          User-provided extracted dump or ISO
cache/         Launcher-generated verified content cache
```
