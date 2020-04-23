#include "Object.h"

#include "Container.h"

namespace Godamn
{
	Container& Object::getContainer()
	{
		return Container::getInstance();
	}
}
