#pragma once
#include <cstdint>

#include "../Foundation/Object.h"

namespace Godamn
{
	class Crypto : public Object
	{
	public:
		/**
		 * @brief Generates cryptographically secure pseudo random number
		 */
		static int64_t getRandomNumber();
		/**
		 * @brief Generates cryptographically secure pseudo random number from given range [left, right] (inclusive)
		 */
		static int64_t getRandomNumber(int64_t left, int64_t right);
		/**
		 * @brief Generates cryptographically secure pseudo random number from given range [0, max] (inclusive)
		 */
		static int64_t getRandomNumber(int64_t max);
	};
}
