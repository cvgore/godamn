#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include "Utils/Crypto.h"
#include "Utils/Crypto.cpp"

TEST_CASE("it generate random numbers")
{
	CHECK_NOTHROW(Godamn::Crypto::getRandomNumber());
	CHECK(Godamn::Crypto::getRandomNumber(1,1)==1);
	CHECK(Godamn::Crypto::getRandomNumber(-1, -1) == -1);
	CHECK(Godamn::Crypto::getRandomNumber(0) == 0);
}
