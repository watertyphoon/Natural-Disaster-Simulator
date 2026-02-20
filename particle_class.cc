#include "/public/read.h" // IWYU pragma: keep
#include <vector>// IWYU pragma: keep
#include "particle_class.h"
#include <ctime>
#include <algorithm>
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
void Particles::setType(particleType parType) {
	srand(time(0));
	this->type = parType;
	switch(parType) {//TO DO: implement other type
		case particleType::AIR:
			veloX = 1;
			veloY = 0;
			lifetime = 15;
			stationary = false;
			break;
		case particleType::DIRT:
			veloX = 0;//velocity is always cell per tick
			veloY = 1;//positive is falling
			lifetime = -1;//-1 means infinite so no die
			stationary = false;
			break;
		case particleType::DUST:
			veloX = rand(); //Double check if this is right
			veloY = 0;
			lifetime = 15;
			stationary = false;
			break;
		case particleType::FIRE:
			veloX = 0;
			veloY = 0;
			lifetime = -1;
			stationary = true;
			break;
			//How do lighting strucks???
		case particleType::EARTH:
			veloX = 0;
			veloY = 0;
			lifetime = -1;
			stationary = true;
			break;
		//case type::WATER:
		//case type::LIGHTNING:
		case particleType::LIGHTNING:
			veloX = 0;
			veloY = 2;
			lifetime = 10;
			stationary = false;
			break;
		case particleType::WATER:
			veloX = 0;
			veloY = 1;
			lifetime = 20;
			stationary = false;
			break;
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
Particles::particleType Particles::getType() const {
	return type;
}
void Particles::touch(Particles victim) {
	if(this->type == WATER && victim.getType() == FIRE) {
		this->setType(AIR);
	}
	else if(this->type == LIGHTNING && victim.getType() == WATER) {
		victim.setType(LIGHTNING);
	}
	else if(this->type == LIGHTNING && victim.getType() == EARTH) {
		victim.setType(DIRT);
	}
}
