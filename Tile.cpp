#include "Tile.h"
#include "Event.h"

namespace Godamn
{
	Tile::Tile()
	{
	}

	TileEnum Tile::getType() const
	{
		return this->m_type;
	}

	void Tile::onMouseClick(Event& ev)
	{
		this->m_type = TileEnum::VOID2;
	}

	const sf::Vector2u Tile::getRelativePos()
	{
		return sf::Vector2u(0, 0);
	}

	void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
	}
}
