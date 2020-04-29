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

	void Tile::onMouseButtonClick(Event& ev)
	{
<<<<<<< HEAD
		m_type = static_cast<TileEnum>((static_cast<int>(m_type) + 1) % 5);
=======
		m_type = static_cast<TileEnum>((static_cast<int>(m_type) + 1) % 10);
>>>>>>> bc658d2c5fcdcfa9a4d69a9bb73ca440dec0b014
		m_vertexOutdated = true;
	}

	void Tile::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
	}
}
