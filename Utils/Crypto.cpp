#include "Crypto.h"
#include "CryptoException.h"
#include <bcrypt.h>
#include <ntstatus.h>

namespace Godamn
{
	int64_t Crypto::getRandomNumber()
	{
		int64_t num = 0;

		auto status = BCryptGenRandom(NULL, &num, sizeof(num), BCRYPT_USE_SYSTEM_PREFERRED_RNG);

		if (status != STATUS_SUCCESS)
		{
			throw CryptoException();
		}

		return num;
	}

	int64_t Crypto::getRandomNumber(int64_t left, int64_t right)
	{
		return getRandomNumber() % (right - left + 1) - left;
	}

	int64_t Crypto::getRandomNumber(int64_t max)
	{
		return getRandomNumber(0, max);
	}
}
