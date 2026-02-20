#pragma once
#include <iostream>
#include "particle_class.h"
#include "/public/read.h" // IWYU pragma: keep
#include <vector>         // IWYU pragma: keep
using namespace std;

class World {
	private:
		int size_row;
		int size_col;
		vector<vector<char>> worldMap = {
			{'*', '*', '*', '*'},
			{'*', '*', '*', '*'},
			{'*', '*', '*', '*'},
	
		};
		list <Particles> allPart; 
	public:
		World();
		World(int sRow, int sCol, char mRow, char mCol);
		//vector<vector<char>> worldMap;
		//Getters and setters
		void setSize_row(int sRow);
		void setSize_col(int sCol);
		int getSize_row() const;
		int getSize_col() const;

		char getLocation(vector<vector<char>>& map, size_t row, size_t col);
		
		void setLocation(vector<vector<char>>& map, size_t row, size_t col, char c);

		void printMap(/*vector<vector<char>>& map, size_t row, size_t col*/);

		//Methods
		
		
		/*int* at(int row, int col);
		int physics(); //NOTE: Change this, this is a placeholder
		int size();
		int alive_count();
		void save();
		void load();
*/
		int particleSize();
		int aliveCount();
		void jiggle_physics(vector<vector<char>>& map);
};
