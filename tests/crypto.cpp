#include <doctest/doctest.h>
#include "Utils/Crypto.cpp"

TEST_CASE("it generates random numbers")
{
	CHECK_NOTHROW(Godamn::Crypto::getRandomNumber());

	SUBCASE("generates from given range")
	{
		CHECK(Godamn::Crypto::getRandomNumber(1, 1) == 1);

		CHECK(Godamn::Crypto::getRandomNumber(0) == 0);
	}

	SUBCASE("generates from given negative range")
	{
		CHECK(Godamn::Crypto::getRandomNumber(-1, -1) == -1);
	}
}
