#pragma once
#include <iostream>
#include "/public/read.h" // IWYU pragma: keep
#include <vector>         // IWYU pragma: keep
using namespace std;

class World {
	private:
		int size_row;
		int size_col;
		char map_row;
		char map_col;
	public:
		World();
		World(int sRow, int sCol, char mRow, char mCol);
		//Getters and setters
		void setSize_row(int sRow);
		void setSize_col(int sCol);
		void setMap_row(char mRow);
		void setMap_col(char mCol);

		int getSize_row() const;
		int getSize_col() const;
		int getMap_row() const;
		int getMap_col() const;

		//Methods

		int* at(int row, int col);
		int physics(); //NOTE: Change this, this is a placeholder
		int size();
		int alive_count();
		void save();
		void load();

};
