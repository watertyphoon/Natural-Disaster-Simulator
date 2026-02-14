#include "/public/read.h" // IWYU pragma: keep
#include <vector>// IWYU pragma: keep
#include "particle_class.h"
using namespace std;

Particles::Particles() {
	gravity = 0;
	velocity = 0;
	row = 0;
	column = 0;
}
Particles::Particles(float userGrav, float userVelo, int userColumn, int userRow) {
	gravity = userGrav;
	velocity = userVelo;
	column = userColumn;
	row = userRow;
}
void Particles::setGravity(float userGrav) {
	gravity = userGrav;
}
void Particles::setVelocity(float userVelo) {
	velocity = userVelo;
}
void Particle::setPosition(int userColumn, int userRow) {
	row = userRow;
	column = userColumn;
}
