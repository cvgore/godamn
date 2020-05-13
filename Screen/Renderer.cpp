#include "Renderer.h"
#include "../Entities/Entity.h"

namespace Godamn
{
	void Renderer::beforeDraw(Entity& object) const
	{
		object.beforeDraw(*this);
	}

	void Renderer::afterDraw(Entity& object) const
	{
		object.beforeDraw(*this);
	}
}