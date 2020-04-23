#pragma once

#include "Container.h"

namespace Godamn
{
	class Object
	{
		static Container* m_container;
	public:
		Object() = default;
		static Container* getContainer();
		static void setContainer(Container* container);
	};
}
