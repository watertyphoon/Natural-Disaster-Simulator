#pragma once
#include <compare>
#include <iostream>
#include <vector>
#include <utility>
#include <list>
#include <cstdint>
using namespace std;


class Particles {
	public:
		enum particleType {
			AIR,
			DUST,
			FIRE,
			WATER,
			EARTH, 
			LIGHTNING,
			DIRT
			//Dog,
		};
		
	private:
		particleType type;
		float gravity;
		float veloX;
		float veloY;
		int column;
		int row;
		int lifetime;
		bool stationary;
		uint8_t r;
		uint8_t g;
		uint8_t b;


	public:
		Particles();
		Particles(float userGrav,int useColumn, int userRow);
		void setGravity(float userGrav);
		void setVelocity(float userX, float userY);
		void setPosition(int userColumn, int userRow);
		float getGravity() const;
		float getVeloX() const;
		float getVeloY() const;
		int getColumn() const;
		int getRow() const;
		int getLifetime() const;
		void aging();
		void touch(Particles victim);
		void setType(particleType parType);
		particleType getType() const;
		void setColor(uint8_t red, uint8_t green, uint8_t blue);
		uint8_t getRed() const;
		uint8_t getBlue() const;
		uint8_t getGreen() const;
		//Are they voids? Doesn't specify
		//void jiggle_physics(vector<vector<char>>& map);
		//void touch();//touch who????

};



