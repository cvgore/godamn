#pragma once

#include "EntityConfigStore.h"

#include "../Entities/Tiles/Buildings/Chapel.h"
#include "../Entities/Tiles/Buildings/LoggingCamp.h"
#include "../Entities/Tiles/Buildings/Mine.h"
#include "../Entities/Tiles/Buildings/Temple.h"

namespace Godamn
{
	EntityConfigStore::EntityConfigStore(): Store()
	{
		BEGIN_CONFIGURE()

		CONFIGURE_ENTITY(
		Godamn::Temple,
		{ .requirements = { .res = { .faith = 0, .wood = 10, .stone = 10 }, .people = 1 },
		  .produces = { .res = { .faith = 1, .wood = 0, .stone = 0 } },
		  .workers = 5 }),

		CONFIGURE_ENTITY(
		Godamn::Chapel,
		{ .requirements = { .res = { .faith = 0, .wood = 5, .stone = 3 }, .people = 1 },
		  .produces = { .res = { .faith = 0, .wood = 0, .stone = 0 } },
		  .workers = 1 }),

		CONFIGURE_ENTITY(
		Godamn::LoggingCamp,
		{ .requirements = { .res = { .faith = 0, .wood = 3, .stone = 1 }, .people = 3 },
		  .produces = { .res = { .faith = 0, .wood = 10, .stone = 0 } },
		  .workers = 5 }),

		CONFIGURE_ENTITY(
		Godamn::Mine,
		{ .requirements = { .res = { .faith = 0, .wood = 1, .stone = 3 }, .people = 3 },
		  .produces = { .res = { .faith = 0, .wood = 0, .stone = 10 } },
		  .workers = 5 }),

		END_CONFIGURE()
	}
}
