#include "Building.h"
#include "../../../Config/EntityConfigStore.h"
#include "../../../Foundation/Container.h"

namespace Godamn
{
	Building::Building(const sf::FloatRect& rect): Tile(rect)
	{
		m_buildingProgress = 0;
		m_state = BuildingStateEnum::IN_BUILDING;
	}

	BuildingStateEnum Building::getState()
	{
		return m_state;
	}

	void Building::setState(BuildingStateEnum state)
	{
		if (m_state == BuildingStateEnum::IN_BUILDING || state == BuildingStateEnum::IN_BUILDING)
		{
			return;
		}

		m_state = state;
	}

	uint16_t Building::getBuildingProgress()
	{
		return m_buildingProgress;
	}

	void Building::setBuildingProgress(uint16_t progress)
	{
		if (m_state != BuildingStateEnum::IN_BUILDING || progress > 100 || progress <= m_buildingProgress)
		{
			return;
		}

		m_buildingProgress = progress;
	}

	EntityConfig Building::getEntityConfig()
	{
		return getContainer().getEntityConfigStore()->get(getEntityId());
	}
}
