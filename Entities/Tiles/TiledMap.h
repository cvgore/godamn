#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <string>
#include <vector>
#include "Tile.h"

namespace Godamn
{
	class TiledMap : public Entity, public IEvMouseClick
	{
	public:
		TiledMap(sf::FloatRect& rect);
		bool loadTileset(const std::string& tilesetPath, sf::Vector2<uint8_t> tileSize);
		void setTilesConfig(std::vector<Tile>& tilesConfig);
		void setRenderSize(sf::Vector2<uint8_t> renderSize);
		void updateIfOutdated();
		void onMouseClick(Event& ev) override;
		
	private:
		sf::Texture m_tileset;
		sf::VertexArray m_vertices;
		sf::Vector2<uint8_t> m_renderSize;
		sf::Vector2<uint8_t> m_tileSize;
		std::vector<Tile> m_tiles;
		bool m_verticesOutdated;

		void redraw();
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
