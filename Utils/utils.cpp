#include "Utils.h"

// template <typename... Vargs>
void debug_print(const char* file, const int line, const char* a)
{
	const auto basename = strrchr(file, DIRSEP);
	static auto fmt = "[%d/%02d/%02d %02d:%02d:%02d] (%s:%d) %s\n";

	auto time = std::time(NULL);
	auto tm = std::localtime(&time);

	printf_s(fmt, 1900 + tm->tm_year, tm->tm_mon + 1, tm->tm_mday, tm->tm_hour, tm->tm_min, tm->tm_sec, basename + 1,
	         line, a);
}
