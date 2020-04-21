#include "main.h"

int main()
{
	/**
	 * @brief Setting memory leak detector, only if using debug mode
	 */
#if defined(_MSC_VER) && _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	Godamn::Engine game {};

	game.runChecks();
	game.initialize();

	const int exitCode = game.spawn();

	return exitCode;
}
