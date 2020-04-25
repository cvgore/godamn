#pragma once
#include <exception>

namespace Godamn
{
	/**
	 * @brief Base class for any exceptions
	 */
	class Exception : public std::exception
	{
	public:
		Exception() = default;
	};
}
