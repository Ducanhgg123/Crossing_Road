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
	void loadGame(string);
	void pauseGame();
	void resumeGame();
	void drawScore();
	void drawGate();
	void levelUp();
	void drawFruitRequired();
	void turnOnMusic();
	void turnOffMusic();
	void playBackgroundMusic();
	void playMenuMusic();
	void drawLogoCrossingGame();
	void drawLoadGamePopup();
	void drawLogoTeam();
	void drawLevel();
	void drawPauseGamePopup();
};