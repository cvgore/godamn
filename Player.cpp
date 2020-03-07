#include "Player.h"

namespace Godamn
{
	Player::Player(const std::string& name)
	{
		this->m_name = name;
	}

	const std::string& Player::getName() const
	{
		return this->m_name;;
	}
}
