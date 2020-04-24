#include "Store.h"

#include "Utils.h"
#include "../Entities/Tiles/Buildings/Temple.h"
#include "../Structs/EntityConfig.h"

#define KVPAIR(key,value) std::pair<std::string, void*>(key,static_cast<void*>(__new value))
#define GVPAIR(key,value) KVPAIR(guid_to_string(key),value)

namespace Godamn
{
	Store::Store()
	{
		m_store.insert(GVPAIR(Temple::getEntityId(), EntityConfig{
			.requirements = {
				.res.wood = 10;
				.res.stone = 10;
				.res.faith = 0;
				.people = 5;
			}
			.produces = {
				.res.faith = 5;
				.res.wood = 0;
				.res.stone = 0;
				.people = 0;
			}
			.workers = 1;
		}));
	}

	void* Store::operator[](std::string key)
	{
		return m_store.at(key);
	}

	void* Store::operator[](GUID key)
	{
		return (*this)[guid_to_string(key)];
	}
}
