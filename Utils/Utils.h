#pragma once

#include <string>
#include <guiddef.h>
#include <stdexcept>
#include <thread>

#ifdef _WIN32
#define DIRSEP '\\'
#else
#define DIRSEP '/'
#endif

template<typename... Args>
void debug_print(const char* file, const int line, const char* severity, Args... args)
{
	const auto basename = strrchr(file, DIRSEP);
	static const auto FMT = "[%d/%02d/%02d %02d:%02d:%02d] %2s (%s:%d) <thread 0x%llx> ";

	const auto time = std::time(NULL);
#pragma warning(disable:4996)
	const auto tm = std::localtime(&time);
#pragma warning(default:4996)

	printf_s(
	FMT,
	1900 + tm->tm_year,
	tm->tm_mon + 1,
	tm->tm_mday,
	tm->tm_hour,
	tm->tm_min,
	tm->tm_sec,
	severity,
	basename + 1,
	line,
	std::this_thread::get_id()
	);

	printf_s(args...);
	printf_s("\n");
}

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

