#include "/public/read.h" // IWYU pragma: keep
#include <vector>         // IWYU pragma: keep
#include "world_class.h"
using namespace std;

World::World() {
	size_row = 0;
	size_col = 0;
	map_row = 0;
	map_col = 0;
}

World::World(int sRow, int sCol, char mRow, char mCol) {
	size_row = sRow;
	size_col = sCol;
	map_row = mRow;
	map_col = mCol;
}

void World::setSize_row(int sRow) {
	size_row = sRow;
}

void World::setSize_col(int sCol) {
   size_col = sCol;
}

void World::setMap_row(char mRow) {
	map_row = mRow;
}

void World::setMap_col(char mCol) {
	map_col = mCol;
}

int World::getSize_row() const {
	return size_row;
}

int World::getSize_col() const {
	return size_col;
}

int World::getMap_row() const {
	return map_row;
}

int World::getMap_col() const {
	return map_col;
}
