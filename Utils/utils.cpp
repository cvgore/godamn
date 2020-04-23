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

std::string guid_to_string(GUID guid)
{
	std::stringstream stream;

	auto* const data5 = (guid.Data4 + 2);

	stream << std::hex << std::right << std::setfill('0')
	<< std::setw(8) << guid.Data1
	<< '-' << std::setw(4) << guid.Data2
	<< '-' << std::setw(4) << guid.Data3
	<< '-' << std::setw(2) << (0xFF & guid.Data4[0]) << std::setw(2) << (0xFF & guid.Data4[1])
	<< '-';

	for (uint8_t i = 0; i < 6; ++i)
	{
		stream << std::setw(2) << (0xFF & data5[i]);
	}

	return stream.str();
}
