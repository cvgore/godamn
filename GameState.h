#pragma once
namespace Godamn
{
	/**
	 * @class
	 * 
	 * @brief Holds information about current game state (centralized store)
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
