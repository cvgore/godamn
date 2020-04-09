#pragma once

#include <SFML/Window/Event.hpp>

namespace Godamn
{
	class GameState;
	
	class Event
	{
	public:
		Event(GameState& gameState, const sf::Event& originalEvent);
		const GameState* getGameState();
		const sf::Event& getOriginalEvent() const;
		
	private:
		GameState* m_gameState;
		const sf::Event& m_originalEvent;
	};
}
