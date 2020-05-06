#include "ScreenObject.h"
#include "Renderer.h"

namespace Godamn
{
	void ScreenObject::afterDraw(const Renderer& renderer)
	{
		renderer.afterDraw(*this);
	}

	void ScreenObject::beforeDraw(const Renderer& renderer)
	{
		renderer.beforeDraw(*this);
	}
}
