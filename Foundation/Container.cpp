#include "Container.h"

#include "../Utils/Utils.h"

namespace Godamn
{
	Container& Container::getInstance()
	{
		static Container instance;

		return instance;
	}

	Engine* Container::getEngine() const
	{
		return m_engine;
	}

	void Container::setEngine(Engine* engine)
	{
		m_engine = engine;
	}

	Container::Container() : m_engine(NULL)
	{
	}

	Container::~Container()
	{
		DEBUG("Destructing container");
		
		delete m_engine;
	}
}
