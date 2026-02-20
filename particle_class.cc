#include "/public/read.h" // IWYU pragma: keep
#include <vector>// IWYU pragma: keep
#include "particle_class.h"
using namespace std;

Particles::Particles() {
	gravity = 0;
	veloX = 0;
	veloY = 0;
	row = 0;
	column = 0;
	stationary = true;
	lifetime = 0;
}
Particles::Particles(float userGrav, int userColumn, int userRow) {
	gravity = userGrav;
	column = userColumn;
	row = userRow;
}
void Particles::setGravity(float userGrav) {
	gravity = userGrav;
}
void Particles::setVelocity(float userX, float userY) {
	veloX = userX;
	veloY = userY;
}
void Particles::setPosition(int userColumn, int userRow) {
	row = userRow;
	column = userColumn;
}
void Particles::setType(type parType) {
	switch(parType) {//TO DO: implement other type
		//case type::AIR:
		case type::DIRT:
			veloX = 0;//velocity is always cell per tick
			veloY = 1;//positive is falling
			lifetime = -1;//-1 means infinite so no die
			stationary = false;
		//case type::DUST:
		//case type::FIRE:
		case type::EARTH:
			veloX = 0;
			veloY = 0;
			lifetime = -1;
			stationary = true;
		//case type::WATER:
		//case type::LIGHTNING:
	}
}
void Particles::aging() {
	lifetime = lifetime - 1;
}
float Particles::getGravity() const {
	return gravity;
}
float Particles::getVeloX() const {
	return veloX;
}
float Particles::getVeloY() const {
	return veloY;
}
int Particles::getColumn() const {
	return column;
}
int Particles::getRow() const {
	return row;
}
int Particles::getLifetime() const {
	return lifetime;
}
