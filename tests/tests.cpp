#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN

#include <doctest/doctest.h>
#include "Utils/Crypto.h"
#include "Utils/Utils.h"
#include "Scenery/SceneryManager.h"
#include "Scenery/SceneryException.h"

using namespace Godamn;

#pragma warning(disable:6319)

/* === Crypto === */

TEST_CASE("it generates random numbers")
{
	CHECK_NOTHROW(Crypto::getRandomNumber());

	SUBCASE("generates from given range")
	{
		CHECK(Crypto::getRandomNumber(1, 1) == 1);

		CHECK(Crypto::getRandomNumber(0) == 0);
	}

	SUBCASE("generates from given negative range")
	{
		CHECK(Crypto::getRandomNumber(-1, -1) == -1);
	}
}

/* === Utils === */

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

/* === Scenes === */

TEST_CASE("SceneryManager works as expected")
{
	auto mgr = SceneryManager();

	SUBCASE("scene management works as expected")
	{
		SUBCASE("scene creation works")
		{
			auto* scene = mgr.newScene().get();

			REQUIRE(scene != nullptr);
		}

		SUBCASE("existing scene can be found")
		{
			auto scene = mgr.newScene();

			CHECK(mgr.contains(scene) == true);
			CHECK(mgr.indexOf(scene) > -1);
			CHECK(mgr.find(scene) != mgr.cend());
		}

		SUBCASE("non-existing scene cannot be found")
		{
			std::shared_ptr<Scene> scene(__new Scene);

			CHECK(mgr.contains(scene) == false);
			CHECK(mgr.indexOf(scene) == -1);
			CHECK(mgr.find(scene) == mgr.cend());
		}

		SUBCASE("existing scene can be set active")
		{
			auto scene = mgr.newScene();

			mgr.setActiveScene(scene);

			CHECK(mgr.getActiveScene() == scene);
		}

		SUBCASE("non-existing scene cannot be set active")
		{
			std::shared_ptr<Scene> scene(__new Scene);

			CHECK_THROWS_AS(mgr.setActiveScene(scene), SceneryException);

			CHECK(mgr.getActiveScene() == nullptr);
		}

		SUBCASE("active scene can be unset")
		{
			mgr.setActiveScene(nullptr);

			CHECK(mgr.getActiveScene() == nullptr);
		}

		SUBCASE("existing, non-active scene can be deleted")
		{
			auto scene = mgr.newScene();

			mgr.removeScene(scene);

			CHECK(mgr.getScenes().size() == 0);
		}

		SUBCASE("non-existing scene can be deleted")
		{
			std::shared_ptr<Scene> scene(__new Scene);

			CHECK_THROWS_AS(mgr.removeScene(scene), SceneryException);
		}

		SUBCASE("existing, active scene cannot be deleted")
		{
			std::shared_ptr<Scene> scene(__new Scene);

			CHECK_THROWS_AS(mgr.setActiveScene(scene), SceneryException);
		}
	}
}
