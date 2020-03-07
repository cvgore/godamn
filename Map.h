#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <string>
#include <vector>

namespace Godamn
{
	class TiledMap : public sf::Drawable, public sf::Transformable
	{
	public:
		TiledMap();
		bool loadTileset(const std::string& tilesetPath, sf::Vector2<uint8_t> tileSize);
		void setTilesConfig(std::vector<uint8_t>& tilesConfig);
		void setRenderSize(sf::Vector2<uint8_t> renderSize);
		void updateIfOutdated();

	private:
		sf::Texture m_tileset;
		sf::VertexArray m_vertices;
		sf::Vector2<uint8_t> m_renderSize;
		sf::Vector2<uint8_t> m_tileSize;
		std::vector<uint8_t> m_tilesConfig;
		bool m_verticesOutdated = true;

		void redraw();
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
