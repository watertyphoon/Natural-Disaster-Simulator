#include "/public/read.h" // IWYU pragma: keep
#include <cctype>
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
void Game::sprint() {
	//here goes the splash screen
	float fps = 100000;
	bool gameState = false;
	set_raw_mode(true);
	show_cursor(false);
	World w;
	w.printMap();
	while(true) {
		char userInput = toupper(quick_read());
		if(gameState) {
			render();
			w.jiggle_physics(w.getMap());
		}
		if(userInput == 'E') {
			gameState = true;
		}
		else if(userInput == 'P') {
			gameState = false;
		}
		else if(userInput == 'Q') {
			break;
		}
		else if(userInput == 'L') {
			cout << "not implemented yet" << endl;
			//TODO: implement method to load
		}
		else if(userInput == 'S') {
			cout << "not implemente d yet" << endl;
			//TODO: implement save method
		}
		else if(userInput == '+') {
			fps += 100;
		}
		else if(userInput == '-') {
			if (fps >= 100) {//this checks that fps won't go less than 0
				fps -= 100;
			}
			else {
				fps = 0;
			}
		}
		else if (userInput == 'D') {
			cout << "not implemented yet" << endl;
			//need to implement a bridges and draw method
		}
		usleep(fps);
	}
}

