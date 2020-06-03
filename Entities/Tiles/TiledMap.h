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
#include "TileEnum.h"

namespace Godamn
{
	class Tile;

	class TiledMap : public Entity, public IEvMouseButtonClick, public IEvMouseOver
	{
		sf::Texture m_tileset;
		sf::VertexArray m_vertices;
		sf::Vector2<uint8_t> m_renderSize;
		sf::Vector2<uint8_t> m_tileSize;
		std::vector<Tile> m_tiles;
		bool m_verticesOutdated;

	public:
		inline static constexpr uint16_t entity_id = 0x0021;

		TiledMap(sf::FloatRect& rect);
		bool loadTileset(const std::string& tilesetPath, sf::Vector2<uint8_t> tileSize);
		void setTilesConfig(std::vector<TileEnum>& tilesConfig);
		void setRenderSize(sf::Vector2<uint8_t> renderSize);
		void updateIfOutdated();
		void onMouseButtonClick(Event& ev) override;
		void onMouseOver(Event &ev) override;
		void unveilTile(sf::Vector2<uint8_t> pos);
		void unveilBase();
		uint16_t countTilesOfType(TileEnum type);

	protected:
		void redraw();
		void beforeDraw(const Renderer& renderer) override;
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
