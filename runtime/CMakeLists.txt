add_library(runtime STATIC
  boot/game_boot.cpp
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
