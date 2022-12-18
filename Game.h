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
<<<<<<< HEAD
	static int score;
	static int fruitRequired;
	static int fruitForThisLevel;
=======
	static bool musicOn;
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
	static int startLine;
	static int endLine;
	static Line carLine;
	static Line dogLine;
	static Line truckLine;
	static Player player;
	static Player playerTwo;
	static vector<CrossLine> crossLine;
	static Fruit fruit;
	static vector<point> gate;
	static bool isRunning;
<<<<<<< HEAD
	static bool waiting;
	static bool isInTwoPlayerMode;
=======
	static bool isPaused;
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
	static mutex m;
	static GameControl gameControl;
	
public:
	Game();
	static bool checkHit(Player&);
	static void isHit(Player&);
	static void exitGame();
	static bool isColide(Player&, Obstacle*&);
<<<<<<< HEAD
	static bool isColidePlayerWithFruit(Player&, Fruit&);
	static void drawRectangle(int, int, int, int,int);
	static void startGame();
	static bool isCollideWithFruit(point&);
	static bool isCollideWithPlayer(point&, Player&);
	static void restartGame();
	static bool playerEnterGate(Player&);
	static void generateGate();
=======
	static void drawRectangle(int, int, int, int,int);
	static void startGame();
	static void restartGame();
	static void saveToFile(fstream&);
	static void loadGame(fstream&);
	static bool isCollideWithFruit(point&);
	static bool isCollideWithPlayer(point&);
	static bool playerEnterGate();
	static bool isColidePlayerWithFruit(Player, Fruit);
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
};