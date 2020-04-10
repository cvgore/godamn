#pragma once

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics.hpp>
#include "Entities/Tiles/TiledMap.h"
#include "GameState.h"

namespace Godamn
{
	/**
	 * @class Engine
	 * 
	 * @brief Main class holding and combining everything within game, manages event loop
	 */
	class Engine : sf::NonCopyable, public sf::Drawable, public sf::Transformable
	{
	public:
		Engine();
		~Engine();
		/**
		 * @brief Runs initial checks (i.e: if all assets are present)
		 */
		void runChecks();
		/**
		 * @brief Pre loads required assets and initializes renderer
		 */
		void initialize();
		/**
		 * @brief Spawns game engine and enters event loop
		 */
		int spawn();
		/**
		 * @brief Returns TiledMap instance
		 */
		TiledMap* getMap() const;

	private:
		sf::Font m_mainFont;
		sf::Font m_altFont;
		sf::RenderWindow* m_renderer;
		GameState* m_state;
		TiledMap* m_map;
		std::vector<Entity*> m_entities;

		/**
		 *
		 * @brief Returns common event occurence position
		 *
		 * @remarks Built-in sf::Event has many event types and each has own mouse struct, so translator is required 
		 */
		sf::Vector2f translateEventPosition(const sf::Event& event);
		/**
		 * @brief Propagates event from event loop to concrete entities
		 */
		void propagateEvent(const sf::Event& event);
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
