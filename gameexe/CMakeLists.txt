add_executable(Skate3Game
  src/main.cpp
)

target_include_directories(Skate3Game PRIVATE ${CMAKE_SOURCE_DIR}/runtime)
target_link_libraries(Skate3Game PRIVATE runtime)

# Run from the repo root so relative paths make sense
set_target_properties(Skate3Game PROPERTIES
  VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)
