@echo off
setlocal

pushd "%~dp0" >nul

echo [setup] Configuring Skate3Recomp with Visual Studio 2022...
cmake --preset windows-msvc-release
if errorlevel 1 goto :fail

echo [setup] Building Release launcher...
cmake --build --preset msvc-release
if errorlevel 1 goto :fail

echo.
echo [setup] Done.
echo [setup] Launcher: %CD%\build-msvc\bin\Release\Skate3Launcher.exe
echo.
echo Place an extracted Skate 3 dump in "%CD%\game" with default.xex, or put Skate3.iso in that folder.
popd >nul
exit /b 0

:fail
echo.
echo [setup] Failed. Check the CMake/MSBuild output above.
popd >nul
exit /b 1
