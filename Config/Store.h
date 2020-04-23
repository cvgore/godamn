#pragma once

#include <map>
#include <string>

#include "../Foundation/Object.h"

namespace Godamn
{
	class Store : Object
	{
		std::map<std::string, void&> m_store;

	public:
		void& operator[](std::string key);
	};
}
