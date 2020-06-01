#include <stdexcept>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <ctime>
#include <cstdio>

#include "Utils.h"

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
