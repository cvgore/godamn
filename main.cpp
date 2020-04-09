#include "main.h"

int main()
{	
	Godamn::Engine game {};

	game.runChecks();
	game.initialize();
	
	const int exitCode = game.spawn();
	
	return exitCode;
}
