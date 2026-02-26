#include "/public/read.h" // IWYU pragma: keep
#include <vector>         // IWYU pragma: keep
#include "game_class.h"
#include "world_class.h"
#include "/public/colors.h"
#include <list>
using namespace std;

Game::Game() {
	//screen_size = { get_terminal_size() };	
	World w(screen_size.first, screen_size.second);
	frame = 0;
}
void Game::FrameRate() {
	frame++;
}
void Game::render() {
	const auto [ROWS, COLS] = get_terminal_size();
	list <Particles> partList;
	set_cursor_mode(false);
	movecursor(ROWS, 0);
	cout << GREEN << "START(e) PAUSE(p) QUIT(q) LOAD(L) SAVE(s) INCREASE_FRAME_RATE(+)";
	cout << "DECREASE_FRAME_RATE(-) DRAW(d)" << RESET << endl; 
	for(auto temp = partList.begin(); temp != partList.end();) {
		set_cursor_mode(false);
		setbgcolor(0,0,0);
		movecursor(temp->getColumn(), temp->getRow());
		//TODO: print out particle with bg colors
	}
}
void Game::run() {

}

