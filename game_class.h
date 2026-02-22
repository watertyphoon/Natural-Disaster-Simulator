#include "/public/read.h" // IWYU pragma: keep
#include "/public/colors.h"
#include "particle_class.h"
#include "world_class.h"
#include <vector>         // IWYU pragma: keep
#include <list>
using namespace std;

class Game {
	private:
		list<pair<int, int>> screen_size;
		World world();
		int frame = 0;
	public:
		Game();
		void render();
		void run();
		void FrameRate();
};
