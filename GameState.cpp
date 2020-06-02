#include "GameState.h"
#include "Engine.h"
#include "Foundation/Container.h"
#include "Scenery/Scene.h"
#include "Scenery/SceneryManager.h"
#include "Entities/Tiles/TileEnum.h"
#include "Entities/Tiles/Buildings/Temple.h"
#include "Entities/Tiles/Buildings/LoggingCamp.h"
#include "Entities/Tiles/Buildings/Mine.h"
#include "Config/EntityConfigStore.h"

#include <algorithm>

namespace Godamn
{
	GameState::GameState(): m_paused(false), m_resources({ 0, 0, 0 })
	{
		auto engine = getContainer().getEngine();
		auto cfgStore = getContainer().getEntityConfigStore();

		engine->listenTimer(1 * 1000, [&, this](uint64_t elapsed, auto delTimer) -> void {
			auto scene = getContainer().getSceneryManager()->getActiveScene();
			auto& mapEnt = *scene->findEntityByGuid(TiledMap::getEntityId());
			auto map = static_cast<TiledMap*>(mapEnt.get());

			uint16_t temples = map->countTilesOfType(TileEnum::Grass_Temple);
			uint16_t lumbers = map->countTilesOfType(TileEnum::Grass_Lumber);
			uint16_t mines = map->countTilesOfType(TileEnum::Grass_Miner);

			m_resources.faith += temples * cfgStore->get(Temple::getEntityId()).produces.res.faith;
			m_resources.wood += lumbers * cfgStore->get(LoggingCamp::getEntityId()).produces.res.wood;
			m_resources.stone += mines * cfgStore->get(Mine::getEntityId()).produces.res.stone;
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
}
