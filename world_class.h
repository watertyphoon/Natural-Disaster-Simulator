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
		list <Particles> savePart;
		int size_row;
		int size_col;
		vector<vector<char>> worldMap = {};
		//list<pair<int, int>> save_coords;
		Game* framerate;
	public:
		World();
		World(int sRow, int sCol);
		

		list <Particles> getList();
		void addToList(Particles tempPart);
		void remove(Particles* tempParty);
		void setSize_row(int sRow);
		void setSize_col(int sCol);
		int getSize_row() const;
		int getSize_col() const;
		void setMap(char ch);
		vector<vector<char>> getMap() const;

		char getLocation(vector<vector<char>>& map, size_t row, size_t col);
		
		void setLocation(vector<vector<char>>& map, size_t row, size_t col, char c);

		void printMap();

		//Methods
		
		Particles* at(int row, int col);
		void save();
		void load();
		
		int particleSize();
		int aliveCount();
		void jiggle_physics(vector<vector<char>>& map);
};
