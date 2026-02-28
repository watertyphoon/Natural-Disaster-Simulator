#include "/public/read.h" // IWYU pragma: keep
#include <cctype>
#include <unistd.h>
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
	//const auto [ROWS, COLS] = get_terminal_size();
	list <Particles> partList = w.getList();
	set_cursor_mode(false);
	/*movecursor(0, w.getSize_col());
	cout << BLUE << "PARTICLE: " << endl;*/
	movecursor(w.getSize_row(), 0);
	cout << GREEN << "START(e) PAUSE(p) QUIT(q) LOAD(L) SAVE(s) INCREASE_FRAME_RATE(+)";
	cout << " DECREASE_FRAME_RATE(-) DRAW(d)" << RESET << endl;
	if(!partList.empty()){ 
		for(auto temp = partList.begin(); temp != partList.end();) {
			//set_cursor_mode(false);
			setbgcolor(temp->getRed(),temp->getGreen(),temp->getBlue());
			movecursor(temp->getRow(), temp->getColumn());
			//TODO: print out particle with bg colors
			set_raw_mode(false);
			cout << ' ' << endl;
			cout << RESET << endl;
			setbgcolor(0,0,0);
		}
	}
}
/*void click (int row, int col) {
	//movecursor(row, col);
	mRow = row;
	mCol = col;
}*/
void Game::sprint() {
	//here goes the splash screen
	//clearscreen();
	const auto [ROWS, COLS] = get_terminal_size();
	int mRow = 0;
	int mCol = 0;
	float fps = 100000;
	bool gameState = false;
	bool isPart = true;
	char menuInput;
	int scroll = 0;
	set_raw_mode(true);
	show_cursor(false);
	World w;
	Particles party;
	list <Particles> partList = w.getList();
	vector<vector<char>> m = w.getMap();
	w.printMap();
	render(w);
	usleep(100000);
	while(true) {
		set_raw_mode(false);
		movecursor(0, w.getSize_col()-18);
		cout << MAGENTA << "PARTICLE: ";
		if(scroll == 0) {
			cout << "FIRE     " << endl;
		}
		else if (scroll == 1) {
			cout << "DIRT     " << endl;
		}
		else if (scroll == 2) {
			cout << "EARTH    " << endl;
		}
		else if (scroll == 3) {
			cout << "LIGHTNING" << endl;
		}
		else if (scroll == 4) {
			cout << "AIR      " << endl;
		}
		else if (scroll == 5) {
			cout << "WATER    " << endl;
		}
		else if (scroll == 6) {
			cout << "DUST     " << endl;
		}
		cout << RESET << endl;
		set_raw_mode(true);
		char userInput = toupper(quick_read());
		if(gameState) {
			render(w);
			w.jiggle_physics(m);
		}
		set_mouse_mode(true);
		if(!gameState) {
			on_mousedown([&](int row, int col){
					movecursor(row, col);
					mRow = row;
					mCol = col;
					});
			if(scroll == 0) {
				party.setType(Particles::FIRE);
				party.setPosition(mCol, mRow);
			}
			else if(scroll == 1) {
				party.setType(Particles::DIRT);
				party.setPosition(mCol, mRow);
			}
			else if(scroll == 2) {
				party.setType(Particles::EARTH);
				party.setPosition(mCol, mRow);
			}
			else if(scroll == 3) {
				party.setType(Particles::LIGHTNING);
				party.setPosition(mCol, mRow);
			}
			else if(scroll == 4) {
				party.setType(Particles::AIR);
				party.setPosition(mCol, mRow);
			}
			else if(scroll == 5) {
				party.setType(Particles::WATER);
				party.setPosition(mCol, mRow);
			}
			else if(scroll == 6) {
				party.setType(Particles::DUST);
				party.setPosition(mCol, mRow);
			}
			w.addToList(party);
		}
		if(userInput == 'W' || userInput == UP_ARROW){
			if(scroll + 1 > 6) {
				scroll = 0;
			}
			else {
				scroll++;
			}
		}
		else if(userInput == 'S' || userInput == DOWN_ARROW) {
			if (scroll - 1 < 0) {
				scroll = 6;
			}
			else {
				scroll--;
			}
		}
		/*else {
			set_mouse_mode(true);
			on_mousedown(click);//moves cursor to wherever you click
			if(!partList.empty()) {
				for(auto temp = w.getList().begin(); temp != w.getList().end();) {
					if (temp->getRow() == row && temp->getColumn() == col) {
						w.getList().erase(temp);
						isPart = false;
						//break;
					}
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
				w.printMap();
			}
			render(w);
		}*/
		/*if(userInput == 'E') {
			gameState = true;
		}*/
		if(userInput == 'P' || w.aliveCount() == 0) {
			gameState = false;
		}
		else if(userInput == 'E') {
			gameState = true;
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

