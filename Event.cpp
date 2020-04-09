#include "Event.h"
#include "GameState.h"

namespace Godamn
{
	Event::Event(GameState& gameState, const sf::Event& originalEvent): m_gameState(&gameState), m_originalEvent(originalEvent)
	{
	}

	const GameState* Event::getGameState()
	{
		return this->m_gameState;
	}

	const sf::Event& Event::getOriginalEvent() const
	{
		return this->m_originalEvent;
	}
}
