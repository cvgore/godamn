#pragma once

namespace Godamn
{
	class ScreenObject;

	/**
	 * @brief Handles beforeDraw & afterDraw events, currently it's only purpose is to
	 * strengthen encapsulation of drawable objects (like ScreenObject)
	 */
	class Renderer
	{
	public:
		virtual ~Renderer() = default;
		void beforeDraw(ScreenObject& object) const;
		void afterDraw(ScreenObject& object) const;
	};
}
