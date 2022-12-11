#include "Game.h"
int Game::level = 1;
int Game::startLine = 10;
int Game::endLine = 140;
Line Game::carLine = Line(Game::endLine+5, distanceBetweenLine );
Line Game::truckLine = Line(Game::startLine-5, 2*distanceBetweenLine);
Line Game::dogLine = Line(Game::endLine+5, 3*distanceBetweenLine);
vector<CrossLine> Game::crossLine = vector<CrossLine>();
Player Game::player = Player(65, 30);
bool Game::isRunning = 1;
bool Game::waiting = 0;
mutex Game::m;
Game::Game() {
	level = 1;
	startLine = 10;
	endLine = 130;
	carLine = Line();
	truckLine = Line();
	dogLine = Line();
	player = Player(65, 5 * distanceBetweenLine);
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
	deque<Obstacle*> listCar = carLine.getLine();
	deque<Obstacle*> listTruck = truckLine.getLine();
	deque<Obstacle*> listDog = dogLine.getLine();
	bool ok = false;
	for (int i = 0; i < listCar.size() && ok==false; i++) {
		if (isColide(player, listCar[i])) {
			ok=true;
			break;
		}
	}
	for (int i = 0; i < listTruck.size() && ok == false; i++) {
		if (isColide(player, listTruck[i])) {
			ok = true;
			break;
		}
	}
	for (int i = 0; i < listDog.size() && ok==false; i++) {
		if (isColide(player, listDog[i])) {
			ok = true;
			break;
		}
	}
	for (int i = 0; i < listCar.size(); i++)
		delete listCar[i];
	for (int i = 0; i < listTruck.size(); i++)
		delete listTruck[i];
	for (int i = 0; i < listDog.size(); i++)
		delete listDog[i];
	return ok;
}
void Game::isHit() {
	if (checkHit()) {
		exitGame();
	}
}
void Game::exitGame() {
	isRunning = false;
}