#include "GameState.h"
 
namespace Godamn
{
	GameState::GameState(sf::RenderWindow& renderer) : m_paused(false), m_renderer(renderer)
	{
		this->m_map = new Godamn::TiledMap;
		this->m_player = new Godamn::Player;
		
		auto hud = new sf::RectangleShape(sf::Vector2f(800.f, 100.f));
		
		hud->setFillColor(sf::Color::Blue);
		hud->setPosition(0.f, 500.f);

		this->m_drawables.push_back(hud);
		this->m_drawables.push_back(this->m_map);
	}

	GameState::~GameState()
	{
		for (Drawable* drawable : this->m_drawables)
		{
			delete drawable;
		}

		delete this->m_player;
	}

	void GameState::setPaused(const bool paused)
	{
		this->m_paused = paused;
	}

	Player* GameState::getPlayer() const
	{
		return this->m_player;
	}

	TiledMap* GameState::getMap() const
	{
		return this->m_map;
	}

	void GameState::dispatch(sf::Event ev)
	{
		if (ev.type == sf::Event::Closed)
		{
			this->m_renderer.close();
		}	
	}

	void GameState::draw(sf::RenderTarget& target, sf::RenderStates states) const
	{
		this->m_map->updateIfOutdated();
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
