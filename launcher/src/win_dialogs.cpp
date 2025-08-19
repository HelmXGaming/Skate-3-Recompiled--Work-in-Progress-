#include "win_dialogs.h"
#include <iostream>
void ShowErrorDialog(const std::string& message) {
	std::cerr << "[ERROR] " << message << std::endl;
}
