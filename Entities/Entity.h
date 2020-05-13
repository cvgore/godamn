// ReSharper disable CppClangTidyCppcoreguidelinesSpecialMemberFunctions
#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <guiddef.h>
#include <string>
#include "../Foundation/Object.h"

namespace Godamn
{
	class Event;

	class Entity : public sf::Drawable, public sf::Transformable, public Object
	{
		friend class Renderer;

		sf::FloatRect m_rect;
		uint16_t m_zIndex;

	public:
		// {E7102D28-1EBB-43FA-AB95-212B25ACF37E}
		inline static constexpr GUID entity_id = {
			0xe7102d28, 0x1ebb, 0x43fa, { 0xab, 0x95, 0x21, 0x2b, 0x25, 0xac, 0xf3, 0x7e }
		};

		Entity() = delete;
		Entity(const sf::FloatRect& rect);
		virtual ~Entity() = default;
		virtual std::string getName() const;
		void onEvent(Event& ev);
		const sf::FloatRect& getRect() const;
		/**
		 * @brief Determines priority of drawing of element, the higher value, the later element would be drawn
		 * Leave 0 for automatic priority
		 */
		uint16_t getZIndex() const;
		void setZIndex(uint16_t zIndex);
		/**
		 * @brief Returns unique screen object type ID
		 */
		static GUID getEntityId();

	protected:
		/**
		 * @brief Called right before drawing on screen object
		 */
		virtual void beforeDraw(const Renderer& renderer);
		/**
		 * @brief Called right after drawing on screen object
		 */
		virtual void afterDraw(const Renderer& renderer);
	};
}
