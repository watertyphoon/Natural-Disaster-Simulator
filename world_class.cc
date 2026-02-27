#include "/public/read.h" // IWYU pragma: keep
#include <memory>
#include <vector>         // IWYU pragma: keep
#include "/public/colors.h"
#include "world_class.h"
#include "particle_class.h"
#include <ctime>
#include "game_class.h"
#include <algorithm>
using namespace std;

World::World() {
	size_row = 0;
	size_col = 0;
	//vector<vector<char>>
	worldMap = {
		{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
		{'*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*', '*'},

	};
}

World::World(int sRow, int sCol) {
	size_row = sRow;
	size_col = sCol;
	worldMap.resize(size_row);
	for (int i = 0; i < size_row; i++) {
		 worldMap.at(i).resize(size_col);
	}
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

char World::getLocation(vector<vector<char>>& map, size_t row, size_t col) {
	if (row >= map.size()) return ' ';
	if (col >= map.at(row).size()) return ' ';
	return map.at(row).at(col);
}

void World::setLocation(vector<vector<char>>& map, size_t row, size_t col, char c) {
	if (row >= map.size()) return;
	if (col >= map.at(row).size()) return;
	map.at(row).at(col) = c;
}

void World::setMap(char ch) {
	worldMap.resize(size_row);
	for (int i = 0; i < size_row; i++) {
		worldMap.at(i).resize(size_col);
	}

	for (int i = 0; i < size_row; i++) {
		for (int j = 0; j < size_col; j++) {
			worldMap.at(i).at(j) = ch;
		}
	}
}

vector<vector<char>> World::getMap() const {
	return worldMap;	
}


void World::printMap() {
	clearscreen();
	show_cursor(true);
	movecursor(0, 0);

	for (int i = 0; i < worldMap.size(); i++) {

		for (int j = 0; j < worldMap.at(i).size(); j++) {
			cout << worldMap.at(i).at(j);
		}
		cout << endl;
	}

	show_cursor(false);
}

Particles* World::at(int row, int col) {
	for(auto temp = allPart.begin(); temp != allPart.end();) {
		if(temp->getRow() == row && temp->getColumn() == col) {
			Particles* part = &*temp;	
			return part;
		}
	}
		return nullptr; //placeholder
}

void World::save() {
	savePart = allPart;
}

void World::load() {
	allPart.clear();
	if (savePart.empty()) {
		cout << BOLDRED << "ERROR: No save file detected" << endl; 
		cout << BOLDWHITE << "You should probably have a save file saved in order to load a save file" << endl;
		cout << RESET;
	}
	else 
		allPart = savePart;
}

int World::particleSize() {
	return allPart.size();
}

int World::aliveCount() {
	int sub = 0;
	for (const auto& temp : allPart) {
		if (temp.getLifetime() == -1) {
			sub++;
		}
	}
	return allPart.size() - sub;
}

void World::jiggle_physics(vector<vector<char>>& map) {
	framerate->FrameRate();
	int newRow = 0;
	int newCol = 0;
	for(auto temp = allPart.begin(); temp != allPart.end();) {
		newRow = temp->getRow() + temp->getVeloX();
		newCol = temp->getColumn() + temp->getVeloY();
		for(auto& temp2 : allPart) {
			if (newRow == temp2.getRow() && newCol == temp2.getColumn()) {
				temp->touch(temp2);
			}
		}
		temp->aging();
		if (temp->getLifetime() == 0) {
			temp = allPart.erase(temp);
		}
		else {
			temp->setPosition(newCol, newRow);
			temp++;
		}
	}
}

list <Particles> World::getList() {
	return allPart;
}

void World::addToList(Particles tempPart) {
	allPart.emplace_back(tempPart);
}
