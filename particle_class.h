#pragma once
#include <compare>
#include <iostream>
#include <vector>
#include <utility>
#include <list>
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
		//Are they voids? Doesn't specify
		//void jiggle_physics(vector<vector<char>>& map);
		//void touch();//touch who????

};



