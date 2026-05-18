@echo off
setlocal

pushd "%~dp0" >nul

if not exist "%CD%\generated\ppc\ppc_recomp_shared.h" (
    echo [setup-recomp] Generated PPC output was not found.
    echo [setup-recomp] Run tools\run_recomp.bat first, then run setup_recomp.bat again.
    popd >nul
    exit /b 1
)

echo [setup-recomp] Configuring recomp-enabled Skate3Launcher with Visual Studio 2022...
cmake --preset windows-msvc-recomp-release
if errorlevel 1 goto :fail

echo [setup-recomp] Building recomp-enabled Release launcher...
cmake --build --preset msvc-recomp-release --target Skate3Launcher
if errorlevel 1 goto :fail

echo.
echo [setup-recomp] Done.
echo [setup-recomp] Launcher: %CD%\build-recomp\bin\Release\Skate3Launcher.exe
echo.
echo Press PLAY to enter the generated PPC runtime path.
popd >nul
exit /b 0

:fail
echo.
echo [setup-recomp] Failed. Check the CMake/MSBuild output above.
popd >nul
exit /b 1
