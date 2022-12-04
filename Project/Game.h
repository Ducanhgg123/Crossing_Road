#pragma once
#include "Car.h"
#include "Dog.h"
#include "Truck.h"
#include "Player.h"
#include "Obstacle.h"
static class Game {
public:
	static int level;
	static int startLine;
	static int endLine;
	static deque<Car> carLine;
	static deque<Dog> dogLine;
	static deque<Truck> truckLine;
	static Player player;
	static bool isRunning;
public:
	static bool checkHit() {
		for (int i = 0; i < carLine.size(); i++) {
			if (isColide(player, carLine[i]))
				return true;
		}
		for (int i = 0; i < truckLine.size(); i++) {
			if (isColide(player, truckLine[i]))
				return true;
		}
		for (int i = 0; i < dogLine.size(); i++) {
			if (isColide(player, dogLine[i]))
				return true;
		}
		return false;
	}
	static void isHit() {
		if (checkHit()) {
			exitGame();
		}
	}
	static void exitGame() {
		isRunning = false;
	}
	static bool isColide(Player player, Obstacle obstacle) {
		vector<point> listPointPlayer = player.getListPoint();
		vector<point> listPointObstacle = obstacle.getListPoint();
		for (int i = 0; i < listPointPlayer.size(); i++)
			for (int j = 0; j < listPointObstacle.size(); j++) {
				if (listPointPlayer[i].getX() == listPointObstacle[j].getX() && listPointPlayer[i].getY() == listPointObstacle[j].getY())
					return true;
			}
		return false;
	}
};
int Game::level = 1;
int Game::startLine = 10;
int Game::endLine = 130;
deque<Car> Game::carLine = deque<Car>();
deque<Dog> Game::dogLine = deque<Dog>();
deque<Truck> Game::truckLine = deque<Truck>();
Player Game::player = Player(65, 30);
bool Game::isRunning = 1;