#pragma once
#include <string>
namespace hal::sys {
	void init_logging();
	void log(const std::string& s);
}
