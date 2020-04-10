#pragma once

#include <SFML/Graphics/RenderWindow.hpp>

namespace Godamn
{
	/**
	 * Holds information about current game state, keeps also all entities in one place
	 */
	class GameState
	{
	public:
		GameState();
		GameState(const GameState&) = delete;
		GameState& operator=(const GameState&) = delete;
		void setPaused(bool paused = true);

	private:
		bool m_paused;
	};
}
