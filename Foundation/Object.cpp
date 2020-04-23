#include "Object.h"

namespace Godamn
{
	Container* Object::getContainer()
	{
		return m_container;
	}

	void Object::setContainer(Container* container)
	{
		if (m_container != NULL)
		{
			return;
		}

		m_container = container;
	}
}
