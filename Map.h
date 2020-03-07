#pragma once

#include <SFML/Graphics.hpp>

namespace Godamn
{
	class Map : public sf::Drawable, public sf::Transformable
	{
	public:

		bool load(
			const std::string& tilesetPath,
			sf::Vector2u tileSize,
			const uint8_t* tiles,
			uint16_t width,
			uint16_t height
		);

	private:

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;

		sf::VertexArray m_vertices;
		sf::Texture m_tileset;
	};
}
