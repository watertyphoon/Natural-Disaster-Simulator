#include "/public/read.h" // IWYU pragma: keep
#include <vector>         // IWYU pragma: keep
#include "particle_class.h"
#include "world_class.h"
#include "/public/colors.h"
using namespace std;

int main() {
	World w;
	//w.setSize_row
	w.printMap();
	cout << "Test good" << endl;
	show_cursor(true);
}
