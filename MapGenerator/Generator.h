#include <iostream>
#include <time.h>
#include "res_generator.h"
#include "game_map.h"

#pragma once

namespace Godamn
{


	void generator() {
		srand(time(NULL));
		int sizex = 16, sizey = 24;
		game_map mapa(sizex, sizey, '0');
		//mapa.setBase();
		res_generator wood(&mapa, 5, 7, 4, 6, '2');
		res_generator stone(&mapa, 5, 7, 4, 6, '4');

		
	}

	
}



	

