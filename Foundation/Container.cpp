#include "Container.h"
#include "../Config/EntityConfigStore.h"
#include "../Engine.h"

namespace Godamn
{
	Container::Container(): m_engine(nullptr), m_entityStore(nullptr)
	{}

	Container& Container::getInstance()
	{
		static Container instance;

		return instance;
	}

	void Container::dispose()
	{
		// todo - might remove
		// no longer needed due to usage of smart pointers
	}

	std::shared_ptr<Engine> Container::getEngine() const
	{
		return m_engine;
	}

	void Container::setEngine(Engine* engine)
	{
		m_engine.reset(engine);
	}

	std::shared_ptr<EntityConfigStore> Container::getEntityConfigStore() const
	{
		return m_entityStore;
	}

	void Container::setEntityConfigStore(EntityConfigStore* store)
	{
		m_entityStore.reset(store);
	}
}
