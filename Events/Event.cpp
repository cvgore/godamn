#include "Event.h"
#include "../Entities/Entity.h"

using EventType = sf::Event::EventType;

namespace Godamn
{
	Event::Event(const sf::Event& originalEvent, sf::Vector2f& pos)
		: m_originalEvent(originalEvent), m_pos(pos)
	{
	}

	const sf::Event& Event::getOriginalEvent()
	{
		return m_originalEvent;
	}

	const sf::Vector2f& Event::getPos()
	{
		return m_pos;
	}

	sf::Vector2f Event::getRelativePos(const sf::FloatRect& rect)
	{
		return sf::Vector2f(m_pos.x - rect.left, m_pos.y - rect.top);
	}

	sf::Vector2f Event::getRelativePos(const Entity& ent)
	{
		return getRelativePos(ent.getRect());
	}

	bool Event::isMouseEvent() const
	{
		switch (m_originalEvent.type)
		{
			case EventType::MouseButtonReleased:
			case EventType::MouseButtonPressed:
			case EventType::MouseMoved:
			case EventType::MouseWheelScrolled:
				return true;
		}

		return false;
	}
}
