#pragma once

namespace Godamn
{
	class Container;

	class Object
	{
	public:
		Object() = default;
		/***
		 * @brief Returns current container
		 */
		static Container& getContainer();
	};
}
