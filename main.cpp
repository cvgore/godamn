#include "main.h"
#include "Foundation/Container.h"
#include "Foundation/Object.h"

int main()
{
	/**
	 * @brief Setting memory leak detector, only if using debug mode
	 */
#if defined(_MSC_VER) && _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	auto* game = __new Godamn::Engine;

	Godamn::Container::getInstance().setEngine(game);

	game->runChecks();
	game->initialize();

	const auto exitCode = game->spawn();

	// Free resources
	delete game;
	
	return exitCode;
}
