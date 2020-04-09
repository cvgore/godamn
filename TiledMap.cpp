#include "TiledMap.h"
#include "Utils.h"
#include "Event.h"

namespace Godamn
{
	TiledMap::TiledMap(): m_verticesOutdated(true)
	{
		// resize the vertex array to fit the level size
		this->m_vertices.setPrimitiveType(sf::Quads);
	}

	bool TiledMap::loadTileset(const std::string& tilesetPath, sf::Vector2<uint8_t> tileSize)
	{
		if (!this->m_tileset.loadFromFile(tilesetPath))
		{
			DEBUG("Cannot load main tileset");

			return false;
		}

		this->m_tileSize = tileSize;

		return true;
	}

	void TiledMap::setTilesConfig(std::vector<Tile>& tilesConfig)
	{
		this->m_tiles = tilesConfig;
		this->m_verticesOutdated = true;
	}

	void TiledMap::setRenderSize(const sf::Vector2<uint8_t> renderSize)
	{
		this->m_renderSize = renderSize;
	}

	void TiledMap::updateIfOutdated()
	{
		if (this->m_verticesOutdated)
		{
			this->redraw();
		}
	}

	void TiledMap::onMouseClick(Event& ev)
	{
		const auto posX = ev.getOriginalEvent().mouseButton.x;
		const auto posY = ev.getOriginalEvent().mouseButton.y;
		
		for (size_t i = 0; i < this->m_vertices.getVertexCount(); ++i)
		{
			const auto * vertex = &this->m_vertices[i];
			
			printf("Tap pos [%d, %d] Vertex pos [%f, %f]\n", posX, posY, vertex->position.x, vertex->position.y);
		}
	}

	const sf::Vector2u TiledMap::getRelativePos()
	{
		return sf::Vector2u(0,0);
	}

	void TiledMap::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// apply the transform
		states.transform *= this->getTransform();

		// apply the tileset texture
		states.texture = &this->m_tileset;

		// draw the vertex array
		target.draw(this->m_vertices, states);
	}

	void TiledMap::redraw()
	{
		this->m_vertices.resize(this->m_renderSize.x * this->m_renderSize.y * 4);

		// populate the vertex array, with one quad per tile
		for (uint16_t i = 0; i < this->m_renderSize.x; ++i)
		{
			for (uint16_t j = 0; j < this->m_renderSize.y; ++j)
			{
				// get the current tile enum
				//const TileEnum tileCfg = this->m_tiles[i + j * this->m_renderSize.x].getType();
				const TileEnum tileCfg = TileEnum::VOID;

				// find its position in the tileset texture
				const uint8_t size = this->m_tileset.getSize().x / this->m_tileSize.x;
				const uint8_t tileX = tileCfg % size;
				const uint8_t tileY = tileCfg / size;

				// get a pointer to the current tile's quad
				sf::Vertex* quad = &this->m_vertices[(i + j * this->m_renderSize.x) * 4];

				// define its 4 corners
				quad[0].position = sf::Vector2f(i * this->m_tileSize.x, j * this->m_tileSize.y);
				quad[1].position = sf::Vector2f((i + 1) * this->m_tileSize.x, j * this->m_tileSize.y);
				quad[2].position = sf::Vector2f((i + 1) * this->m_tileSize.x, (j + 1) * this->m_tileSize.y);
				quad[3].position = sf::Vector2f(i * this->m_tileSize.x, (j + 1) * this->m_tileSize.y);

				// define its 4 texture coordinates
				quad[0].texCoords = sf::Vector2f(tileX * this->m_tileSize.x, tileY * this->m_tileSize.y);
				quad[1].texCoords = sf::Vector2f((tileX + 1) * this->m_tileSize.x, tileY * this->m_tileSize.y);
				quad[2].texCoords = sf::Vector2f((tileX + 1) * this->m_tileSize.x, (tileY + 1) * this->m_tileSize.y);
				quad[3].texCoords = sf::Vector2f(tileX * this->m_tileSize.x, (tileY + 1) * this->m_tileSize.y);
			}
		}

		this->m_verticesOutdated = false;
	}
}
