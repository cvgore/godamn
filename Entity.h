// ReSharper disable CppClangTidyCppcoreguidelinesSpecialMemberFunctions
#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>

namespace Godamn
{
	class Event;

	class Entity : public sf::Drawable, public sf::Transformable
	{
	public:
		Entity() = delete;
		Entity(const sf::FloatRect& rect);
		virtual ~Entity() = default;
		virtual const char* getName() const;
		void onEvent(Event& ev);
		const sf::FloatRect& getRect() const;

	private:
		sf::FloatRect m_rect;
	};
}
