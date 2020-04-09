#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>
#include "Player.h"
#include "TiledMap.h"

namespace Godamn
{
	/**
	 * Holds information about current game state, keeps also all entities in one place
	 */
	class GameState : public sf::Drawable, public sf::Transformable
	{
	public:
		GameState(sf::RenderWindow& renderer);
		GameState(const GameState&) = delete;
		GameState& operator=(const GameState&) = delete;
		~GameState();
		void setPaused(bool paused = true);
		Player* getPlayer() const;
		TiledMap* getMap() const;
		void handleEvent(sf::Event ev);
		
	private:
		bool m_paused;
		Player* m_player;
		TiledMap* m_map;
		sf::RenderWindow& m_renderer;
		std::vector<Entity* > m_entites;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
