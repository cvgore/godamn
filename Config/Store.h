#pragma once

#include <guiddef.h>
#include <map>
#include <string>

#include "../Foundation/Object.h"

namespace Godamn
{
	class Store : public Object
	{
		std::map<std::string, void*> m_store;

	public:
		Store();
		~Store();
		void* get(std::string key);
		void* get(GUID key);
		void* operator[](std::string key);
		void* operator[](GUID key);
	};
}
