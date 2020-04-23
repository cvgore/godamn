#pragma once

#include <SFML/Graphics/Rect.hpp>
#include <SFML/Window/Event.hpp>
#include "../Entities/Entity.h"
#include "../Foundation/Object.h"

namespace Godamn
{
	class Engine;

	/**
	 * @class Event
	 *
	 * @brief Neat little wrapper over sf::Event, providing 
	 */
	class Event : public Object
	{
		const sf::Event& m_originalEvent;
		sf::Vector2f m_pos;
	public:
		Event(const sf::Event& originalEvent, sf::Vector2f& pos);
		/**
		 * @brief Returns wrapped event instance
		 */
		const sf::Event& getOriginalEvent();
		/**
		 * @brief Returns absolute to renderer position where event occured
		 */
		const sf::Vector2f& getPos();
		/**
		 * @brief Returns relative to given rectangle position where event occured
		 */
		sf::Vector2f getRelativePos(const sf::FloatRect& rect);
		/**
		 * @brief Returns relative to given entity position where event occured
		 */
		sf::Vector2f getRelativePos(const Entity& ent);
		/**
		 * @brief Checks whether event type is MouseEvent*
		 */
		bool isMouseEvent() const;
	};
}
