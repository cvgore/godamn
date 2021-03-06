#include "Container.h"
#include "../Config/EntityConfigStore.h"
#include "../Scenery/SceneryManager.h"

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

	void Container::setSceneryManager(SceneryManager* manager)
	{
		m_sceneryManager.reset(manager);
	}

	std::shared_ptr<SceneryManager> Container::getSceneryManager() const
	{
		return m_sceneryManager;
	}

	void Container::setGameState(GameState* state)
	{
		m_state.reset(state);
	}

	std::shared_ptr<GameState> Container::getGameState() const
	{
		return m_state;
	}
}
