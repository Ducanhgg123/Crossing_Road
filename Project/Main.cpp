#include "lib.h"
#include "Game.h"
#include <cstdlib>
#include <ctime>
#include <iostream>
#include<random>
using namespace std;

void randomNumber() {
	random_device rd; // obtain a random number from hardware
	mt19937 gen(rd()); // seed the generator
	uniform_int_distribution<> distr(4, 8); // define the range

	for (int n = 0; n < 10; ++n)
		cout << distr(gen) << ' '; // generate numbers
}

void printFromPosition(int x, int y, int width, int height,vector<string> player) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			Game::gotoOxy(x + j, y + i);
			cout << player[i][j];
		}
	}
}
void deleteFromPosition(int x, int y, int width, int height,vector<string> player) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			Game::gotoOxy(x + j, y + i);
			cout << ' ';
		}
	}
}
int Game::level = 1;
int Game::startLine = 10;
int Game::endLine = 130;
deque<Car> Game::carLine = deque<Car>();
deque<Dog> Game::dogLine = deque<Dog>();
deque<Truck> Game::truckLine = deque<Truck>();
Player Game::player = Player(65, 30);
bool Game::isRunning = 1;

int main()
{
	Game::SetWindowSize(500, 200); 
	Game::FixConsoleWindow(); 

	//Game game; 
	//game.drawMenu(); 
	randomNumber(); 

	return 0;
}

//while (Game::isRunning)
//{
//	if (Game::checkHit()) {
//		Game::isHit();
//		cout << "Hitted";
//		Game::isRunning = false;
//		return 0;
//	}
//
//	if (_kbhit()) {
//		char c = _getch();
//		if (c == 'w') {
//			deleteFromPosition(player.x, player.y, 3, 3, player.getPlayer());
//			player.up();
//			printFromPosition(player.x, player.y, 3, 3, player.getPlayer());
//		}
//		if (c == 's') {
//			deleteFromPosition(player.x, player.y, 3, 3, player.getPlayer());
//			player.down();
//			printFromPosition(player.x, player.y, 3, 3, player.getPlayer());
//		}
//		if (c == 'a') {
//			deleteFromPosition(player.x, player.y, 3, 3, player.getPlayer());
//			player.left();
//			printFromPosition(player.x, player.y, 3, 3, player.getPlayer());
//		}
//		if (c == 'd') {
//			deleteFromPosition(player.x, player.y, 3, 3, player.getPlayer());
//			player.right();
//			printFromPosition(player.x, player.y, 3, 3, player.getPlayer());
//		}
//	}
//	if (Game::carLine.size() == 0)
//	{
//		Game::carLine.push_back(Car(Game::startLine, 10, 1));
//	}
//	else if (Game::carLine.size() < 4 && Game::carLine[Game::carLine.size() - 1].getDistanceFromStart() > Game::carLine[Game::carLine.size() - 1].getDistance())
//		Game::carLine.push_back(Car(Game::startLine, 10, 1));
//	for (int i = 0; i < Game::carLine.size(); i++) {
//		Game::carLine[i].undrawBack();
//		Game::carLine[i].move();
//		Game::carLine[i].draw();
//	}
//	if (Game::carLine[0].reachEndPoint(Game::endLine)) {
//		Game::carLine[0].undraw();
//		Game::carLine.pop_front();
//	}
//
//	//Truck
//	if (Game::truckLine.size() == 0)
//	{
//		Game::truckLine.push_back(Truck(Game::endLine, 15, -1));
//	}
//	else if (Game::truckLine.size() < 3 && Game::truckLine[Game::truckLine.size() - 1].getDistanceFromStart() > Game::truckLine[Game::truckLine.size() - 1].getDistance())
//		Game::truckLine.push_back(Truck(Game::endLine, 15, -1));
//	for (int i = 0; i < Game::truckLine.size(); i++) {
//		Game::truckLine[i].undrawBack();
//		Game::truckLine[i].move();
//		Game::truckLine[i].draw();
//	}
//	if (Game::truckLine[0].reachEndPoint(Game::startLine)) {
//		Game::truckLine[0].undraw();
//		Game::truckLine.pop_front();
//	}
//}
