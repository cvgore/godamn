#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <string>
#include "Building.h"

namespace Godamn
{
	class Mine : public Building
	{
		uint16_t m_level;

	public:
		// {0157E010-B827-4E96-84B4-5EA09B95BD65}
		inline static const GUID entity_id = {
			0x157e010, 0xb827, 0x4e96, { 0x84, 0xb4, 0x5e, 0xa0, 0x9b, 0x95, 0xbd, 0x65 }
		};
	};
}