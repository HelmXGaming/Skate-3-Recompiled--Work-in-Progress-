#include "win_dialogs.h"
#include <iostream>
#include <windows.h>
void ShowErrorDialog(const std::string& message) {
	std::cerr << "[ERROR] " << message << std::endl;
	MessageBoxA(nullptr, message.c_str(), "Skate 3 Recomp Launcher", MB_OK | MB_ICONERROR);
}
