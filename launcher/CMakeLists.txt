add_executable(Skate3Launcher
  src/main.cpp
  src/asset_locator.cpp
  src/validator.cpp
  src/importer.cpp
  src/iso_utils.cpp
  src/win_dialogs.cpp
)
set_target_properties(Skate3Launcher PROPERTIES
  VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

target_include_directories(Skate3Launcher PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(Skate3Launcher PRIVATE runtime)
