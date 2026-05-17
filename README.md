# Skate 3 Recompilation Project

This project is an early Skate 3 native Windows recompilation experiment using the XenonRecomp toolchain. The current milestone is a launchable Windows launcher UI that can select, extract, validate, and cache the required game files. Native game boot is not wired yet.

## Current Status

- `Skate3Launcher.exe` resolves the repo root even when run from the build output directory.
- The launcher has a native Windows menu UI with Skate 3 logo art, Play/Settings/Quit actions, a settings screen, and bottom-right asset status.
- It accepts either `game/default.xex` from an extracted dump or `game/Skate3.iso`.
- ISO extraction uses `tools/bin/extract-xiso.exe`.
- Required files are checked through `tools/manifest_boot.json`.
- Validated files are copied into `cache/Skate3`.
- `tools/run_recomp.bat` can build XenonRecomp tools, analyse `game/default.xex`, and generate raw PPC C++ into `generated/ppc`.
- Generated recomp output is intentionally ignored by Git; rerun the tool when you need to refresh it.
- Pressing Play now enters the runtime boot path after validation: it mounts cached content, reads `default.xex`, parses XEX metadata, decrypts/decompresses the XEX image, reserves guest address space, and reports the current guest-entry blocker.
- The default build still produces only `Skate3Launcher.exe`. When configured with `SKATE3_ENABLE_RECOMP_LIB=ON`, the runtime also wires a guarded generated-PPC entry bridge and import stubs for the next launch milestone.

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

Press **PLAY** to select/import an ISO when needed. **SETTINGS** opens a placeholder settings menu; the Game ISO row already works and lets you pick `Skate3.iso`. If validation succeeds, the cache is prepared and the launcher enters the runtime boot path. If files are missing, it shows a clear error.

## Manual Build

```bat
cmake --preset windows-msvc-release
cmake --build --preset msvc-release
```

The launcher is written to `build-msvc/bin/Release/Skate3Launcher.exe`.

## Recompilation Pipeline

The first native-game milestone is to produce generated C++ from the extracted Xbox 360 executable:

```bat
tools\run_recomp.bat
```

This script expects `game/default.xex` or a launcher-imported `cache/Skate3/iso_extracted/default.xex`, builds `XenonAnalyse.exe` and `XenonRecomp.exe`, writes switch-table data to `Skate3RecompLib/config/skate3_switches.toml`, and writes generated PPC output to `generated/ppc`.

The generated C++ can be wired into CMake with:

```bat
cmake -S . -B build-recomp-test -G "Visual Studio 17 2022" -A x64 -DSKATE3_ENABLE_RECOMP_LIB=ON
cmake --build build-recomp-test --config Release --target Skate3RecompLib
```

This target is not part of the default launcher build yet. The runtime can now stage the XEX image and has a guarded bridge for generated PPC entry dispatch, but the current raw recomp pass still reports missing save/restore helper addresses and unsupported PPC instructions. Those helper addresses and the first real kernel/XAM import implementations are the next boot blockers.

## Layout

```text
launcher/      Windows launcher and asset validation/import logic
launcher/assets/ Logo and icon assets used by the launcher
runtime/       Early host runtime/HAL shims
runtime/boot/  XEX boot parser and guest-memory launch staging
gameexe/       Optional boot stub placeholder for future recompiled game entry
Skate3RecompLib/ Optional generated PPC static library wrapper and config
tools/         Helper tools and manifests
third_party/   XenonRecomp dependency
game/          User-provided extracted dump or ISO
cache/         Launcher-generated verified content cache
generated/     Ignored XenonRecomp output
```
