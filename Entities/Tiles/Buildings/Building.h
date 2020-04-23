#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <string>
#include "../Tile.h"

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
		// todo: ceny drewna i kamienia do ustalenia oraz iloœæ osób potrzebnych do budowy
		// todo: oraz wymagan¹ liczbê pracowników 

	public:
		// {E0DEB3EF-E55C-4088-A91F-3105FF191FC8}
		inline static constexpr GUID entity_id = {
			0xe0deb3ef, 0xe55c, 0x4088, {0xa9, 0x1f, 0x31, 0x5, 0xff, 0x19, 0x1f, 0xc8}
		};

		Building(const sf::FloatRect& rect);
		virtual ~Building() = default;
		BuildingStateEnum getState();
		void setState(BuildingStateEnum state);
		uint16_t getBuildingProgress();
		void setBuildingProgress(uint16_t progress);
	};
}
