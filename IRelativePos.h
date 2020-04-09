#pragma once
#include <SFML/System/Vector2.hpp>

namespace Godamn
{
	class IRelativePos
	{
	public:
		virtual ~IRelativePos() = default;
		virtual const sf::Vector2u getRelativePos() = 0;
	};
}
