#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <string>
#include "Building.h"

namespace Godamn
{
	class LoggingCamp: public Building
	{
		uint16_t m_level;

	public:
		// {64D85950-96D7-4822-BDBF-69B3025AE277}
		inline static constexpr GUID entity_id ={
			0x64d85950, 0x96d7, 0x4822, { 0xbd, 0xbf, 0x69, 0xb3, 0x2, 0x5a, 0xe2, 0x77 }
		};

	};
}