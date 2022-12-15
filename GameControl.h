#pragma once
class GameControl {
public:
	void clrscr();
	void drawRectangle(int, int, int, int, int);
	void drawMenu();
	void drawBorder();
	void drawLeaderboard();
	void drawGameOverPopup();
	void startGame();
	void settingGame();
	void drawInfoMenu();
	void saveGame();
	void drawScore();
	void drawGate();
	void levelUp();
	void drawFruitRequired();
};