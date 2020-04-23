#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <string>
#include "Building.h"

namespace Godamn
{
	class Temple : public Building
	{
		uint16_t m_level;

	public:
		// {EEA20227-14C3-4F44-9059-D3ADC519ED4C}
		inline static constexpr GUID entity_id = {
			0xeea20227, 0x14c3, 0x4f44, {0x90, 0x59, 0xd3, 0xad, 0xc5, 0x19, 0xed, 0x4c}
		};

		uint16_t getRange() const;
		sf::Rect<uint16_t> getRectRange() const;
	};
}
