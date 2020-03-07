#include "Utils.h"

void debug_print(const char* file, const int line, const char* content)
{
	const auto basename = strrchr(file, DIRSEP);
	static const auto FMT = "[%d/%02d/%02d %02d:%02d:%02d] (%s:%d) %s\n";

	const auto time = std::time(NULL);
	// ReSharper disable once CppDeprecatedEntity
	const auto tm = std::localtime(&time); // NOLINT(clang-diagnostic-deprecated-declarations)

	printf_s(
		FMT,
		1900 + tm->tm_year,
		tm->tm_mon + 1,
		tm->tm_mday,
		tm->tm_hour,
		tm->tm_min,
		tm->tm_sec,
		basename + 1,
		line,
		content
	);
}
