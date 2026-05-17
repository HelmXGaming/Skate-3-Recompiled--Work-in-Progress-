cmake_minimum_required(VERSION 3.20)
project(Skate3Recomp CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

option(SKATE3_ENABLE_RECOMP_LIB "Build generated Skate 3 PPC recompilation output" OFF)

add_subdirectory(launcher)
add_subdirectory(runtime)

if (SKATE3_ENABLE_RECOMP_LIB)
  add_subdirectory(Skate3RecompLib)
endif()

# If you later pull XenonRecomp headers:
# include_directories(third_party/XenonRecomp/XenonUtils)
