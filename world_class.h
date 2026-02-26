#pragma once
#include <iostream>
#include "particle_class.h"
#include "/public/read.h" // IWYU pragma: keep
#include <vector>         // IWYU pragma: keep
using namespace std;

class Game;

class World {
	private:
		list <Particles> allPart;
		int size_row;
		int size_col;
		vector<vector<char>> worldMap = {};
		Game* framerate;
	public:
		World();
		World(int sRow, int sCol);
		

		void setSize_row(int sRow);
		void setSize_col(int sCol);
		int getSize_row() const;
		int getSize_col() const;
		void setMap(char ch);

		char getLocation(vector<vector<char>>& map, size_t row, size_t col);
		
		void setLocation(vector<vector<char>>& map, size_t row, size_t col, char c);

		void printMap();

		//Methods
		
		Particles* at(int row, int col);
		/*int size();
		void save();
		void load();
*/
		int particleSize();
		int aliveCount();
		void jiggle_physics(vector<vector<char>>& map);
};
