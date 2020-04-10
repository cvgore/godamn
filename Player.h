#pragma once

#include <string>

#include "Entity.h"

namespace Godamn
{
	class Player : public Entity
	{
	public:

	private:
		uint16_t m_power = 0;
		
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
