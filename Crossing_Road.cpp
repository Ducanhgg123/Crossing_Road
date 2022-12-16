#pragma once
#include "lib.h"
#include "Game.h"
void showConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}
void fixConsoleWindow()
{
	HWND hwnd = GetConsoleWindow();
	RECT rect = { 50, 50, 1500, 800 };
	MoveWindow(hwnd, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, TRUE);
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);

	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);

	showConsoleCursor(false);

}

void ConsoleColor(int c = 240)
{

}

int main()
{
	/*for (int i = 240; i <= 260; i++) {
		Game::gameControl.TextColor(i); 
		cout << "hello" << i << endl; 
	}*/

	fixConsoleWindow();
	Game::gameControl.drawMenu();
	/*Game::gameControl.drawGameOverPopup(); */
	//Game::gameControl.drawPauseGamePopup(); 
	
	//Game::gameControl.drawPauseGamePopup();
	//Game::gameControl.drawLoadGamePopup(); 
	
	
	while (1);
	return 0;
}