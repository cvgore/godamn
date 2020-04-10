#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window/Event.hpp>

#include "Entity.h"

namespace Godamn
{
	class Engine;

	class Event
	{
	public:
		Event(Engine& engine, const sf::Event& originalEvent, sf::Vector2f& pos);
		Engine& getEngine();
		const sf::Event& getOriginalEvent();
		const sf::Vector2f& getPos();
		const sf::Vector2f& getRelativePos(const sf::FloatRect& rect);
		const sf::Vector2f& getRelativePos(const Entity& ent);

	private:
		Engine& m_engine;
		const sf::Event& m_originalEvent;
		sf::Vector2f m_pos;
	};
}
