#include "Store.h"

#include "Utils.h"
#include "../Entities/Tiles/Buildings/Temple.h"
#include "../Structs/EntityConfig.h"

// Here we define some helper macros for easier config management

#define KVPAIR(key, value) std::pair<std::string, void*>(key, static_cast<void*>(value))
#define GVPAIR(key, value) KVPAIR(guid_to_string(key), value)
#define CONFIGURE_ENTITY(entityClass) m_store.insert(std::pair<std::string, void*>(guid_to_string(##entityClass::getEntityId()),static_cast<void*>(__new EntityConfig {
#define END_CONFIGURING(entityClass) })));

namespace Godamn
{
	Store::Store()
	{
		// ReSharper fks up indentation due to macros, so disabling it right now
		// @formatter:off
		
		CONFIGURE_ENTITY(Temple)
			.requirements = {
				.res = {
					.faith = 0,
					.stone = 10,
					.wood = 10
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
		
		// @formatter:on
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
