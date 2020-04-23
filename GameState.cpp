#include "GameState.h"

namespace Godamn
{
	GameState::GameState() : m_paused(false)
	{
	}

	void GameState::setPaused(const bool paused)
	{
		m_paused = paused;
	}
}
