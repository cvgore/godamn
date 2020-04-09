#include "GameState.h"
#include "Event.h";

namespace Godamn
{
	GameState::GameState(sf::RenderWindow& renderer) : m_paused(false), m_renderer(renderer)
	{
		this->m_map = new TiledMap;
		this->m_player = new Player;

		auto hud = new sf::RectangleShape(sf::Vector2f(800.f, 100.f));
		//
		hud->setFillColor(sf::Color::Blue);
		hud->setPosition(0.f, 500.f);

		// this->m_entites.push_back(hud);
		
		this->m_entites.push_back(this->m_map);
	}

	GameState::~GameState()
	{
		for (Entity* entity : this->m_entites)
		{
			delete entity;
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

	void GameState::handleEvent(sf::Event ev)
	{
		if (ev.type == sf::Event::Closed)
		{
			this->m_renderer.close();
		}
		else
		{
			// this->m_renderer.
			
			Event wrapper(*this, ev);
			
			for (Entity* entity : this->m_entites)
			{
				// if ()
				
				entity->onEvent(wrapper);
			}
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
		for (Entity* drawable : this->m_entites)
		{
			target.draw(*drawable);
		}
	}
}
