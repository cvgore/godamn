#pragma once

#include <SFML/Graphics/RenderStates.hpp>
#include <SFML/Graphics/RenderTarget.hpp>
#include <include/SFML/Graphics/RectangleShape.hpp>
#include <memory>
#include "Entity.h"

namespace Godamn
{
	template<typename T>
	class AnonymousEntity : public Entity
	{
		std::shared_ptr<T> m_drawable;

	public:
		inline static constexpr Entity::EntityID entity_id = 0x00F0;

		AnonymousEntity(T* drawable, const sf::FloatRect& rect): Entity(rect), m_drawable(drawable)
		{
			static_assert(std::is_base_of<sf::Drawable, T>::value, "T must inherit from sf::Drawable");
			static_assert(std::is_base_of<sf::Transformable, T>::value, "T must inherit from sf::Transformable");

			static_cast<sf::Transformable*>(drawable)->setPosition(rect.left, rect.top);
		}

		virtual ~AnonymousEntity() = default;

		std::shared_ptr<T>& get()
		{
			return m_drawable;
		}

		T* operator->() const
		{
			return m_drawable.get();
		}

	protected:
		void draw(sf::RenderTarget& target, sf::RenderStates states) const override
		{
			target.draw(*m_drawable);

			Entity::draw(target, states);
		}
	};
}