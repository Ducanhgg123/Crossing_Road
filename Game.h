#pragma once
#include "Car.h"
#include "Dog.h"
#include "Truck.h"
#include "Player.h"
#include "Obstacle.h"
#include "Line.h"
#include "CrossLine.h"
#include "GameControl.h"
#include "Fruit.h"
static class Game {
public:
	static int level;
	static int score;
	static int fruitRequired;
	static int fruitForThisLevel;
	static int startLine;
	static int endLine;
	static Line carLine;
	static Line dogLine;
	static Line truckLine;
	static Player player;
	static vector<CrossLine> crossLine;
	static Fruit fruit;
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
	static bool isColidePlayerWithFruit(Player, Fruit);
	static void drawRectangle(int, int, int, int,int);
	static void startGame();
	static bool isCollideWithFruit(point&);
	static bool isCollideWithPlayer(point&);
	static void restartGame();
	static bool playerEnterGate();
};