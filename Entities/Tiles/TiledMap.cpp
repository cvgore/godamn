#include "TiledMap.h"
#include "../../Utils/Utils.h"
#include "../../Events/Event.h"

namespace Godamn
{
	TiledMap::TiledMap(sf::FloatRect& rect): Entity(rect), m_verticesOutdated(true)
	{
		// resize the vertex array to fit the level size
		m_vertices.setPrimitiveType(sf::Quads);
	}

	bool TiledMap::loadTileset(const std::string& tilesetPath, sf::Vector2<uint8_t> tileSize)
	{
		if (!m_tileset.loadFromFile(tilesetPath))
		{
			DEBUG("Cannot load main tileset");

			return false;
		}

		m_tileSize = tileSize;

		return true;
	}

	void TiledMap::setTilesConfig(std::vector<Tile>& tilesConfig)
	{
		m_tiles = tilesConfig;
		m_verticesOutdated = true;
	}

	void TiledMap::setRenderSize(const sf::Vector2<uint8_t> renderSize)
	{
		m_renderSize = renderSize;
		m_verticesOutdated = true;

		m_tiles.clear();

		const uint32_t tilesCount = m_renderSize.x * m_renderSize.y;

		for (uint32_t i = 0; i < tilesCount; ++i)
		{
			m_tiles.emplace_back(Tile(sf::FloatRect(0.f, 0.f, 0.f, 0.f)));
		}
	}

	void TiledMap::updateIfOutdated()
	{
		if (m_verticesOutdated)
		{
			redraw();
		}
	}

	void TiledMap::onMouseButtonClick(Event& ev)
	{
		const auto relPos = ev.getRelativePos(*this);

		const uint8_t tileX = floor(relPos.x / static_cast<float>(m_tileSize.x));
		const uint8_t tileY = floor(relPos.y / static_cast<float>(m_tileSize.y));

		m_tiles[tileX + tileY * m_renderSize.x].onMouseButtonClick(ev);
		// TODO: redraw only single tile, not whole map (!performance)
		m_verticesOutdated = true;
	}

	void TiledMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// apply the transform
		states.transform *= getTransform();

		// apply the tileset texture
		states.texture = &m_tileset;

		// draw the vertex array
		target.draw(m_vertices, states);
	}

	void TiledMap::redraw()
	{
		m_vertices.resize(m_renderSize.x * m_renderSize.y * 4);

		// populate the vertex array, with one quad per tile
		for (uint16_t i = 0; i < m_renderSize.x; ++i)
		{
			for (uint16_t j = 0; j < m_renderSize.y; ++j)
			{
				// get the current tile enum
				const auto tileCfg = static_cast<uint8_t>(m_tiles[i + j * m_renderSize.x].getType());

				// find its position in the tileset texture
				const uint8_t size = m_tileset.getSize().x / m_tileSize.x;
				const uint8_t tileX = tileCfg % size;
				const uint8_t tileY = tileCfg / size;

				// get a pointer to the current tile's quad
				auto* quad = &m_vertices[(i + j * m_renderSize.x) * 4];

				// define its 4 corners
				quad[0].position = sf::Vector2f(i * m_tileSize.x, j * m_tileSize.y);
				quad[1].position = sf::Vector2f((i + 1) * m_tileSize.x, j * m_tileSize.y);
				quad[2].position = sf::Vector2f((i + 1) * m_tileSize.x, (j + 1) * m_tileSize.y);
				quad[3].position = sf::Vector2f(i * m_tileSize.x, (j + 1) * m_tileSize.y);

				// define its 4 texture coordinates
				quad[0].texCoords = sf::Vector2f(tileX * m_tileSize.x, tileY * m_tileSize.y);
				quad[1].texCoords = sf::Vector2f((tileX + 1) * m_tileSize.x, tileY * m_tileSize.y);
				quad[2].texCoords = sf::Vector2f((tileX + 1) * m_tileSize.x, (tileY + 1) * m_tileSize.y);
				quad[3].texCoords = sf::Vector2f(tileX * m_tileSize.x, (tileY + 1) * m_tileSize.y);
			}
		}

		m_verticesOutdated = false;
	}
}
