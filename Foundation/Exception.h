#pragma once
#include <exception>
#include <string>

namespace Godamn
{
	/**
	 * @brief Base class for any exceptions
	 */
	class Exception : public std::exception
	{
		std::string_view m_what;
	public:
		Exception(std::string_view what = "");
		char const* what() const override;
	};
}
