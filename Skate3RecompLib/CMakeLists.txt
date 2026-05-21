project(Skate3RecompLib CXX)

set(SKATE3_RECOMP_PPC_DIR "${CMAKE_SOURCE_DIR}/generated/ppc")
set(SKATE3_RECOMP_SHARED_HEADER "${SKATE3_RECOMP_PPC_DIR}/ppc_recomp_shared.h")
set(SKATE3_RECOMP_CONFIG_HEADER "${SKATE3_RECOMP_PPC_DIR}/ppc_config.h")
set(SKATE3_RECOMP_CONTEXT_HEADER "${SKATE3_RECOMP_PPC_DIR}/ppc_context.h")
set(SKATE3_RECOMP_MAPPING_SOURCE "${SKATE3_RECOMP_PPC_DIR}/ppc_func_mapping.cpp")
set(SKATE3_RECOMP_EPILOGUE_SHIMS "${CMAKE_CURRENT_SOURCE_DIR}/src/skate3_recomp_epilogue_shims.cpp")
set(SKATE3_RECOMP_IMPORT_STUBS "${CMAKE_CURRENT_BINARY_DIR}/skate3_recomp_import_stubs.cpp")

if (NOT EXISTS "${SKATE3_RECOMP_SHARED_HEADER}")
    message(FATAL_ERROR "Generated PPC output is missing. Run tools/run_recomp.bat first.")
endif()

file(GLOB SKATE3_RECOMP_PPC_SOURCES CONFIGURE_DEPENDS
    "${SKATE3_RECOMP_PPC_DIR}/ppc_recomp.*.cpp"
)

set(SKATE3_RECOMP_SHARED_EPILOGUES
    82F274E4 82F274E8 82F274EC 82F274F0
    82F274F4 82F274F8 82F274FC 82F27500
    82F27504 82F27508 82F2750C 82F27510
    82F27514 82F27518 82F2751C
)

foreach(SKATE3_RECOMP_PPC_SOURCE IN LISTS SKATE3_RECOMP_PPC_SOURCES)
    file(READ "${SKATE3_RECOMP_PPC_SOURCE}" SKATE3_RECOMP_PPC_CONTENTS)
    set(SKATE3_RECOMP_PPC_PATCHED "${SKATE3_RECOMP_PPC_CONTENTS}")
    foreach(SKATE3_RECOMP_EPILOGUE IN LISTS SKATE3_RECOMP_SHARED_EPILOGUES)
        string(REPLACE
            "\t// ERROR ${SKATE3_RECOMP_EPILOGUE}\n\treturn;"
            "\tsub_${SKATE3_RECOMP_EPILOGUE}(ctx, base);\n\treturn;"
            SKATE3_RECOMP_PPC_PATCHED
            "${SKATE3_RECOMP_PPC_PATCHED}"
        )
    endforeach()
    if (NOT SKATE3_RECOMP_PPC_PATCHED STREQUAL SKATE3_RECOMP_PPC_CONTENTS)
        file(WRITE "${SKATE3_RECOMP_PPC_SOURCE}" "${SKATE3_RECOMP_PPC_PATCHED}")
    endif()
endforeach()

