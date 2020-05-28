#pragma once

#include "../Foundation/Exception.h"

namespace Godamn
{
	class SceneryException : public Exception
	{
	public:
		SceneryException(std::string_view what): Exception(what)
		{}
	};
}
