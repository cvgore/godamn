#pragma once

#include "Foundation/Object.h"
#include "Structs/Resources.h"
#include "Entities/Tiles/Tile.h"

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
		int m_mode;
		Tile* m_currentlySelectedTile;
		Tile* m_currentlyHoveredTile;
		Resources m_resources;

	public:
		GameState();
		GameState(const GameState&) = delete;
		GameState& operator=(const GameState&) = delete;

		void setPaused(bool paused = true);
		void setMode(int mode);
		int getMode() const;
		Resources& getResources();
		Tile* getCurrentlySelectedTile() const;
		Tile* getCurrentlyHoveredTile() const;
		void setCurrentlySelectedTile(Tile* tile);
		void setCurrentlyHoveredTile(Tile* tile);
	};
}
