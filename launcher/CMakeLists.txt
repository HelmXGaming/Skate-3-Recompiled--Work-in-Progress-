add_executable(Skate3Launcher
  src/main.cpp
  src/asset_locator.cpp
  src/validator.cpp
  src/importer.cpp
  src/iso_utils.cpp
  src/win_dialogs.cpp
  src/resources.rc
)
set_target_properties(Skate3Launcher PROPERTIES
  WIN32_EXECUTABLE TRUE
  VS_DEBUGGER_WORKING_DIRECTORY "${CMAKE_SOURCE_DIR}"
)

target_include_directories(Skate3Launcher PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/src)
target_link_libraries(Skate3Launcher PRIVATE runtime comdlg32 gdiplus shell32 ole32)

if (TARGET Skate3RecompLib)
  target_link_libraries(Skate3Launcher PRIVATE Skate3RecompLib)
endif()
