#include "Generator.h"

namespace Godamn
{

	std::vector<TileEnum> Generator::generator()
	{
		std::vector<TileEnum> m_map;

		int sizex = 15, sizey = 24;
		game_map mapa(sizex, sizey, '0');

		mapa.setBase();

		res_generator wood(&mapa, 5, 7, 4, 6, '2');
		res_generator stone(&mapa, 5, 7, 4, 6, '4');

		mapa.replaceBaseWithStandardObjects();

		for (int i = 0; i < sizex; i++) {
			for (int j = 0; j < sizey; j++) {
				switch (mapa[i][j])
				{
					case '2':
						m_map.push_back(TileEnum::Grass_Forest);
						break;
					case '4':
						m_map.push_back(TileEnum::Grass_Stone);
						break;
					case 's':
						m_map.push_back(TileEnum::Grass_Miner);
						break;
					case 'l':
						m_map.push_back(TileEnum::Grass_Lumber);
						break;
					case 't':
						m_map.push_back(TileEnum::Grass_Temple);
						break;
					default:
						m_map.push_back(TileEnum::Grass);
						break;
				}
			}
		}

		return m_map;
	}
}