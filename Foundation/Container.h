#pragma once
#include "../Engine.h"

namespace Godamn
{
	class Container
	{
		Engine* m_engine;
	public:
		Container(Engine* engine);
		Engine* getEngine()const;
	};
}
