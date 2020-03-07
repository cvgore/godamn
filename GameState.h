#pragma once
#include "Player.h"

namespace Godamn
{
	/**
	 * Holds information about current game state
	 */
	class GameState
	{
	public:
		GameState(const GameState&) = delete;
		GameState operator=(const GameState&) = delete;

		void setPaused(bool paused = true);
	private:
		bool m_paused;
		Player m_player;		
	};
}
