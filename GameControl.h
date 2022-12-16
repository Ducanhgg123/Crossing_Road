#pragma once
class GameControl {
public:
	void clrscr();
	void drawRectangle(int, int, int, int, int);
	void drawMenu();
	void drawBorder();
	void drawLeaderboard();
	void drawGameOverPopup();
	void drawLogoCrossingGame(); 
	void drawGameWinPopup(); 
	void drawPauseGamePopup(); 
	void drawSaveGamePopup(); 
	void drawLoadGamePopup(); 
	void drawContinuePopup(); 
	void drawScore(); 
	void drawLogoTeam(); 
	void drawFruitRequired(); 
	void drawInfoMenu();

	void TextColor(int); 
	void FontSize(int); 
	void startGame();
	void settingGame();
	void saveGame();
};

// draw fruit required, draw level, drawHeart