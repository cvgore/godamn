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

	Godamn::Engine game{};
	Godamn::Container container(&game);
	Godamn::Object::setContainer(&container);
	 
	game.runChecks();
	game.initialize();

	const int exitCode = game.spawn();

	return exitCode;
}