file(STRINGS "${SKATE3_RECOMP_SHARED_HEADER}" SKATE3_RECOMP_IMPORT_DECLS REGEX "^PPC_EXTERN_FUNC\\(__imp__.*\\);$")
file(WRITE "${SKATE3_RECOMP_IMPORT_STUBS}"
    "#include \"ppc_recomp_shared.h\"\n\n"
    "extern \"C\" void Skate3RecordImportStub(const char* name);\n\n"
    "#define SKATE3_IMPORT_STUB(name) void name(PPCContext& ctx, uint8_t*) { Skate3RecordImportStub(#name); ctx.r3.u64 = 0; }\n\n"
)
foreach(SKATE3_RECOMP_IMPORT_DECL IN LISTS SKATE3_RECOMP_IMPORT_DECLS)
    string(REGEX REPLACE "^PPC_EXTERN_FUNC\\(([^\\)]*)\\);$" "\\1" SKATE3_RECOMP_IMPORT_NAME "${SKATE3_RECOMP_IMPORT_DECL}")
    if (SKATE3_RECOMP_IMPORT_NAME STREQUAL "__imp__NtAllocateVirtualMemory")
        file(APPEND "${SKATE3_RECOMP_IMPORT_STUBS}"
            "namespace runtime { namespace boot { void Skate3ImportNtAllocateVirtualMemory(PPCContext& ctx, uint8_t* base); } }\n"
            "void __imp__NtAllocateVirtualMemory(PPCContext& ctx, uint8_t* base) { Skate3RecordImportStub(\"__imp__NtAllocateVirtualMemory\"); runtime::boot::Skate3ImportNtAllocateVirtualMemory(ctx, base); }\n"
        )
    elseif (SKATE3_RECOMP_IMPORT_NAME STREQUAL "__imp__NtFreeVirtualMemory")
        file(APPEND "${SKATE3_RECOMP_IMPORT_STUBS}"
            "namespace runtime { namespace boot { void Skate3ImportNtFreeVirtualMemory(PPCContext& ctx, uint8_t* base); } }\n"
            "void __imp__NtFreeVirtualMemory(PPCContext& ctx, uint8_t* base) { Skate3RecordImportStub(\"__imp__NtFreeVirtualMemory\"); runtime::boot::Skate3ImportNtFreeVirtualMemory(ctx, base); }\n"
        )
    elseif (SKATE3_RECOMP_IMPORT_NAME STREQUAL "__imp__RtlInitializeCriticalSection")
        file(APPEND "${SKATE3_RECOMP_IMPORT_STUBS}"
            "namespace runtime { namespace boot { void Skate3ImportRtlInitializeCriticalSection(PPCContext& ctx, uint8_t* base); } }\n"
            "void __imp__RtlInitializeCriticalSection(PPCContext& ctx, uint8_t* base) { Skate3RecordImportStub(\"__imp__RtlInitializeCriticalSection\"); runtime::boot::Skate3ImportRtlInitializeCriticalSection(ctx, base); }\n"
        )
    elseif (SKATE3_RECOMP_IMPORT_NAME STREQUAL "__imp__RtlInitializeCriticalSectionAndSpinCount")
        file(APPEND "${SKATE3_RECOMP_IMPORT_STUBS}"
            "namespace runtime { namespace boot { void Skate3ImportRtlInitializeCriticalSection(PPCContext& ctx, uint8_t* base); } }\n"
            "void __imp__RtlInitializeCriticalSectionAndSpinCount(PPCContext& ctx, uint8_t* base) { Skate3RecordImportStub(\"__imp__RtlInitializeCriticalSectionAndSpinCount\"); runtime::boot::Skate3ImportRtlInitializeCriticalSection(ctx, base); }\n"
        )
    elseif (SKATE3_RECOMP_IMPORT_NAME STREQUAL "__imp__RtlEnterCriticalSection")
        file(APPEND "${SKATE3_RECOMP_IMPORT_STUBS}"
            "namespace runtime { namespace boot { void Skate3ImportRtlEnterCriticalSection(PPCContext& ctx, uint8_t* base); } }\n"
            "void __imp__RtlEnterCriticalSection(PPCContext& ctx, uint8_t* base) { Skate3RecordImportStub(\"__imp__RtlEnterCriticalSection\"); runtime::boot::Skate3ImportRtlEnterCriticalSection(ctx, base); }\n"
        )
    elseif (SKATE3_RECOMP_IMPORT_NAME STREQUAL "__imp__RtlLeaveCriticalSection")
        file(APPEND "${SKATE3_RECOMP_IMPORT_STUBS}"
            "namespace runtime { namespace boot { void Skate3ImportRtlLeaveCriticalSection(PPCContext& ctx, uint8_t* base); } }\n"
            "void __imp__RtlLeaveCriticalSection(PPCContext& ctx, uint8_t* base) { Skate3RecordImportStub(\"__imp__RtlLeaveCriticalSection\"); runtime::boot::Skate3ImportRtlLeaveCriticalSection(ctx, base); }\n"
        )
    elseif (SKATE3_RECOMP_IMPORT_NAME STREQUAL "__imp__RtlFillMemoryUlong")
        file(APPEND "${SKATE3_RECOMP_IMPORT_STUBS}"
            "namespace runtime { namespace boot { void Skate3ImportRtlFillMemoryUlong(PPCContext& ctx, uint8_t* base); } }\n"
            "void __imp__RtlFillMemoryUlong(PPCContext& ctx, uint8_t* base) { Skate3RecordImportStub(\"__imp__RtlFillMemoryUlong\"); runtime::boot::Skate3ImportRtlFillMemoryUlong(ctx, base); }\n"
        )
    elseif (SKATE3_RECOMP_IMPORT_NAME STREQUAL "__imp__RtlCompareMemoryUlong")
        file(APPEND "${SKATE3_RECOMP_IMPORT_STUBS}"
            "namespace runtime { namespace boot { void Skate3ImportRtlCompareMemoryUlong(PPCContext& ctx, uint8_t* base); } }\n"
            "void __imp__RtlCompareMemoryUlong(PPCContext& ctx, uint8_t* base) { Skate3RecordImportStub(\"__imp__RtlCompareMemoryUlong\"); runtime::boot::Skate3ImportRtlCompareMemoryUlong(ctx, base); }\n"
        )
    else()
        file(APPEND "${SKATE3_RECOMP_IMPORT_STUBS}" "SKATE3_IMPORT_STUB(${SKATE3_RECOMP_IMPORT_NAME})\n")
    endif()
endforeach()

add_library(Skate3RecompLib STATIC
    "${SKATE3_RECOMP_CONFIG_HEADER}"
    "${SKATE3_RECOMP_CONTEXT_HEADER}"
    "${SKATE3_RECOMP_EPILOGUE_SHIMS}"
    "${SKATE3_RECOMP_MAPPING_SOURCE}"
    "${SKATE3_RECOMP_SHARED_HEADER}"
    "${SKATE3_RECOMP_IMPORT_STUBS}"
    ${SKATE3_RECOMP_PPC_SOURCES}
)

target_include_directories(Skate3RecompLib PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${SKATE3_RECOMP_PPC_DIR}"
    "${CMAKE_SOURCE_DIR}/third_party/XenonRecomp/thirdparty/simde"
)

target_compile_options(Skate3RecompLib PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/bigobj>
    $<$<CXX_COMPILER_ID:MSVC>:/MP4>
    $<$<CXX_COMPILER_ID:MSVC>:/Od>
    $<$<CXX_COMPILER_ID:MSVC>:/Ob0>
    $<$<CXX_COMPILER_ID:MSVC>:/FI${CMAKE_CURRENT_SOURCE_DIR}/include/skate3_recomp_msvc_compat.h>
)

target_precompile_headers(Skate3RecompLib PUBLIC
    "$<$<CXX_COMPILER_ID:MSVC>:${CMAKE_CURRENT_SOURCE_DIR}/include/skate3_recomp_msvc_compat.h>"
    "${SKATE3_RECOMP_SHARED_HEADER}"
)
