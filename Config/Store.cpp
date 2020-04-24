#include "Store.h"

namespace Godamn
{
	Store::Store()
	{
		m_store.insert()
	}

	void& Store::operator[](std::string key)
	{
		return m_store.at(key);
	}

	void& Store::operator[](GUID key)
	{
		
	}
}
