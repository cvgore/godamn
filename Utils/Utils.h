#pragma once

#include <ctime>
#include <cstdio>
#include <cstring>
#include <guiddef.h>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <iomanip>

void debug_print(const char* file, const int line, const char* severity, const char* content);
std::string guid_to_string(GUID guid);

#ifdef _DEBUG
#define DEBUG(...) debug_print(__FILE__, __LINE__, "D", __VA_ARGS__)
#define WARNING(...) debug_print(__FILE__, __LINE__, "W", __VA_ARGS__)
#define PANIC(...) debug_print(__FILE__, __LINE__, "P", __VA_ARGS__); \
	throw std::exception(__VA_ARGS__);
#else
#define DEBUG(...)
#define WARNING(...)
#define PANIC(...) throw std::exception(__VA_ARGS__);  // NOLINT(cppcoreguidelines-macro-usage)
#endif

#ifdef _WIN32
#define DIRSEP '\\'
#else
#define DIRSEP '/'
#endif
