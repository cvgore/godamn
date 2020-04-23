#include "Store.h"

namespace Godamn
{
	void& Store::operator[](std::string key)
	{
		return m_store.at(key);
	}
}
