#pragma once

#include "Foundation/Object.h"
#include "Structs/Resources.h"

namespace Godamn
{
	/**
	 * @class
	 *
	 * @brief Holds information about current game state (centralized store)
	 */
	class GameState : public Object
	{
		bool m_paused;
		Resources m_resources;

	public:
		GameState();
		GameState(const GameState&) = delete;
		GameState& operator=(const GameState&) = delete;

		void setPaused(bool paused = true);
		Resources& getResources();
	};
}
