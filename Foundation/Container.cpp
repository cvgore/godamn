#include "Container.h"
#include "../Config/Store.h"

namespace Godamn
{
	std::shared_ptr<Store> Container::getStore() const
	{
		return m_store;
	}

	void Container::setStore(Store* store)
	{
		m_store.reset(store);
	}

	Container& Container::getInstance()
	{
		static Container instance;

		return instance;
	}

	void Container::dispose()
	{
		m_engine.reset();
		m_store.reset();
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
