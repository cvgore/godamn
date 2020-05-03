#include "main.h"

#include "Config/EntityConfigStore.h"
#include "Scenery/SceneryManager.h"
#include "Foundation/Container.h"

int main()
{
	/**
	 * @brief Setting memory leak detector, only if using debug mode
	 * This must be first 3 lines in main.cpp
	 */
#if defined(_MSC_VER) && _DEBUG
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#endif

	// Storing reference to container instance
	auto& container = Godamn::Container::getInstance();

	// Creating engine & putting it in a container
	container.setEngine(__new Godamn::Engine);

	// Creating entity config store & putting it in a container
	container.setEntityConfigStore(__new Godamn::EntityConfigStore);

	// Creating scenery manager & putting it in a container
	container.setSceneryManager(__new Godamn::SceneryManager);

	// Storing pointer to engine from container
	auto game = container.getEngine();

	game->runChecks();
	game->initialize();

	const auto exitCode = game->spawn();

	// Right before exiting, we're disposing any resources
	// NOTE: container is not usable after disposing
	container.dispose();

	return exitCode;
}
