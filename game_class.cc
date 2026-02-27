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
void Game::render(World w) {
	const auto [ROWS, COLS] = get_terminal_size();
	list <Particles> partList = w.getList();
	set_cursor_mode(false);
	movecursor(ROWS, 0);
	cout << GREEN << "START(e) PAUSE(p) QUIT(q) LOAD(L) SAVE(s) INCREASE_FRAME_RATE(+)";
	cout << " DECREASE_FRAME_RATE(-) DRAW(d)" << RESET << endl; 
	for(auto temp = partList.begin(); temp != partList.end();) {
		set_cursor_mode(false);
		setbgcolor(0,0,0);
		movecursor(temp->getColumn(), temp->getRow());
		//TODO: print out particle with bg colors
	}
}
/*void click (int row, int col) {
	cout << "hello" << endl;
}*/
void Game::sprint() {
	//here goes the splash screen
	const auto [ROWS, COLS] = get_terminal_size();
	int row = 0;
	int col = 0;
	float fps = 100000;
	bool gameState = false;
	bool isPart = false;
	char menuInput;
	set_raw_mode(true);
	show_cursor(false);
	World w;
	Particles party;
	list <Particles> partList = w.getList();
	vector<vector<char>> m = w.getMap();
	w.printMap();
	char userInput = toupper(quick_read());
	render(w);
	while(true) {
		if(gameState) {
			render(w);
			w.jiggle_physics(m);
		}
		if(!gameState) {
			set_mouse_mode(true);
			on_mousedown([](int row, int col) { movecursor(row, col); } );//moves cursor to wherever you click
			for(auto temp = w.getList().begin(); temp != w.getList().end();) {
				if (temp->getRow() == row && temp->getColumn() == col) {
					w.remove(temp);
					isPart = false;
					break;
				}
			}
			if(isPart) {//if there isn't a particle add one to location
				Particles::particleType type;
				party.setPosition(row, col);
				clearscreen();
				cout << "What type Particle would you like to place?" << endl;
				cout << "(F)IRE (D)IRT (E)ARTH (L)IGHTNING (A)IR (W)ATER DUS(T)" << endl;
				set_raw_mode(false);
				show_cursor(true);
				cin >> menuInput;
				menuInput = toupper(menuInput);
				if (menuInput == 'F') {
					type = Particles::FIRE;
				}
				else if (menuInput == 'D') {
					type = Particles::DIRT;
				}
				else if (menuInput == 'E') {
					type = Particles::EARTH;
				}
				else if (menuInput == 'L') {
					type = Particles::LIGHTNING;
				}
				else if (menuInput == 'A') {
					type = Particles::AIR;
				}
				else if (menuInput == 'W') {
					type = Particles::WATER;
				}
				else if (menuInput == 'D') {
					type = Particles::DUST;
				}
				else {
					cout << "INVALID INPUT  --- You should get glasses" << endl;
				}
				party.setPosition(row, col);
				party.setType(type);
				w.addToList(party);
			}
			render(w);

		}
		if(userInput == 'E') {
			gameState = true;
		}
		else if(userInput == 'P' || w.aliveCount() == 0) {
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

