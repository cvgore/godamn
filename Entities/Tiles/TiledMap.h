#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/Texture.hpp>
#include <SFML/Graphics/VertexArray.hpp>
#include <string>
#include <vector>
#include "../../Events/EventMethodsInterfaces.h"
#include "../Entity.h"

namespace Godamn
{
	class Tile;

	class TiledMap : public Entity, public IEvMouseButtonClick
	{
		sf::Texture m_tileset;
		sf::VertexArray m_vertices;
		sf::Vector2<uint8_t> m_renderSize;
		sf::Vector2<uint8_t> m_tileSize;
		std::vector<Tile> m_tiles;
		bool m_verticesOutdated;

	public:
		// {7381B45C-9619-4E46-888D-9C9C10C935F7}
		inline static constexpr GUID entity_id = {
			0x7381b45c, 0x9619, 0x4e46, {0x88, 0x8d, 0x9c, 0x9c, 0x10, 0xc9, 0x35, 0xf7}
		};

		TiledMap(sf::FloatRect& rect);
		bool loadTileset(const std::string& tilesetPath, sf::Vector2<uint8_t> tileSize);
		void setTilesConfig(std::vector<Tile>& tilesConfig);
		void setRenderSize(sf::Vector2<uint8_t> renderSize);
		void updateIfOutdated();
		void onMouseButtonClick(Event& ev) override;

	protected:
		void redraw();
		void beforeDraw(const Renderer& renderer) override;
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
