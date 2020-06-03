#include "Tile.h"
#include "../../Events/Event.h"
#include "../../Utils/Utils.h"
#include "../../Foundation/Container.h"
#include "../../GameState.h"

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
		getContainer().getGameState()->setCurrentlySelectedTile(this);
	}

	bool Tile::isUnveiled() const
	{
		return m_unveiled;
	}

	void Tile::unveil()
	{
		m_unveiled = true;
	}

	std::string Tile::getTypeString() const
	{
		switch (getType())
		{
			case TileEnum::Not_Unveiled:
				return "???";
			case TileEnum::Grass_Stone:
				return "Stone";
			case TileEnum::Grass_Miner:
				return "Mine";
			case TileEnum::Grass_Lumber:
				return "Lumber";
			case TileEnum::Grass_Temple:
				return "Temple";
			case TileEnum::Grass_Forest:
				return "Forest";
			case TileEnum::Grass_Chample:
				return "Chapel";
			case TileEnum::Grass:
				return "Grass";
			default:
				return "Unknown";
		}
	}

	void Tile::onMouseOver(Event& ev)
	{
		getContainer().getGameState()->setCurrentlyHoveredTile(this);
	}
}
