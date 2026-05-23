# Skate 3 ReXGlue Experiment

Experimental Skate 3 native recompilation route using ReXGlue.

## Current State

- ReXGlue SDK is cloned and installed at `../rexglue-sdk`.
- `skate3rexglue_manifest.toml` points at the extracted Skate 3 XEX in `../../../game/default.xex`.
- `rexglue codegen skate3rexglue_manifest.toml` succeeds.
- The generated project builds successfully into `out/build/win-amd64-release/skate3rexglue.exe`.
- Launching with `--game_data_root` initializes ReXGlue, mounts the extracted game folder, loads `game:\default.xex`, and reaches the Skate 3 language-select flow with the game logo visible.
- The latest smoke tests open/read major game archives, run GPU resolves, load 1280x720 render targets/textures, poll XInput, write to XMA registers, and enter visible frontend boot.
- The latest run is still experimental and may exit with native `0xC0000005` after reaching the first frontend screens.

## Runtime Bring-Up Notes

- SDK local changes currently map low guest memory above the protected zero page so early low-address reads do not become host AVs.
- SDK indirect function dispatch now logs missing targets with register state.
- Null and data-space indirect callbacks return through a stub instead of crashing on optional callback slots.
- Skate-specific mid-asm hooks guard known bad early bring-up paths:
  - unreadable hash bucket lookup returns `null`
  - non-writable list clear ranges are skipped
  - unreadable draw command contexts are skipped
  - non-writable draw command writes are skipped

## Manual Codegen Hints

The manifest currently declares these entrypoint function boundaries:

- `0x82B0C658` through `0x82B0C700`
- `0x82EC9BB0` through `0x82EC9BB8`
- `0x8296A510` through `0x8296A518`
- `0x82714CE8` through `0x82714D78`
- `0x829E7658` through `0x829E7660`
- `0x825F0190` through `0x825F01B0`
- `0x82654D98` through `0x82654DE0`
- `0x82663110` through `0x82663158`
- `0x82CDE398` through `0x82CDE3C0`
- `0x82CDE3E8` through `0x82CDE428`
- `0x82E48608` through `0x82E48640`
- `0x82E48640` through `0x82E48678`
- `0x82E57610` through `0x82E57628`

## Build Notes

Run from a Visual Studio x64 developer environment with the installed SDK `bin` directory on `PATH`:

```powershell
rexglue codegen skate3rexglue_manifest.toml
cmake --build --preset win-amd64-release
```

Launch smoke test:

```powershell
.\out\build\win-amd64-release\skate3rexglue.exe --protect_zero=false --game_data_root "C:\Users\HelmXGaming\Documents\GitHub\Skate-3-Recomp-PC\game" --log_verbose --log_noisy --log_high_frequency_kernel_calls
```
