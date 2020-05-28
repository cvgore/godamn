#pragma once

#include "IPoint.h"
#include "game_map.h"

namespace Godamn
{


	int los(int min, int max);

	class res_generator
	{
	private:
		const int n_original_max_nodes, n_original_max_tiles;
		int n_max_nodes;
		int n_avg_tiles_in_node;
		int n_max_tiles;
		game_map* n_map;					// wska�nik do mapy na kt�rej generujemy surowce
		char n_res_type;					// jaki surowiec generujemy na mapie

	public:
		res_generator(game_map* map, int min_node_count, int max_node_count,
			int min_tiles_in_node, int max_tiles_in_node, char res_type);
		res_generator(game_map* map, int max_tiles, char res_type);
		~res_generator();

		int getMaxNodes()const;
		int getMaxTiles()const;

		IPoint randomize_point();
		bool tile_not_taken(IPoint index);
		//metoda odpalana w p�tli for -> node_index = i
		void create_all_nodes();
		void create_node_on_the_map(int node_index);
		void create_node_on_the_map_2(int node_index);
	};
}