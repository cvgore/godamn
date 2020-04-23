// ReSharper disable CppClangTidyCppcoreguidelinesSpecialMemberFunctions
#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <string>

#include "../Foundation/Object.h"

namespace Godamn
{
	class Event;

	class Entity : public sf::Drawable, public sf::Transformable, public Object
	{
		sf::FloatRect m_rect;

	public:
		Entity() = delete;
		Entity(const sf::FloatRect& rect);
		virtual ~Entity() = default;
		virtual std::string getName() const;
		void onEvent(Event& ev);
		const sf::FloatRect& getRect() const;
	};
}
