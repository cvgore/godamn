#include "Object.h"

namespace Godamn
{
	Container& Object::getContainer()
	{
		return Container::getInstance();
	}
}
