#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <string>
#include "Building.h"

namespace Godamn
{
	class LoggingCamp : public Building
	{
		uint16_t m_level;

	public:
		inline static constexpr EntityID entity_id = 0x0027;
	};
}
