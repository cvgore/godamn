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
		inline static constexpr GUID entity_id = {
			0x57ac7725, 0x2b2a, 0x4be6, { 0x91, 0x32, 0x2f, 0x3a, 0x33, 0xda, 0xe2, 0xbf }
		};

		AnonymousEntity(sf::RectangleShape* drawable, const sf::FloatRect& rect): Entity(rect), m_drawable(drawable)
		{
			static_assert(std::is_base_of<sf::Drawable, T>::value, "T must inherit from sf::Drawable");
		}
		virtual ~AnonymousEntity() = default;

		std::shared_ptr<T>& get() const
		{
			return m_drawable;
		}

		T* operator->()
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