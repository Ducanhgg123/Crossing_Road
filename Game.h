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
	static bool twoPlayerMode;
	static int fruitRequired;
	static int fruitForThisLevel;
	static Fruit fruit;
	static int score;
	static int score2;
	static int level;
	static bool musicOn;
	static int startLine;
	static int endLine;
	static Line carLine;
	static Line dogLine;
	static Line truckLine;
	static Player player;
	static vector<CrossLine> crossLine;
	static bool isRunning;
	static bool isPaused;
	static mutex m;
	static GameControl gameControl;
public:
	Game();
	static bool checkHit();
	static void isHit();
	static void exitGame();
	static bool isColide(Player&, Obstacle*&);
	static void drawRectangle(int, int, int, int,int);
	static void startGame();
	static void restartGame();
	static void saveToFile(fstream&);
	static void loadGame(fstream&);
	static bool isCollideWithFruit(point&);
	static bool isCollideWithPlayer(point&);
	static bool playerEnterGate();
	static bool isColidePlayerWithFruit(Player, Fruit);
};