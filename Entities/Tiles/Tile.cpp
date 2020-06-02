#include "Tile.h"
#include "../../Events/Event.h"
#include "../../Utils/Utils.h"

namespace Godamn
{
	Tile::Tile(const sf::FloatRect& rect, const TileEnum type)
		: Entity(rect), m_type(type), m_vertexOutdated(true), m_unveiled(false)
	{
	}

	TileEnum Tile::getType() const
	{
		if (!m_unveiled) {
			return TileEnum::Not_Unveiled;
		}

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

	void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// noop
	}

	void Tile::onMouseButtonClick(Event& ev)
	{
		// noop
	}

	bool Tile::isUnveiled() const
	{
		return m_unveiled;
	}

	void Tile::unveil()
	{
		m_unveiled = true;
	}
}
