#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <sstream>
#include <doctest/doctest.h>
#include "Utils/Utils.cpp"

TEST_CASE("it converts GUID to string correctly")
{
	// {C410A5E2-EE9A-45FE-BEBD-2748F1D65007}
	static const GUID guid = {
		0xc410a5e2, 0xee9a, 0x45fe, {0xbe, 0xbd, 0x27, 0x48, 0xf1, 0xd6, 0x50, 0x7}
	};

	CHECK(guid_to_string(guid) == "c410a5e2-ee9a-45fe-bebd-2748f1d65007");

	SUBCASE("handles well padded zeroes")
	{
		// {00000000-0000-0000-0000-000000000000}
		static const GUID guid = {
			0x0, 0x0, 0x0, {0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0, 0x0}
		};

		CHECK(guid_to_string(guid) == "00000000-0000-0000-0000-000000000000");
	}
}
