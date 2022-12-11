#pragma once
#include "Car.h"
#include "Dog.h"
#include "Truck.h"
#include "Player.h"
#include "Obstacle.h"
#include "Line.h"
#include "CrossLine.h"
#include "GameControl.h"
static class Game {
public:
	static int level;
	static int startLine;
	static int endLine;
	static Line carLine;
	static Line dogLine;
	static Line truckLine;
	static Player player;
	static vector<CrossLine> crossLine;
	static bool isRunning;
	static bool waiting;
	static mutex m;
	static GameControl gameControl;
public:
	Game();
	static bool checkHit();
	static void isHit();
	static void exitGame();
	static bool isColide(Player, Obstacle*&);
	static void drawRectangle(int, int, int, int,int);
	static void startGame();
};