add_library(runtime STATIC
  boot/game_boot.cpp
  boot/recomp_bridge.cpp
  hal/fs.cpp
  hal/mem.cpp
  hal/sys.cpp
  ${CMAKE_SOURCE_DIR}/third_party/XenonRecomp/thirdparty/tiny-AES-c/aes.c
  ${CMAKE_SOURCE_DIR}/third_party/XenonRecomp/thirdparty/libmspack/libmspack/mspack/lzxd.c
)

target_include_directories(runtime PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

target_include_directories(runtime PRIVATE
  ${CMAKE_SOURCE_DIR}/third_party/XenonRecomp/thirdparty/tiny-AES-c
  ${CMAKE_SOURCE_DIR}/third_party/XenonRecomp/thirdparty/libmspack/libmspack/mspack
  ${CMAKE_SOURCE_DIR}/third_party/XenonRecomp/thirdparty/TinySHA1
)

target_compile_definitions(runtime PRIVATE NOMINMAX)

if (SKATE3_ENABLE_RECOMP_LIB)
  target_compile_definitions(runtime PUBLIC SKATE3_HAS_RECOMP_LIB=1)
  target_include_directories(runtime PRIVATE
    ${CMAKE_SOURCE_DIR}/Skate3RecompLib/include
    ${CMAKE_SOURCE_DIR}/generated/ppc
    ${CMAKE_SOURCE_DIR}/third_party/XenonRecomp/thirdparty/simde
  )
endif()
