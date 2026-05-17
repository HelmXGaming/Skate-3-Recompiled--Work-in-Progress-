project(Skate3RecompLib CXX)

set(SKATE3_RECOMP_PPC_DIR "${CMAKE_SOURCE_DIR}/generated/ppc")
set(SKATE3_RECOMP_SHARED_HEADER "${SKATE3_RECOMP_PPC_DIR}/ppc_recomp_shared.h")
set(SKATE3_RECOMP_CONFIG_HEADER "${SKATE3_RECOMP_PPC_DIR}/ppc_config.h")
set(SKATE3_RECOMP_CONTEXT_HEADER "${SKATE3_RECOMP_PPC_DIR}/ppc_context.h")
set(SKATE3_RECOMP_MAPPING_SOURCE "${SKATE3_RECOMP_PPC_DIR}/ppc_func_mapping.cpp")

if (NOT EXISTS "${SKATE3_RECOMP_SHARED_HEADER}")
    message(FATAL_ERROR "Generated PPC output is missing. Run tools/run_recomp.bat first.")
endif()

file(GLOB SKATE3_RECOMP_PPC_SOURCES CONFIGURE_DEPENDS
    "${SKATE3_RECOMP_PPC_DIR}/ppc_recomp.*.cpp"
)

add_library(Skate3RecompLib STATIC
    "${SKATE3_RECOMP_CONFIG_HEADER}"
    "${SKATE3_RECOMP_CONTEXT_HEADER}"
    "${SKATE3_RECOMP_MAPPING_SOURCE}"
    "${SKATE3_RECOMP_SHARED_HEADER}"
    ${SKATE3_RECOMP_PPC_SOURCES}
)

target_include_directories(Skate3RecompLib PUBLIC
    "${CMAKE_CURRENT_SOURCE_DIR}/include"
    "${SKATE3_RECOMP_PPC_DIR}"
)

target_include_directories(Skate3RecompLib PRIVATE "${CMAKE_SOURCE_DIR}/third_party/XenonRecomp/thirdparty/simde")

target_compile_options(Skate3RecompLib PRIVATE
    $<$<CXX_COMPILER_ID:MSVC>:/bigobj>
    $<$<CXX_COMPILER_ID:MSVC>:/MP4>
    $<$<CXX_COMPILER_ID:MSVC>:/FI${CMAKE_CURRENT_SOURCE_DIR}/include/skate3_recomp_msvc_compat.h>
)

target_precompile_headers(Skate3RecompLib PUBLIC
    "$<$<CXX_COMPILER_ID:MSVC>:${CMAKE_CURRENT_SOURCE_DIR}/include/skate3_recomp_msvc_compat.h>"
    "${SKATE3_RECOMP_SHARED_HEADER}"
)
