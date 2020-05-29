#pragma once
#include <iostream>
#include <vector>
#include "res_generator.h"
#include "game_map.h"
#include "../Entities/Tiles/TileEnum.h"


namespace Godamn
{
	class Generator {

	public:

		static std::vector<TileEnum> generator();

	};
}





