#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <string>
#include "Entity.h"

namespace Godamn
{

	enum class BuildingStateEnum {
		OFF, ON, IN_BUILDING
	};

	class Building : public Entity {
		BuildingStateEnum m_state;

		// todo: ceny drewna i kamienia do ustalenia oraz iloœæ osób potrzebnych do budowy
		// oraz wymagan¹ liczbê pracowników 

	public:
		Building(const sf::FloatRect& rect);
		virtual ~Building() = default;
		BuildingStateEnum getState();
		void setState(BuildingStateEnum state);
	};

}