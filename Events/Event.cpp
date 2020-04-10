#include "Event.h"

using EventType = sf::Event::EventType;

namespace Godamn
{
	Event::Event(Engine& engine, const sf::Event& originalEvent, sf::Vector2f& pos)
		: m_engine(engine), m_originalEvent(originalEvent), m_pos(pos)
	{
	}

	Engine& Event::getEngine()
	{
		return this->m_engine;
	}

	const sf::Event& Event::getOriginalEvent()
	{
		return this->m_originalEvent;
	}

	const sf::Vector2f& Event::getPos()
	{
		return this->m_pos;
	}

	sf::Vector2f Event::getRelativePos(const sf::FloatRect& rect)
	{
		return sf::Vector2f(this->m_pos.x - rect.left, this->m_pos.y - rect.top);
	}

	sf::Vector2f Event::getRelativePos(const Entity& ent)
	{
		return this->getRelativePos(ent.getRect());
	}

	bool Event::isMouseEvent() const
	{
		switch (this->m_originalEvent.type)
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
