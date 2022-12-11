#pragma once
#include "Car.h"
#include "Dog.h"
#include "Truck.h"
#include "Player.h"
#include "Obstacle.h"
#include<map>
#include<iostream>
#include<fstream>
using namespace std; 


#define KEY_ESC 27
#define DEFAULT_COLOR 10

#define KEY_DOWN 80
#define KEY_UP 72
#define KEY_ESC 27
#define KEY_ENTER 13

#define DOWN_BLACK_PIECE char(220)
#define UP_BLACK_PIECE char(223)
#define VERTICAL_BLACK_PIECE char(219)
#define BLOCK char(254)

#define WIDTH 50
#define HEIGHT 50

static class Game {
public:
	static int level;
	static int startLine;
	static int endLine;
	static deque<Car> carLine;
	static deque<Dog> dogLine;
	static deque<Truck> truckLine;
	Player player;
	static bool isRunning;
	static bool waiting;
	static mutex m;
	void drawRectangle(int offsetX, int offsetY, int width, int height, int color); 

public:
	Game(); 
	static bool checkHit(); 
	static void isHit(); 
	void showConsoleCursor(bool showFlag); 
	static void exitGame(); 
	static bool isColide(Player player, Obstacle obstacle); 
	static void removeCursor(); 
	static void FixConsoleWindow();
	static void SetWindowSize(SHORT width, SHORT height);
	static void gotoOxy(int x, int y);
	static void clrscr();
	static void txtColor(int color); 
	void startGame();
	void settingGame();
	void drawMenu();
	void menu(int active, int color); 
	void drawBorder();
	void drawModal(); 
	void drawInfoMenu(); 
	void drawLoserScreen(); 
	void drawLeaderboardScreen();

	void saveGame(string name); 
	void loadGame(); 
	void getPlayerFromFile(string name); 
};



