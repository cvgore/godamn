#include "GameState.h"

namespace Godamn
{
	GameState::GameState(Player& player) : m_paused(false), m_player(player)
	{
	}

	void GameState::setPaused(const bool paused)
	{
		this->m_paused = paused;
	}

	void GameState::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		// // apply the transform
		// states.transform *= this->getTransform();
		//
		// // apply the tileset texture
		// states.texture = &this->m_tileset;
		//
		// // draw the vertex array
		// target.draw(this->m_vertices, states);
	}
}
