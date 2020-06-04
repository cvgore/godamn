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
		Temple,
		{ .requirements = { .res = { .faith = 5, .wood = 20, .stone = 20 }, .people = 1 },
		  .produces = { .res = { .faith = 1, .wood = 0, .stone = 0 } },
		  .workers = 5 }),

		CONFIGURE_ENTITY(
		Chapel,
		{ .requirements = { .res = { .faith = 0, .wood = 10, .stone = 5 }, .people = 1 },
		  .produces = { .res = { .faith = 0, .wood = 0, .stone = 0 } },
		  .workers = 1 }),

		CONFIGURE_ENTITY(
		LoggingCamp,
		{ .requirements = { .res = { .faith = 0, .wood = 3, .stone = 1 }, .people = 3 },
		  .produces = { .res = { .faith = 0, .wood = 1, .stone = 0 } },
		  .workers = 5 }),

		CONFIGURE_ENTITY(
		Mine,
		{ .requirements = { .res = { .faith = 0, .wood = 10, .stone = 5 }, .people = 3 },
		  .produces = { .res = { .faith = 0, .wood = 0, .stone = 1 } },
		  .workers = 5 }),

		END_CONFIGURE()
	}
}
