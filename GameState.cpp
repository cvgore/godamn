#include "GameState.h"
#include "Config/EntityConfigStore.h"
#include "Engine.h"
#include "Entities/Tiles/Buildings/LoggingCamp.h"
#include "Entities/Tiles/Buildings/Mine.h"
#include "Entities/Tiles/Buildings/Temple.h"
#include "Entities/Tiles/TileEnum.h"
#include "Foundation/Container.h"
#include "Scenery/Scene.h"
#include "Scenery/SceneryManager.h"

namespace Godamn
{
	GameState::GameState(): m_paused(false), m_resources({ 0, 0, 0 }), m_mode(0), m_currentlyHoveredTile(nullptr), m_currentlySelectedTile(nullptr)
	{
		auto engine = getContainer().getEngine();

		engine->listenEvent(Engine::EngineEvent::Initialized, [this](Engine::RemoveElementCallback removeListener) -> void {
		  	auto engine = getContainer().getEngine();

		  DEBUG("EntId of TiledMap: %X",TiledMap::entity_id);
		  DEBUG("EntId of Entity: %X", Entity::entity_id);

			engine->listenTimer(1 * 1000, [this](uint64_t elapsed, Engine::RemoveElementCallback delTimer) -> void {
			  	static auto cfgStore = getContainer().getEntityConfigStore();
			    auto scene = getContainer().getSceneryManager()->getActiveScene();
				auto mapEntIt = scene->findEntityByEntityId("TiledMap");
			  	auto& mapEnt = *mapEntIt;
				auto map = static_cast<TiledMap*>(mapEnt.get());

				uint16_t temples = map->countTilesOfType(TileEnum::Grass_Temple);
				uint16_t lumbers = map->countTilesOfType(TileEnum::Grass_Lumber);
				uint16_t mines = map->countTilesOfType(TileEnum::Grass_Miner);

				DEBUG("There are currently %d temples, %d lumbers, %d mines unveiled", temples, lumbers, mines);

				auto faithPerTemple = cfgStore->get("Temple").produces.res.faith;
				auto woodPerCamp = cfgStore->get("LoggingCamp").produces.res.wood;
				auto stonePerMine = cfgStore->get("Mine").produces.res.stone;

			  	m_resources.faith += temples * faithPerTemple;
				m_resources.wood += lumbers * woodPerCamp;
				m_resources.stone += mines * stonePerMine;
			});
		});
	}

	void GameState::setPaused(const bool paused)
	{
		m_paused = paused;
	}

	Resources& GameState::getResources()
	{
		return m_resources;
	}

	void GameState::setMode(int mode)
	{
		m_mode = mode;
	}

	int GameState::getMode() const
	{
		return m_mode;
	}

	Tile* GameState::getCurrentlySelectedTile() const
	{
		return m_currentlySelectedTile;
	}

	Tile* GameState::getCurrentlyHoveredTile() const
	{
		return m_currentlyHoveredTile;
	}

	void GameState::setCurrentlySelectedTile(Tile* tile)
	{
		m_currentlySelectedTile = tile;
	}

	void GameState::setCurrentlyHoveredTile(Tile* tile)
	{
		m_currentlyHoveredTile = tile;
	}
}
