cmake_minimum_required(VERSION 3.20)
project(Skate3Recomp CXX)
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_subdirectory(launcher)
add_subdirectory(runtime)

# If you later pull XenonRecomp headers:
# include_directories(third_party/XenonRecomp/XenonUtils)
