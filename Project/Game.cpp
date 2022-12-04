//#include "Game.h"

//Game::Game() {
//	/*level = 1;
//	startLine = 10;
//	endLine = 130;
//	carLine = deque<Car>();
//	dogLine = deque<Dog>();
//	truckLine = deque<Truck>();
//	player = Player(65,30);
//	isRunning = 1;*/
//}
//bool Game::isColide(Player player, Obstacle obstacle) {
//	vector<point> listPointPlayer = player.getListPoint();
//	vector<point> listPointObstacle = obstacle.getListPoint();
//	for (int i=0;i<listPointPlayer.size();i++)
//		for (int j = 0; j < listPointObstacle.size(); j++) {
//			if (listPointPlayer[i].getX() == listPointObstacle[j].getX() && listPointPlayer[i].getY() == listPointObstacle[j].getY())
//				return true;
//		}
//	return false;
//}
//bool Game::checkHit() {
//	for (int i = 0; i < carLine.size(); i++) {
//		if (isColide(player, carLine[i]))
//			return true;
//	}
//	for (int i = 0; i < truckLine.size(); i++) {
//		if (isColide(player, truckLine[i]))
//			return true;
//	}
//	for (int i = 0; i < dogLine.size(); i++) {
//		if (isColide(player, dogLine[i]))
//			return true;
//	}
//	return false;
//}
//void Game::isHit() {
//	if (checkHit()) {
//		exitGame();
//	}
//}
//void Game::exitGame() {
//	isRunning = false;
//}