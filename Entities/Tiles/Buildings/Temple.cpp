#include "Temple.h"

namespace Godamn
{
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
		//todo
		return sf::Rect<uint16_t>();
	}
}
