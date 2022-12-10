#include "Game.h"
int Game::level = 1;
int Game::startLine = 10;
int Game::endLine = 130;
deque<Car> Game::carLine = deque<Car>();
deque<Dog> Game::dogLine = deque<Dog>();
deque<Truck> Game::truckLine = deque<Truck>();
Player Game::player = Player(65, 30);
bool Game::isRunning = 1;
bool Game::waiting = 0;
mutex Game::m;
Game::Game() {
	level = 1;
	startLine = 10;
	endLine = 130;
	carLine = deque<Car>();
	dogLine = deque<Dog>();
	truckLine = deque<Truck>();
	player = Player(65,30);
	isRunning = 1;
}
bool Game::isColide(Player player, Obstacle*& obstacle) {
	vector<point> listPointPlayer = player.getListPoint();
	vector<point> listPointObstacle = obstacle->getListPoint();
	for (int i=0;i<listPointPlayer.size();i++)
		for (int j = 0; j < listPointObstacle.size(); j++) {
			if (listPointPlayer[i].getX() == listPointObstacle[j].getX() && listPointPlayer[i].getY() == listPointObstacle[j].getY())
				return true;
		}
	return false;
}
bool Game::checkHit() {
	for (int i = 0; i < carLine.size(); i++) {
		Obstacle* o = carLine[i].clone();
		if (isColide(player, o)) {
			delete o;
			return true;
		}
		delete o;
	}
	for (int i = 0; i < truckLine.size(); i++) {
		Obstacle* o = truckLine[i].clone();
		if (isColide(player, o)) {
			delete o;
			return true;
		}
		delete o;
	}
	for (int i = 0; i < dogLine.size(); i++) {
		Obstacle* o = dogLine[i].clone();
		if (isColide(player, o)) {
			delete o;
			return true;
		}
		delete o;
	}
	return false;
}
void Game::isHit() {
	if (checkHit()) {
		exitGame();
	}
}
void Game::exitGame() {
	isRunning = false;
}