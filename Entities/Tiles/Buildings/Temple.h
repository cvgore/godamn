#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <string>
#include "Building.h"

namespace Godamn
{
	class Temple : public Building
	{
		uint16_t m_level;

	public:
		inline static constexpr EntityID entity_id = 0x0029;
		
		Temple(const sf::FloatRect& rect);
		uint16_t getRange() const;
		sf::Rect<uint16_t> getRectRange() const;
	};
}
