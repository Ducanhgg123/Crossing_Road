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
void TextColor(int color)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, color);
}

int main()
{
	TextColor(colorDefault);
	fixConsoleWindow();

	//thread t1(ThreadCar);
	//thread t2(ThreadTruck);
	//thread t3(ThreadDog);
	//thread t4(ThreadCrossLine);
	//Game::player.draw();
	Game::player.winAnimation();

	//while (Game::isRunning)
	//{
	//	if (Game::checkHit()) {
	//		Game::exitGame();
	//		cout << "Hitted";
	//		Game::isRunning = false;
	//		/*if (t1.joinable())
	//			t1.join();
	//		if (t2.joinable())
	//			t2.join();
	//		if (t3.joinable())
	//			t3.join();
	//		if (t4.joinable())
	//			t4.join();*/
	//		return 0;
	//	}
	//	int temp = toupper(_getch());
	//	if (temp == 27) {
	//		Game::isRunning = false;
	//		/*if (t1.joinable())
	//			t1.join();
	//		if (t2.joinable())
	//			t2.join();
	//		if (t3.joinable())
	//			t3.join();
	//		if (t4.joinable())
	//			t4.join();*/
	//		return 0;
	//	}
	//	Game::player.undraw();
	//	Game::player.move(char(temp));
	//	Game::player.draw();
	//}
	///*if (t1.joinable())
	//	t1.join();
	//if (t2.joinable())
	//	t2.join();
	//if (t3.joinable())
	//	t3.join();
	//if (t4.joinable())
	//	t4.join();*/
	return 0;
}