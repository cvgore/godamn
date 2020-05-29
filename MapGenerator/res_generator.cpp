#include "res_generator.h"
#include <iostream>
#include "../Utils/Crypto.h"


namespace Godamn
{
	

	

	res_generator::res_generator(game_map* map, int min_node_count, int max_node_count,
		int min_tiles_in_node, int max_tiles_in_node, char res_type) :
		n_map(map),
		// tak, aby obie te liczby by�y na pewno podzielne przez 2
		n_original_max_nodes((Crypto::getRandomNumber(min_node_count, max_node_count)) / 2 * 2),
		n_original_max_tiles(((min_node_count* Crypto::getRandomNumber(min_tiles_in_node, max_tiles_in_node)) + 1) / 2 * 2),
		n_max_nodes(n_original_max_nodes),
		n_avg_tiles_in_node((n_original_max_tiles + 1) / n_original_max_nodes),
		n_max_tiles(n_original_max_tiles),
		n_res_type(res_type)
	{
		this->create_all_nodes();
	}

	res_generator::res_generator(game_map* map, int max_tiles, char res_type) :
		n_map(map),
		n_original_max_nodes(0),
		n_max_nodes(0),
		n_avg_tiles_in_node(0),
		n_original_max_tiles(max_tiles),
		n_max_tiles(max_tiles),
		n_res_type(res_type)
	{
	}

	res_generator::~res_generator()
	{
	}

	int res_generator::getMaxNodes() const
	{
		return n_original_max_nodes;
	}

	int res_generator::getMaxTiles() const
	{
		return n_original_max_tiles;
	}

	IPoint res_generator::randomize_point()
	{
		return IPoint(Crypto::getRandomNumber(0, n_map->getLenght()), Crypto::getRandomNumber((0, n_map->getWidth())));
	}

	bool res_generator::tile_not_taken(IPoint index)
	{
		if (n_map->getChar(index) == n_map->getDefault_Value()) {
			return true;
		}
		else
			return false;
	}

	void res_generator::create_all_nodes()
	{
		for (int i = 0; i < n_max_nodes; i++)
		{
			if (n_max_tiles <= 0) { break; }
			create_node_on_the_map(i);
		}
		if (n_max_tiles > 0)
		{
			create_node_on_the_map(n_max_nodes + 1);
		}
	}
	void res_generator::create_node_on_the_map(int node_index)
	{
		int max_tiles_in_this_node = (n_avg_tiles_in_node + Crypto::getRandomNumber((-1, 1)));
		if (node_index > n_max_tiles) { max_tiles_in_this_node = n_max_tiles; }

		while (2 * max_tiles_in_this_node > n_max_tiles) { max_tiles_in_this_node--; }
		n_max_tiles -= 2 * max_tiles_in_this_node;

		IPoint first = randomize_point();


		for (int i = 0; i < max_tiles_in_this_node; i++)
		{
			IPoint copy(first);
			static int last_movement;
			int switch_count = 0;
		randomize:
			int movement_randomizer = Crypto::getRandomNumber((0, 4));
			if (movement_randomizer == last_movement) { goto randomize; }
			switch (movement_randomizer) {
			case 0: first.MoveByDistance(-1, 0); last_movement = 0; break;	// id� w g�r�
			case 1: first.MoveByDistance(1, 0); last_movement = 1; break;	// id� w d�
			case 2: first.MoveByDistance(0, -1); last_movement = 2; break;	// id� w lewo
			case 3: first.MoveByDistance(0, 1); last_movement = 3; break;	// id� w prawo
			}
			// wy�apanie wyj�cia poza zakres w tabeli
			if (first.getX() < 0) { first.setx(1); }
			else if (first.getY() < 0) { first.sety(1); }
			else if (first.getX() >= n_map->getLenght()) { first.setx(n_map->getLenght() - 2); }
			else if (first.getY() >= n_map->getWidth()) { first.sety(n_map->getWidth() - 2); }

			IPoint second(n_map->getLenght() - first.getX() - 1, n_map->getWidth() - first.getY() - 1);
			if (tile_not_taken(first) && tile_not_taken(second))
			{
				n_map->set_Indexed_Position(first, n_res_type);

				n_map->set_Indexed_Position(second, n_res_type);
			}
			else
			{
				switch_count++;
				if (switch_count > 50) { first = copy; }
				goto randomize;
			}
		}
	}

	void res_generator::create_node_on_the_map_2(int node_index)
	{
		while (n_max_tiles > 0)
		{
			int this_node_count = Crypto::getRandomNumber((2, 6));
			game_map temp(this_node_count, this_node_count, this->n_map->getDefault_Value());

		}
	}
}
