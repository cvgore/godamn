#pragma once

#include <guiddef.h>
#include <map>
#include <string>

#include "../Foundation/Object.h"

namespace Godamn
{
	class Store : public Object
	{
		std::map<std::string, void&> m_store;

	public:
		Store()
		void& operator[](std::string key);
		void& operator[](GUID key);
	};
}
