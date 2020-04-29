#include "Container.h"

namespace Godamn
{
	Container& Container::getInstance()
	{
		static Container instance;

		return instance;
	}

	void Container::dispose()
	{		
		this->m_engine.reset();
	}

	std::shared_ptr<Engine> Container::getEngine() const
	{
		return m_engine;
	}

	void Container::setEngine(Engine* engine)
	{
		m_engine.reset(engine);
	}

	Container::Container() : m_engine(NULL)
	{
	}
}
