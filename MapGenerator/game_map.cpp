#include "game_map.h"

namespace Godamn {
	
	game_map::game_map(int lenght, int width, char default_value) :
		n_lenght(lenght), n_width(width), n_default_value(default_value)
	{
		this->n_tab = __new char* [n_lenght];
		for (int i = 0; i < n_lenght; i++)
		{
			n_tab[i] = __new char[n_width];
		}

		// nadawanie default_value
		for (int i = 0; i < n_lenght; i++)
		{
			for (int j = 0; j < n_width; j++)
			{
				n_tab[i][j] = n_default_value;
			}
		}
		//this->setBase();
	}

	game_map::~game_map()
	{
		if (n_tab != nullptr)
		{
			for (int i = 0; i < n_lenght; i++)
			{
				delete[] n_tab[i];
			}
			delete[] n_tab;
			n_tab = nullptr;
		}
	}

	int game_map::getLenght() const
	{
		return n_lenght;
	}

	int game_map::getWidth() const
	{
		return n_width;
	}

	char game_map::getDefault_Value() const
	{
		return n_default_value;
	}

	char game_map::getChar(IPoint index) const
	{
		return this->n_tab[index.getX()][index.getY()];
	}

	void game_map::set_Indexed_Position(IPoint index, char new_Value)
	{
		n_tab[index.getX()][index.getY()] = new_Value;
	}

	void game_map::setBase()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				n_tab[n_lenght - 3 + i][j] = 'b';
				n_tab[i][n_width - 3 + j] = 'b';
			}
		}
	}

	int game_map::getResourceCount(char res_type)
	{
		int res_count = 0;

		for (int i = 0; i < n_lenght; i++)
		{
			for (int j = 0; j < n_width; j++)
			{
				if (n_tab[i][j] == res_type) { res_count++; }
			}
		}

		return res_count;
	}

	char* game_map::operator[](int index)
	{
		return this->n_tab[index];
	}

	void game_map::replaceBaseWithStandardObjects()
	{
		const char layout[] = { 's', '0', 'l', '0', 't', 'l', 's', '0', '0' };
		const int breakAt = 3;

		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				n_tab[n_lenght - 3 + i][j] = layout[i + j * breakAt];
			}
		}
	}
}