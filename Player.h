#pragma once

#include <string>

namespace Godamn
{
	class Player
	{
	public:
		Player(const std::string& name);
		const std::string& getName() const;
	private:
		std::string m_name;
		uint16_t m_power = 0;
	};
}
