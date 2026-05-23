# skate3rexglue - ReXGlue Recompiled Project
#
# SDK boilerplate lives in generated/rexglue.cmake.

cmake_minimum_required(VERSION 3.25)
project(skate3rexglue LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(generated/rexglue.cmake)

# Sources
set(SKATE3REXGLUE_SOURCES
    src/main.cpp
    src/skate3_hooks.cpp
)

if(WIN32)
    add_executable(skate3rexglue WIN32 ${SKATE3REXGLUE_SOURCES})
else()
    add_executable(skate3rexglue ${SKATE3REXGLUE_SOURCES})
endif()

rexglue_setup_target(skate3rexglue)

if(WIN32)
    target_link_options(skate3rexglue PRIVATE
        LINKER:/DEBUG:FULL
        LINKER:/MAP:$<TARGET_FILE_DIR:skate3rexglue>/skate3rexglue.map
        LINKER:/PDB:$<TARGET_FILE_DIR:skate3rexglue>/skate3rexglue.pdb
    )
endif()
