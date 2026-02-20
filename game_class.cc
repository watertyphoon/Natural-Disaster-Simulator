#include "/public/read.h" // IWYU pragma: keep
#include <vector>         // IWYU pragma: keep
#include "game_class.h"
#include "/public/colors.h"
#include <list>
using namespace std;

Game::Game() {
	screen_size = { get_terminal_size() };	
	World w(screen_size.front().first, screen_size.front().second);
	frame = 0;
}

