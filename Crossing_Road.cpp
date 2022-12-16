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

void drawSomething() {
	int gateLength = 8; //pixels
	int gateWidth = 5;//pixels
	int startPointGate = ((Game::endLine - Game::startLine + 1) / 2 - (gateLength / 2)) + Game::startLine;
	char gatePointHorizontalChar = 'X';
	char gatePointVerticalLeftChar = 'X';
	char gatePointVerticalRightChar = 'X';

	for (int i = 0; i < gateLength; i++)
	{
		Game::m.lock();
		goToXY(startPointGate + i, 0);
		cout << gatePointHorizontalChar;
		goToXY(startPointGate + i, 1);
		cout << gatePointHorizontalChar;
		Game::m.unlock();
	}
	for (int i = 0; i < gateWidth; i++)
	{
		Game::m.lock();
		goToXY(startPointGate, i);
		cout << gatePointVerticalLeftChar;
		Game::m.unlock();
	}
	for (int i = 0; i < gateWidth; i++)
	{
		Game::m.lock();
		goToXY(startPointGate + gateLength - 1, i);
		cout << gatePointVerticalRightChar;
		Game::m.unlock();
	}
}

int main()
{
	TextColor(colorDefault);
	fixConsoleWindow();
	Game::startGame();
	return 0;
}