#pragma once
#include "lib.h"
class GameControl {
public:
	void clrscr();
	void drawRectangle(int, int, int, int, int);
	void undrawRectangle(int, int, int, int);
	void drawMenu();
	void drawBorder();
	void drawLeaderboard();
	void drawGameOverPopup();
	void startGame();
	void settingGame();
	void drawInfoMenu();
	void saveGame();
<<<<<<< HEAD
=======
	void loadGame(string);
	void pauseGame();
	void resumeGame();
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
	void drawScore();
	void drawGate();
	void levelUp();
	void drawFruitRequired();
<<<<<<< HEAD
=======
	void turnOnMusic();
	void turnOffMusic();
	void playBackgroundMusic();
	void playMenuMusic();
	void drawLogoCrossingGame();
	void drawLoadGamePopup();
	void drawLogoTeam();
	void drawLevel();
	void drawPauseGamePopup();
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
};