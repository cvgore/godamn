#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
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

		void setPaused(bool paused = true);
	private:
		bool m_paused;
		Player& m_player;

		void draw(sf::RenderTarget& target, sf::RenderStates states) const override;
	};
}
