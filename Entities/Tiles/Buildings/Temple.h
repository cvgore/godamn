#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <string>
#include "Building.h"

namespace Godamn
{

	class Temple : public Building {

		uint16_t m_level;

	public:
		uint16_t getRange() const;
		sf::Rect <uint16_t> getRectRange() const;

	};

}
