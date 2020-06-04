#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <string>
#include "../Tile.h"
#include "../../../Structs/EntityConfig.h"

namespace Godamn
{
	enum class BuildingStateEnum
	{
		OFF,
		ON,
		IN_BUILDING
	};

	class Building : public Tile
	{
		BuildingStateEnum m_state;
		uint16_t m_buildingProgress;
		// todo: ceny drewna i kamienia do ustalenia oraz ilość osób potrzebnych do budowy
		// todo: oraz wymaganą liczbę pracowników

	public:
		inline static constexpr EntityID entity_id = 0x0025;

		Building(const sf::FloatRect& rect);
		virtual ~Building() = default;
		BuildingStateEnum getState();
		void setState(BuildingStateEnum state);
		uint16_t getBuildingProgress();
		void setBuildingProgress(uint16_t progress);
		EntityConfig getEntityConfig();
	};
}
