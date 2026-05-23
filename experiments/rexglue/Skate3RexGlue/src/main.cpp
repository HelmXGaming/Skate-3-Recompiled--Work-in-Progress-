// skate3rexglue - ReXGlue Recompiled Project

#ifdef _WIN32
#ifndef NOMINMAX
#define NOMINMAX
#endif
#include <windows.h>

#include <cstdio>
#endif

#include "generated/default/skate3rexglue_init.h"

#include "skate3rexglue_app.h"

#ifdef _WIN32
namespace {

LONG WINAPI Skate3UnhandledExceptionFilter(EXCEPTION_POINTERS* exception) {
  HMODULE module = GetModuleHandleA(nullptr);
  auto base = reinterpret_cast<unsigned long long>(module);
  auto address = reinterpret_cast<unsigned long long>(exception->ExceptionRecord->ExceptionAddress);

  FILE* file = nullptr;
  if (fopen_s(&file, "skate3rexglue_crash.txt", "a") == 0 && file) {
    std::fprintf(file, "Exception: 0x%08lX\n",
                 exception->ExceptionRecord->ExceptionCode);
    std::fprintf(file, "Address: 0x%llX\n", address);
    std::fprintf(file, "ModuleBase: 0x%llX\n", base);
    std::fprintf(file, "ModuleOffset: 0x%llX\n", address - base);
    std::fprintf(file, "----------\n");
    std::fclose(file);
  }

  return EXCEPTION_CONTINUE_SEARCH;
}

struct CrashFilterInstaller {
  CrashFilterInstaller() { SetUnhandledExceptionFilter(Skate3UnhandledExceptionFilter); }
};

CrashFilterInstaller g_crash_filter_installer;

}  // namespace
#endif

REX_DEFINE_APP(skate3rexglue, Skate3rexglueApp::Create)
