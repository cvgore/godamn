#include "Renderer.h"
#include "ScreenObject.h"

namespace Godamn
{
	void Renderer::beforeDraw(ScreenObject& object) const
	{
		object.beforeDraw(*this);
	}

	void Renderer::afterDraw(ScreenObject& object) const
	{
		object.beforeDraw(*this);
	}
}