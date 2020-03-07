#include "Map.h"

bool Godamn::Map::load(
	const std::string& tilesetPath,
	sf::Vector2u tileSize,
	const uint8_t* tiles,
	uint16_t width,
	uint16_t height
)
{
	// load the tileset texture
	if (!m_tileset.loadFromFile(tilesetPath))
		return false;

	// resize the vertex array to fit the level size
	m_vertices.setPrimitiveType(sf::Quads);
	m_vertices.resize(width * height * 4);

	// populate the vertex array, with one quad per tile
	for (uint16_t i = 0; i < width; ++i)
		for (uint16_t j = 0; j < height; ++j)
		{
			// get the current tile number
			const int tileNumber = tiles[i + j * width];

			// find its position in the tileset texture
			const uint16_t size = m_tileset.getSize().x / tileSize.x;
			const int tileU = tileNumber % size;
			const int tileV = tileNumber / size;

			// get a pointer to the current tile's quad
			sf::Vertex* quad = &m_vertices[(i + j * width) * 4];

			// define its 4 corners
			quad[0].position = sf::Vector2f(i * tileSize.x, j * tileSize.y);
			quad[1].position = sf::Vector2f((i + 1) * tileSize.x, j * tileSize.y);
			quad[2].position = sf::Vector2f((i + 1) * tileSize.x, (j + 1) * tileSize.y);
			quad[3].position = sf::Vector2f(i * tileSize.x, (j + 1) * tileSize.y);

			// define its 4 texture coordinates
			quad[0].texCoords = sf::Vector2f(tileU * tileSize.x, tileV * tileSize.y);
			quad[1].texCoords = sf::Vector2f((tileU + 1) * tileSize.x, tileV * tileSize.y);
			quad[2].texCoords = sf::Vector2f((tileU + 1) * tileSize.x, (tileV + 1) * tileSize.y);
			quad[3].texCoords = sf::Vector2f(tileU * tileSize.x, (tileV + 1) * tileSize.y);
		}

	return true;
}

void Godamn::Map::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	// apply the transform
	states.transform *= getTransform();

	// apply the tileset texture
	states.texture = &m_tileset;

	// draw the vertex array
	target.draw(m_vertices, states);
}
