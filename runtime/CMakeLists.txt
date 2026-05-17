add_library(runtime STATIC
  boot/game_boot.cpp
  hal/fs.cpp
  hal/mem.cpp
  hal/sys.cpp
)

target_include_directories(runtime PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
