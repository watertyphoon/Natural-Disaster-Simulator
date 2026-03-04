#include "/public/read.h" // IWYU pragma: keep
#include <cstdint>
#include <vector>// IWYU pragma: keep
#include "particle_class.h"
#include "world_class.h"
#include <ctime>
#include <algorithm>
using namespace std;

Particles::Particles() {
	gravity = 0;
	veloX = 0;
	veloY = 0;
	rows = 0;
	columns = 0;
	stationary = true;
	lifetime = 0;
	r = 0;
	g = 0;
	b = 0;
}
Particles::Particles(float userGrav, int userColumn, int userRow) {
	gravity = userGrav;
	columns = userColumn;
	rows = userRow;
}
void Particles::setGravity(float userGrav) {
	gravity = userGrav;
}
void Particles::setVelocity(float userX, float userY) {
	veloX = userX;
	veloY = userY;
}
void Particles::setPosition(int userColumn, int userRow) {
	rows = userRow;
	columns = userColumn;
}

void Particles::setColor(uint8_t red, uint8_t green, uint8_t blue) {
	r = red;
	g = green;
	b = blue;
}

void Particles::setType(particleType parType) {
	srand(time(0));
	this->type = parType;
	switch(parType) {//TO DO: implement other type
		case particleType::AIR:
			veloX = 0;
			veloY = -1;
			lifetime = -1;
			stationary = false;
			r = 255;
			g = 255;
			b = 255;
			break;
		case particleType::DIRT:
			veloX = 1;//velocity is always cell per tick
			veloY = 0;//positive is falling
			lifetime = -1;//-1 means infinite so no die
			stationary = false;
			r = 112;
			g = 69;
			b = 26;
			break;
		case particleType::DUST:
			veloX = 0;  //Double check if this is right
			veloY = rand() % 2;
			lifetime = 400;
			stationary = false;
			r = 156;
			g = 139;
			b = 123;
			break;
		case particleType::FIRE:
			veloX = 0;
			veloY = 0;
			lifetime = -1;
			stationary = true;
			r = 219;
			g = 22;
			b = 22;
			

			break;
			//How do lighting strucks???
		case particleType::EARTH:
			veloX = 0;
			veloY = 0;
			lifetime = -1;
			stationary = true;
			r = 17;
			g = 140;
			b = 42;
			break;
		case particleType::LIGHTNING:
			veloX = 2;
			veloY = 0;
			lifetime = 420;
			stationary = false;
			r = 232;
			g = 193;
			b = 51;
			break;
		case particleType::WATER:
			veloX = 1;
			veloY = 0;
			lifetime = 420;
			stationary = false;
			r = 65;
			g = 174;
			b = 232;
			break;
		case particleType::DOG:
			veloX = 1;
			veloY = 0;
			lifetime = 420;
			stationary = false;
			r = 67;
			g = 102;
			b = 87;
	}
}
void Particles::aging() {
	lifetime = lifetime - 1;
	if (this-> type == FIRE) {
		Particles spark;
		spark.setType(LIGHTNING);
	}

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
	return columns;
}
int Particles::getRow() const {
	return rows;
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
	else if(this->type == WATER) {
		this->setPosition(this->getColumn(), this->getRow() + 1);
	}
	else if(this->type == LIGHTNING && victim.getType() == WATER) {
		victim.setType(LIGHTNING);
	}
	else if(this->type == LIGHTNING && victim.getType() == EARTH) {
		victim.setType(DIRT);
	}
}

uint8_t Particles::getRed() const {
	return r;
}

uint8_t Particles::getGreen() const {
	return g;
}

uint8_t Particles::getBlue() const {
	return b;
}
