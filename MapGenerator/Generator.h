#pragma once
#include <iostream>
#include <time.h>
#include <vector>
#include "res_generator.h"
#include "game_map.h"
#include "../Entities/Tiles/TileEnum.h"


namespace Godamn
{
	inline std::vector<TileEnum> m_map;

	inline void generator() {
		srand(time(NULL));
		int sizex = 15, sizey = 24;
		game_map mapa(sizex, sizey, '0');
		//mapa.setBase();
		res_generator wood(&mapa, 5, 7, 4, 6, '2');
		res_generator stone(&mapa, 5, 7, 4, 6, '4');

		//todo: naniesienie obszaru startowego na mape
		
		for (int i = 0; i < sizex; i++) {
			for (int j = 0; j < sizey; j++)
				if (mapa[i][j] == '0') {
					m_map.push_back(TileEnum::Grass);
				}
				else if (mapa[i][j] == '2') {
					m_map.push_back(TileEnum::Grass_Forest);
				}

				else if (mapa[i][j] == '4')
				{
					m_map.push_back(TileEnum::Moutain_Stone);
				}
				else
				{
					m_map.push_back(TileEnum::Grass);
				}

		}
	}

}





