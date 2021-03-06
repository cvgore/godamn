#pragma once
#include <iostream>
#include "IPoint.h"



namespace Godamn
{


	class game_map
	{
	private:
		int n_lenght;
		int n_width;
		char** n_tab;
		char n_default_value;
	public:
		game_map(int lenght, int width, char default_value);
		~game_map();

		int getLenght()const;
		int getWidth()const;
		char getDefault_Value()const;
		char getChar(IPoint index)const;

		void set_Indexed_Position(IPoint index, char new_Value);
		void setBase();
		int getResourceCount(char res_type);
		void replaceBaseWithStandardObjects();

		char* operator[](int index);
	};
}