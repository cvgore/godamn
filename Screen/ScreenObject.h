#pragma once

#include <SFML/Graphics/Drawable.hpp>
#include <SFML/Graphics/Transformable.hpp>
#include "../Foundation/Object.h"

namespace Godamn
{
	class Renderer;

	class ScreenObject : public sf::Drawable, public sf::Transformable, public Object
	{
		friend class Renderer;

	public:
		virtual ~ScreenObject() = default;

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