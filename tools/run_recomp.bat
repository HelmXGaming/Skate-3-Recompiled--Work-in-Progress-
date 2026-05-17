@echo off
setlocal

pushd "%~dp0\.." >nul

set "ROOT=%CD%"
set "XENON_SRC=%ROOT%\third_party\XenonRecomp"
set "XENON_BUILD=%ROOT%\build-xenonrecomp-msvc"
set "ANALYSE_EXE=%XENON_BUILD%\XenonAnalyse\Release\XenonAnalyse.exe"
set "RECOMP_EXE=%XENON_BUILD%\XenonRecomp\Release\XenonRecomp.exe"
set "XEX=%ROOT%\game\default.xex"
set "CONFIG=%ROOT%\Skate3RecompLib\config\skate3.toml"
set "SWITCHES=%ROOT%\Skate3RecompLib\config\skate3_switches.toml"
set "PPC_HEADER=%XENON_SRC%\XenonUtils\ppc_context.h"
set "PATCH=%ROOT%\docs\patches\xenonrecomp-msvc-toolchain.patch"
set "PATCH_APPLIED=0"

if not exist "%XEX%" (
  echo [recomp] Missing %XEX%
  echo [recomp] Put an extracted Skate 3 dump in game\ with default.xex first.
  goto :fail
)

if exist "%PATCH%" (
  git -C "%XENON_SRC%" apply --check "%PATCH%" >nul 2>nul
  if not errorlevel 1 (
    echo [recomp] Applying local MSVC compatibility patch for XenonRecomp...
    git -C "%XENON_SRC%" apply "%PATCH%"
    if errorlevel 1 goto :fail
    set "PATCH_APPLIED=1"
  )
)

echo [recomp] Configuring XenonRecomp tools...
cmake -S "%XENON_SRC%" -B "%XENON_BUILD%" -G "Visual Studio 17 2022" -A x64
if errorlevel 1 goto :fail

echo [recomp] Building XenonAnalyse and XenonRecomp...
cmake --build "%XENON_BUILD%" --config Release --target XenonAnalyse XenonRecomp
if errorlevel 1 goto :fail

if not exist "%ROOT%\generated\analysis" mkdir "%ROOT%\generated\analysis"
if not exist "%ROOT%\generated\ppc" mkdir "%ROOT%\generated\ppc"

echo [recomp] Analysing switch tables...
"%ANALYSE_EXE%" "%XEX%" "%SWITCHES%"
if errorlevel 1 goto :fail

echo [recomp] Recompiling PPC code...
"%RECOMP_EXE%" "%CONFIG%" "%PPC_HEADER%"
if errorlevel 1 goto :fail

echo.
echo [recomp] Done.
echo [recomp] Generated output: %ROOT%\generated\ppc

if "%PATCH_APPLIED%"=="1" (
  echo [recomp] Restoring clean XenonRecomp submodule source...
  git -C "%XENON_SRC%" restore -- XenonUtils\byteswap.h XenonUtils\xex_patcher.cpp
)

popd >nul
exit /b 0

:fail
echo.
echo [recomp] Failed.
if "%PATCH_APPLIED%"=="1" (
  echo [recomp] Restoring clean XenonRecomp submodule source...
  git -C "%XENON_SRC%" restore -- XenonUtils\byteswap.h XenonUtils\xex_patcher.cpp
)
popd >nul
exit /b 1
