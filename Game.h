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
	static bool waiting;
	static mutex m;
public:
	Game();
	static bool checkHit();
	static void isHit();
	static void exitGame();
	static bool isColide(Player, Obstacle*&);
};