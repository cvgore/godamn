#include "Crypto.h"
#include "CryptoException.h"

#include <windows.h>
#include <ntstatus.h>
#include <bcrypt.h>

namespace Godamn
{
	int64_t Crypto::getRandomNumber()
	{
		static union
		{
			UCHAR bytes[8];
			int64_t num = 0;
		} converter;

		NTSTATUS status = BCryptGenRandom(NULL, converter.bytes, sizeof(converter.bytes), BCRYPT_USE_SYSTEM_PREFERRED_RNG);

		if (status != STATUS_SUCCESS)
		{
			throw CryptoException();
		}

		return converter.num;
	}

	int64_t Crypto::getRandomNumber(int64_t left, int64_t right)
	{
		return getRandomNumber() % (right - left + 1) + left;
	}
	int64_t Crypto::getRandomNumber(int64_t max)

	{
		return getRandomNumber(0, max);
	}
}
