#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <string>
#include "Building.h"

namespace Godamn
{
	class Chapel :public Building
	{
		uint16_t m_level;

	public:
		// {53DB42F6-B363-4755-A58F-9D3718F10F9D}
		inline static constexpr GUID entity_id = {
			 0x53db42f6, 0xb363, 0x4755, { 0xa5, 0x8f, 0x9d, 0x37, 0x18, 0xf1, 0xf, 0x9d }
		};

		 uint16_t getRange() const;
	};
}