#pragma once

#include <SFML/Graphics.hpp>
#include <SFML/System/NonCopyable.hpp>
#include "Entities/Tiles/TiledMap.h"
#include "Foundation/Object.h"
#include "GameState.h"
#include "Screen/Renderer.h"
#include "Screen/ScreenObject.h"

namespace Godamn
{
	/**
	 * @class Engine
	 * 
	 * @brief Main class holding and combining everything within game, manages event loop
	 */
	class Engine : sf::NonCopyable, public Object, public Renderer
	{
		sf::Font m_mainFont;
		sf::Font m_altFont;
		std::shared_ptr<sf::RenderWindow> m_renderer;
		GameState* m_state;

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

	private:
		/**
		 * @brief Returns common event occurence position
		 *
		 * @remarks Built-in sf::Event has many event types and each has own mouse struct, so translator is required 
		 */
		static sf::Vector2f translateEventPosition(const sf::Event& event);
		/**
		 * @brief Propagates event from event loop to concrete entities
		 */
		void propagateEvent(const sf::Event& event);
	};
}
