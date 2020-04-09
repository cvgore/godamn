#pragma once

#include <SFML/System/NonCopyable.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include "Utils.h"
#include "TiledMap.h"
#include "GameState.h"
#include "Player.h"

namespace Godamn
{
	class Engine : sf::NonCopyable
	{
	public:
		Engine();
		void runChecks();
		void initialize();
		int spawn();

	private:
		sf::Font m_mainFont;
		sf::Font m_altFont;
		sf::RenderWindow* m_renderer;
		Godamn::GameState* m_state;
	}; 
}
