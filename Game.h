#pragma once
#include "Car.h"
#include "Dog.h"
#include "Truck.h"
#include "Player.h"
#include "Obstacle.h"
#include "Line.h"
static class Game {
public:
	static int level;
	static int startLine;
	static int endLine;
	static Line carLine;
	static Line dogLine;
	static Line truckLine;
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