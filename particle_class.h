#pragma once
#include <iostream>
#include <vector>
#include <utility>
#include <list>
using namespace std;


class Particles {
	private:
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
		void addToList(Particles& userParticle);
		float getGravity() const;
		float getVeloX() const;
		float getVeloY() const;
		int getColumn() const;
		int getRow() const;
		void aging();

		enum type {
			AIR,
			DUST,
			FIRE,
			WATER,
			EARTH, 
			LIGHTNING,
			DIRT
			//Dog,
		};
		void setType(type parType);
		
		//Are they voids? Doesn't specify
		void jiggle_physics(vector<vector<char>>& map);
		void touch();//touch who????

};



