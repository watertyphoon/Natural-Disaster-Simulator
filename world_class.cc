#include "/public/read.h" // IWYU pragma: keep
#include <vector>         // IWYU pragma: keep
#include "/public/colors.h"
#include "world_class.h"

using namespace std;

World::World() {
	size_row = 0;
	size_col = 0;
	//vector<vector<char>>
	worldMap = {};
}

World::World(int sRow, int sCol, char mRow, char mCol) {
	size_row = sRow;
	size_col = sCol;
}

void World::setSize_row(int sRow) {
	size_row = sRow;
}

void World::setSize_col(int sCol) {
   size_col = sCol;
}


int World::getSize_row() const {
	return size_row;
}

int World::getSize_col() const {
	return size_col;
}

char getLocation(vector<vector<char>>& map, size_t row, size_t col) {
	if (row >= map.size()) return ' ';
	if (col >= map.at(row).size()) return ' ';
	return map.at(row).at(col);
}

void setLocation(vector<vector<char>>& map, size_t row, size_t col, char c) {
	if (row >= map.size()) return;
	if (col >= map.at(row).size()) return;
	map.at(row).at(col) = c;
}

void printMap(vector<vector<char>>& map, size_t row, size_t col) {
	clearscreen();
	show_cursor(true);
	movecursor(0,0);
	
	for (int i = 0; i < map.size(); i++) {
		for (int j = 0; j < map.at(i).size(); i++) {
			if (i == row and j = col)
				cout << ' ' << endl;
			else cout << ' ' << endl; //CHANGE EVENTUALLY
		}
	}

	show_cursor(false);
}
