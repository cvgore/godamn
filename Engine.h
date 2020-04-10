#pragma once

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics.hpp>
#include "TiledMap.h"
#include "GameState.h"
#include "Player.h"

namespace Godamn
{
	class Engine : sf::NonCopyable, public sf::Drawable, public sf::Transformable
	{
	public:
		Engine();
		~Engine();
		void runChecks();
		void initialize();
		int spawn();
		TiledMap* getMap() const;

	private:
		sf::Font m_mainFont;
		sf::Font m_altFont;
		sf::RenderWindow* m_renderer;
		GameState* m_state;
		TiledMap* m_map;
		std::vector<Entity*> m_entities;

		sf::Vector2f translateEventPosition(const sf::Event& event);
		void propagateEvent(const sf::Event& event);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
