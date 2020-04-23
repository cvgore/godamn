#include "Tile.h"
#include "../../Events/Event.h"
#include "../../Utils/Utils.h"

namespace Godamn
{
	Tile::Tile(const sf::FloatRect& rect, const TileEnum type)
		: Entity(rect), m_type(type), m_vertexOutdated(true)
	{
	}

	TileEnum Tile::getType() const
	{
		return m_type;
	}

	void Tile::setType(TileEnum type)
	{
		m_type = type;
	}

	bool Tile::isOutdated()
	{
		return m_vertexOutdated;
	}

	void Tile::onMouseClick(Event& ev)
	{
		m_type = TileEnum::VOID2;
		m_vertexOutdated = true;
	}

	void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
	}
}
