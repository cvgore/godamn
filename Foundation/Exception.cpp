#include "Exception.h"

namespace Godamn
{
	Exception::Exception(const std::string_view what): m_what(what)
	{
	}

	char const* Exception::what() const
	{
		return m_what.data();
	}
}
