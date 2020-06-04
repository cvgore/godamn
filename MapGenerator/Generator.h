#pragma once

#include <iostream>
#include <vector>
#include "../Entities/Tiles/TileEnum.h"
#include "game_map.h"
#include "res_generator.h"

namespace Godamn
{
	class Generator
	{
	public:
		static std::vector<TileEnum> generator();
	};
}
