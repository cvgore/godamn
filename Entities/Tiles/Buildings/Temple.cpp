#include "Temple.h"

namespace Godamn
{
	Temple::Temple(const sf::FloatRect& rect): Building(rect)
	{
	}

	uint16_t Temple::getRange() const
	{
		switch (m_level)
		{
			case 1:
				return 1;
			default:
			case 2:
				return 2;
		}
	}

	sf::Rect<uint16_t> Temple::getRectRange() const
	{
		// todo
		return sf::Rect<uint16_t>();
	}
}
