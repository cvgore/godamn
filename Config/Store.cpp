#include "Store.h"

#include "Utils.h"

namespace Godamn
{
	Store::Store()
	{
		// m_store.insert();
	}

	void& Store::operator[](std::string key)
	{
		return m_store.at(key);
	}

	void& Store::operator[](GUID key)
	{
		return (*this)[guid_to_string(key)];
	}
}
