#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RectangleShape.hpp>
#include <vector>
#include "Player.h"

namespace Godamn
{
	/**
	 * Holds information about current game state
	 */
	class GameState : public sf::Drawable, public sf::Transformable
	{
	public:
		GameState(Player& player);
		GameState(const GameState&) = delete;
		GameState& operator=(const GameState&) = delete;
		~GameState();
		void setPaused(bool paused = true);
	private:
		bool m_paused;
		Player& m_player;
		std::vector<sf::Drawable*> m_drawables;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
