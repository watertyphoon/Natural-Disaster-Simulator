#include "/public/read.h" // IWYU pragma: keep
#include <vector>         // IWYU pragma: keep
#include "particle_class.h"
#include "world_class.h"
#include "game_class.h"
#include "/public/colors.h"
using namespace std;

int main() {
	World w(15, 15);

	w.printMap();
	cout << "Test good" << endl;
	w.setMap('c');
	w.printMap();

	show_cursor(true);
}
