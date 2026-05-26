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

void WriteExceptionRecord(FILE* file, const char* label, EXCEPTION_POINTERS* exception) {
  HMODULE module = GetModuleHandleA(nullptr);
  auto base = reinterpret_cast<unsigned long long>(module);
  auto address = reinterpret_cast<unsigned long long>(exception->ExceptionRecord->ExceptionAddress);

  std::fprintf(file, "%s\n", label);
  std::fprintf(file, "Exception: 0x%08lX\n", exception->ExceptionRecord->ExceptionCode);
  std::fprintf(file, "Address: 0x%llX\n", address);
  std::fprintf(file, "ModuleBase: 0x%llX\n", base);
  std::fprintf(file, "ModuleOffset: 0x%llX\n", address - base);

  if (exception->ExceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION &&
      exception->ExceptionRecord->NumberParameters >= 2) {
    const auto mode = exception->ExceptionRecord->ExceptionInformation[0];
    const auto fault_address = exception->ExceptionRecord->ExceptionInformation[1];
    std::fprintf(file, "Access: %s at 0x%llX\n",
                 mode == 0 ? "read" : mode == 1 ? "write" : "execute",
                 static_cast<unsigned long long>(fault_address));
  }

#if defined(_M_X64) || defined(__x86_64__)
  const CONTEXT* ctx = exception->ContextRecord;
  std::fprintf(file,
               "RIP=0x%llX RSP=0x%llX RBP=0x%llX\n",
               static_cast<unsigned long long>(ctx->Rip),
               static_cast<unsigned long long>(ctx->Rsp),
               static_cast<unsigned long long>(ctx->Rbp));
  std::fprintf(file,
               "RAX=0x%llX RBX=0x%llX RCX=0x%llX RDX=0x%llX\n",
               static_cast<unsigned long long>(ctx->Rax),
               static_cast<unsigned long long>(ctx->Rbx),
               static_cast<unsigned long long>(ctx->Rcx),
               static_cast<unsigned long long>(ctx->Rdx));
  std::fprintf(file,
               "RSI=0x%llX RDI=0x%llX R8=0x%llX R9=0x%llX\n",
               static_cast<unsigned long long>(ctx->Rsi),
               static_cast<unsigned long long>(ctx->Rdi),
               static_cast<unsigned long long>(ctx->R8),
               static_cast<unsigned long long>(ctx->R9));
  std::fprintf(file,
               "R10=0x%llX R11=0x%llX R12=0x%llX\n",
               static_cast<unsigned long long>(ctx->R10),
               static_cast<unsigned long long>(ctx->R11),
               static_cast<unsigned long long>(ctx->R12));
#endif

  std::fprintf(file, "----------\n");
}

LONG WINAPI Skate3VectoredExceptionHandler(EXCEPTION_POINTERS* exception) {
  static LONG written = 0;
  if (InterlockedIncrement(&written) <= 16) {
    FILE* file = nullptr;
    if (fopen_s(&file, "skate3rexglue_first_chance.txt", "a") == 0 && file) {
      WriteExceptionRecord(file, "First chance exception", exception);
      std::fclose(file);
    }
  }

  return EXCEPTION_CONTINUE_SEARCH;
}

LONG WINAPI Skate3UnhandledExceptionFilter(EXCEPTION_POINTERS* exception) {
  FILE* file = nullptr;
  if (fopen_s(&file, "skate3rexglue_crash.txt", "a") == 0 && file) {
    WriteExceptionRecord(file, "Unhandled exception", exception);
    std::fclose(file);
  }

  return EXCEPTION_CONTINUE_SEARCH;
}

struct CrashFilterInstaller {
  CrashFilterInstaller() {
    AddVectoredExceptionHandler(1, Skate3VectoredExceptionHandler);
    SetUnhandledExceptionFilter(Skate3UnhandledExceptionFilter);
  }
};

CrashFilterInstaller g_crash_filter_installer;

}  // namespace
#endif

REX_DEFINE_APP(skate3rexglue, Skate3rexglueApp::Create)
