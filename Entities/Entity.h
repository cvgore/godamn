// ReSharper disable CppClangTidyCppcoreguidelinesSpecialMemberFunctions
#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include <guiddef.h>
#include <string>
#include "../Events/EventMethodsInterfaces.h"
#include "../Foundation/Object.h"

namespace Godamn
{
	class Event;

	class Entity : public sf::Drawable, public sf::Transformable, public Object
	{
	public:
		typedef uint16_t EntityID;

	private:
		friend class Renderer;

		sf::FloatRect m_rect;
		uint16_t m_zIndex;

		/** @debugging */
		static int m_debug;

	public:
		inline static constexpr EntityID entity_id = 0x0020;

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
		static EntityID getEntityId();
		void keyboardDebug(Event& ev);

	protected:
		/**
		 * @brief Called right before drawing on screen object
		 */
		virtual void beforeDraw(const Renderer& renderer);
		/**
		 * @brief Called right after drawing on screen object
		 */
		virtual void afterDraw(const Renderer& renderer);
		void draw(sf::RenderTarget &target, sf::RenderStates states) const override;
	};
}
