#pragma once

#include "../Structs/EntityConfig.h"
#include "Store.h"

namespace Godamn
{
	class EntityConfigStore : public Store<EntityConfig>
	{
	public:
		EntityConfigStore();
	};
}