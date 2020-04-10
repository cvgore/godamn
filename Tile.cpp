#include "Tile.h"
#include "Event.h"

namespace Godamn
{
	Tile::Tile(const sf::FloatRect& rect): Entity(rect)
	{
	}

	TileEnum Tile::getType() const
	{
		return this->m_type;
	}

	void Tile::setType(TileEnum type)
	{
		this->m_type = type;
	}

	bool Tile::isOutdated()
	{
		return this->m_vertexOutdated;
	}

	void Tile::onMouseClick(Event& ev)
	{
		this->m_type = TileEnum::VOID2;
		this->m_vertexOutdated = true;
	}

	void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
	}
}
