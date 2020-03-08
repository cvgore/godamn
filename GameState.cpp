#include "GameState.h"
 
namespace Godamn
{
	GameState::GameState(Player& player) : m_paused(false), m_player(player)
	{
		auto hud = new sf::RectangleShape(sf::Vector2f(800.f, 100.f));
		
		hud->setFillColor(sf::Color::Blue);
		hud->setPosition(0.f, 500.f);

		this->m_drawables.push_back(hud);
	}

	GameState::~GameState()
	{
		for (Drawable* drawable : this->m_drawables)
		{
			delete drawable;
		}
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
		// const uint16_t size = this->m_drawables.size();
		//
		// for (uint16_t i = 0; i < size; i++)
		// {
		// 	target.draw(this->m_drawables[i]);
		// }
		//
		for (Drawable* const drawable : this->m_drawables)
		{
			target.draw(*drawable);
		}
	}
}
