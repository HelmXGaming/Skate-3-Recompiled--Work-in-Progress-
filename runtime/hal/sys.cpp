#include "sys.h"
#include <iostream>
void hal::sys::init_logging() {}
void hal::sys::log(const std::string& s) { std::cout << s << std::endl; }
