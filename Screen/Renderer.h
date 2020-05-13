#pragma once

namespace Godamn
{
	class Entity;

	/**
	 * @brief Handles beforeDraw & afterDraw events, currently it's only purpose is to
	 * strengthen encapsulation of drawable objects (like ScreenObject)
	 */
	class Renderer
	{
	public:
		virtual ~Renderer() = default;
		void beforeDraw(Entity& object) const;
		void afterDraw(Entity& object) const;
	};
}
