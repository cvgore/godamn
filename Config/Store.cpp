#include "Store.h"

#include "../Entities/Tiles/Buildings/Chapel.h"
#include "../Entities/Tiles/Buildings/LoggingCamp.h"
#include "../Entities/Tiles/Buildings/Mine.h"
#include "../Entities/Tiles/Buildings/Temple.h"
#include "../Structs/EntityConfig.h"
#include "../Utils/Utils.h"

// Here we define some helper macros for easier config management

#define KVPAIR(key, value) std::pair<std::string, void*>(key, static_cast<void*>(value))
#define GVPAIR(key, value) KVPAIR(guid_to_string(key), value)
#define CONFIGURE_ENTITY(entityClass) m_store.insert(std::pair<std::string, void*>(guid_to_string(##entityClass::getEntityId()),static_cast<void*>(__new EntityConfig {
#define END_CONFIGURING(entityClass) \
	})));

namespace Godamn
{
	Store::Store() {

		// ReSharper fks up indentation due to macros, so disabling it right now
		// @formatter:off
		// clang-format off

		CONFIGURE_ENTITY(Temple)
			.requirements = {
				.res = {
					.faith = 0,
					.wood = 10,
					.stone = 10
				},
				.people = 1
			},
			.produces = {
				.res = {
					.faith = 1,
					.wood = 0,
					.stone = 0
				}
			},
			.workers = 5
		END_CONFIGURING(Temple)

			CONFIGURE_ENTITY(Chapel)
			.requirements = {
				.res = {
					.faith = 0,
					.wood = 5,
					.stone = 3
				},
				.people = 1
		},
			.produces = {
				.res = {
					.faith = 0,
					.wood = 0,
					.stone = 0
				}
		},
			.workers = 1
			END_CONFIGURING(Chapel)

			CONFIGURE_ENTITY(LoggingCamp)
			.requirements = {
				.res = {
					.faith = 0,
					.wood = 3,
					.stone = 1
				},
				.people = 3
		},
			.produces = {
				.res = {
					.faith = 0,
					.wood = 10,
					.stone = 0
				}
		},
			.workers = 5
			END_CONFIGURING(LoggingCamp)

			CONFIGURE_ENTITY(Mine)
			.requirements = {
				.res = {
					.faith = 0,
					.wood = 1,
					.stone = 3
				},
				.people = 3
		},
			.produces = {
				.res = {
					.faith = 0,
					.wood = 0,
					.stone = 10
				}
		},
			.workers = 5
			END_CONFIGURING(Mine)

		// @formatter:on
		// clang-format on
	}

	Store::~Store()
	{
		for (auto& pair : m_store)
		{
			delete static_cast<EntityConfig*>(pair.second);
		}
	}

	void* Store::get(const std::string key)
	{
		return m_store.at(key);
	}

	void* Store::get(const GUID key)
	{
		return get(guid_to_string(key));
	}

	void* Store::operator[](const std::string key)
	{
		return get(key);
	}

	void* Store::operator[](const GUID key)
	{
		return get(key);
	}
}

#undef CONFIGURE_ENTITY
#undef END_CONFIGURING
#undef GVPAIR
#undef KVPAIR
