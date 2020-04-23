#pragma once

#include "Container.h"

namespace Godamn
{
	class Object
	{
	public:
		Object() = default;
		static Container& getContainer();
	};
}
