#pragma once
#include <iostream>
#include <vector>
#include <utility>
using namespace std;


class Particles {
	private:
		float gravity;
		float velocity;
		int column;
		int row;
		bool stationary;
	public:
		Particles();
		Particles(float userGrav, float userVelo, int useColumn, int userRow);
		void setGravity(float userGrav);
		void setVelocity(float userVelo);
		void setPosition(int userColumn, int userRow);
		float getGravity() const;
		float getVelocity() const;
		int getColumn() const;
		int getRow() const;

		enum type {
			AIR,
			DUST,
			FIRE,
			WATER,
			EARTH, 
			LIGHTNING,
			DIRT,
			//Dog,
		};
		
		//Are they voids? Doesn't specify
		void physics();
		void touch();

};

