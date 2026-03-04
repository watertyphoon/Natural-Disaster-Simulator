#include "/public/read.h" // IWYU pragma: keep
#include <cctype>
#include <unistd.h>
#include <vector>         // IWYU pragma: keep
#include "game_class.h"
#include "world_class.h"
#include "particle_class.h"
#include "/public/colors.h"
#include <list>
//#include "Bridges.h"
#include "Color.h"
#include "ColorGrid.h"
using namespace std;
using namespace bridges;



Game::Game() {
	//screen_size = { get_terminal_size() };	
	World w(screen_size.first, screen_size.second);
	frame = 0;
}
void Game::FrameRate() {
	frame++;
}
void Game::render(Particles curr) {
	const auto [ROWS, COLS] = get_terminal_size();
	//list <Particles> partList = w.getList();
	set_cursor_mode(false);
	/*movecursor(0, w.getSize_col());
	cout << BLUE << "PARTICLE: " << endl;*/
	movecursor(ROWS, 0);
/*	cout << GREEN << "START(E) PAUSE(P) QUIT(Q) LOAD(L) SAVE(V) INCREASE_FRAME_RATE(+)";
	cout << " DECREASE_FRAME_RATE(-) DRAW(d)" << RESET << endl;*/
	setbgcolor(0,0,0);
	movecursor(curr.getRow() - curr.getVeloX(), curr.getColumn() - curr.getVeloY());
	cout << ' ';
	setbgcolor(curr.getRed(),curr.getGreen(),curr.getBlue());
	movecursor(curr.getRow(), curr.getColumn());
	cout << ' ' << RESET;
	/*if(!w.getList().empty()){ 
		for(auto temp = w.getList().begin(); temp != w.getList().end();) {
			setbgcolor(temp->getRed(),temp->getGreen(),temp->getBlue());
			movecursor(temp->getRow(), temp->getColumn());
			//set_raw_mode(false);
			//movecursor(10, 10);
			//cout << temp->getRow() << " " << temp->getColumn() << endl;
			cout << ' ' << RESET << endl;
			setbgcolor(0,0,0);
		}
	}*/
}
/*void click (int row, int col) {
	//movecursor(row, col);
	mRow = row;
	mCol = col;
}*/
void Game::sprint() {
	//Bridges Data
	/*Bridges bridges(25, "gTayona", "964981320515");
	bridges.setTitle("Particle Simulation");
	bridges.setDescription("A simulation where you similate the life and death particles");
	ColorGrid cg(5, 5, Color("Black"));*/
	//here goes the splash screen
	//clearscreen();
	const auto [ROWS, COLS] = get_terminal_size();
	int mRow = 0;
	int mCol = 0;
	float fps = 100'000;
	bool gameState = false;
	bool isPart = true;
	//bool addParty = false;
	char menuInput;
	int scroll = 0;
	set_raw_mode(true);
	show_cursor(false);
	World w;
	Particles party;
	list <Particles> partList = w.getList();
	vector<vector<char>> m = w.getMap();
	w.printMap();
	//render(party);
	usleep(100000);
	//set_mouse_mode(true);
	/*cout << GREEN << "START(E) PAUSE(P) QUIT(Q) LOAD(L) SAVE(V) INCREASE_FRAME_RATE(+)";
	cout << " DECREASE_FRAME_RATE(-) DRAW(d)" << RESET << endl;*/
	while(true) {
		movecursor(0,0);
		cout << GREEN << "START(E) PAUSE(P) QUIT(Q) LOAD(L) SAVE(V) INCREASE_FRAME_RATE(+)";
		cout << " DECREASE_FRAME_RATE(-) DRAW(d)" << RESET << endl;
		set_raw_mode(false);
		movecursor(0, w.getSize_col()-18);
		cout << MAGENTA << "PARTICLE: ";
		set_raw_mode(true);
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
		else if (scroll == 7) {
			cout << "DOG      " << endl;
		}
		cout << RESET << endl;
		char userInput = toupper(quick_read());
		if(gameState) {
			for (auto temp : w.getList()) {
				//Particles curr = temp;
				render(temp);
			}

			w.jiggle_physics(m);

		}	
		//set_mouse_mode(true);
		if(!gameState) {
			set_mouse_mode(true);
			on_mousedown([&](int row, int col){
					movecursor(row, col);
					/*if(mRow == row && mCol == col) {
					addParty = false;
					}*/
					mRow = row;
					mCol = col;
					});
			//movecursor(ROWS/2, COLS/2);
			//cout << mRow << " " << mCol << endl;
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
			else if(scroll == 7) {
				party.setType(Particles::DOG);
				party.setPosition(mCol, mRow);
			}
			//cout << party.getType() << " " << party.getRow() << " " << party.getColumn() << endl; 
			w.addToList(party);
			set_mouse_mode(true);
			setbgcolor(party.getRed(), party.getGreen(), party.getBlue());
			cout << ' ' << RESET;
		}
		if(userInput == 'W' || userInput == UP_ARROW){
			if(scroll ==  7) {
				scroll = 0;
			}
			else {
				scroll++;
			}
		}
		else if(userInput == 'S' || userInput == DOWN_ARROW) {
			if (scroll == 0) {
				scroll = 7;
			}
			else {
				scroll--;
			}
		}
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
			//cout << "not implemented yet" << endl;
			//TODO: implement method to load
			w.load();	
		}
		else if(userInput == 'S') {
			//cout << "not implemente d yet" << endl;
		}
		else if(userInput == 'V') {
			//cout << "not implemente d yet" << endl;
			//TODO: implement save method
			w.save();
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
		/*else if (userInput == 'D') {
			cg.set(100, 100, Color("black")); //test	
			bridges.setDataStructure(&cg);
			bridges.visualize();
			//need to implement a bridges and draw method
		}*/
		usleep(fps);
	}
	set_cursor_mode(true);
	set_mouse_mode(false);
	set_raw_mode(false);
}

