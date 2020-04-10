#include "Utils.h"

void debug_print(const char* file, const int line, const char* severity, const char* content)
{
	const auto basename = strrchr(file, DIRSEP);
	static const auto FMT = "[%d/%02d/%02d %02d:%02d:%02d] %2s (%s:%d) %s\n";

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
		content
	);
}
