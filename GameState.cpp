#include "GameState.h"

namespace Godamn
{
	GameState::GameState() : m_paused(false)
	{
		// auto hud = new sf::RectangleShape(sf::Vector2f(800.f, 100.f));
		
		// hud->setFillColor(sf::Color::Blue);
		// hud->setPosition(0.f, 500.f);

		// this->m_entites.push_back(hud);
		
		// this->m_entites.push_back(this->m_map);
	}

	void GameState::setPaused(const bool paused)
	{
		m_paused = paused;
	}
}
