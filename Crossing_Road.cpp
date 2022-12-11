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

void ConsoleColor(int c = 240)
{

}
//void goToXY(int x, int y)
//{
//	COORD coord;
//
//	coord.X = x;
//	coord.Y = y;
//
//	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
//}
//
//
//class Wall
//{
//
//};
//
//class point
//{
//	COORD c;
//	char ch;
//public:
//	point()
//	{
//		c.X = 0;
//		c.Y = 0;
//		ch = 0;
//	};
//	point(COORD c, char ch)
//	{
//		this->c = c;
//		this->ch = ch;
//	};
//	void increaseX()
//	{
//		this->c.X++;
//	}
//	void increaseY()
//	{
//		this->c.Y++;
//	}
//	COORD getCoord()
//	{
//		return this->c;
//	}
//	//getter
//	int cX()
//	{
//		return this->c.X;
//	}
//	int cY()
//	{
//		return this->c.Y;
//	}
//	char getChar()
//	{
//		return this->ch;
//	}
//};
//
//
//class Car
//{
//	deque<point> p;
//	string a = " _.-.___\\__";
//	string b = "|  _      _`-.";
//	string c = "'-(_)----(_)--`";
//	int size;
//public:
//	Car()
//	{
//		for (int i = 0; i < 3; i++)
//		{
//			COORD temp;
//			temp.Y = OFFSET_Y + i;
//			if (i == 0)
//			{
//				for (int j = 0; j < 11; j++)
//				{
//					temp.X = OFFSET_X + j;
//					point tempP(temp, a[j]);
//					p.push_back(tempP);
//				}
//			}
//			else if (i == 1)
//			{
//				for (int j = 0; j < 15; j++)
//				{
//					temp.X = OFFSET_X + j;
//					point tempP(temp, b[j]);
//					p.push_back(tempP);
//				}
//			}
//			else if (i == 2)
//			{
//				for (int j = 0; j < 16; j++)
//				{
//					temp.X = OFFSET_X + j;
//					point tempP(temp, c[j]);
//					p.push_back(tempP);
//				}
//			}
//		}
//		size = p.size();
//	}
//	Car(const Car& temp)
//	{
//		*this = temp;
//	}
//	int getSize()
//	{
//		return this->size;
//	}
//	Car& operator++()
//	{
//		for (int i = 0; i < p.size(); i++)
//		{
//			p[i].increaseX();
//		}
//		return *this;
//	}
//	Car operator++(int x)
//	{
//		Car temp(*this);
//		++(*this);
//		return temp;
//	}
//	bool isColide(const COORD& coord)
//	{
//		for (int i = 0; i < p.size(); i++)
//		{
//			if (p[i].cX() == coord.X && p[i].cY() == coord.Y)
//			{
//				return true;
//			}
//		}
//		return false;
//	}
//	friend ostream& operator<<(ostream& out, Car& car)
//	{
//		for (int i = 0; i < car.p.size(); i++)
//		{
//			goToXY(car.p[i].cX(), car.p[i].cY());
//			cout << car.p[i].getChar();
//		}
//		return out;
//	}
//	void undrawCar1()
//	{
//		goToXY(p[0].cX(), p[0].cY());
//		cout << " ";
//		goToXY(p[11].cX(), p[11].cY());
//		cout << " ";
//		goToXY(p[26].cX(), p[26].cY());
//		cout << " ";
//	}
//	void undrawCar2()
//	{
//		for (int i = 0; i < p.size(); i++)
//		{
//			goToXY(p[i].cX(), p[i].cY());
//			cout <<" ";
//		}
//	}
//	COORD getCoord()
//	{
//		return p[0].getCoord();
//	}
//};

void ThreadCar()
{
	if (Game::carLine.getLineSize() == 0)
		Game::carLine.insertNewObstacle(new Car(Game::startLine, distanceBetweenLine + 1, 1));
	Game::carLine.makeSound();
	while (Game::isRunning)
	{
		Sleep(10);
		Game::carLine.updateTrafficLight();
		if (Game::carLine.isRed())
			Sleep(1000);
		if (Game::carLine.getLineSize() == 0)
			Game::carLine.insertNewObstacle(new Car(Game::startLine, distanceBetweenLine + 1, 1));
		else if (Game::carLine.getLineSize() < 4 && Game::carLine.canAddNewObstacle())
			Game::carLine.insertNewObstacle(new Car(Game::startLine, distanceBetweenLine  + 1, 1));
		Game::carLine.move();
		Game::carLine.deleteReachEndPoint(Game::endLine);
		if (Game::checkHit()) {
			Game::exitGame();
			cout << "Hitted";
		}
	}
}
void ThreadTruck()
{
	if (Game::truckLine.getLineSize() == 0)
		Game::truckLine.insertNewObstacle(new Truck(Game::endLine, 2*distanceBetweenLine + 1, -1));
	Game::truckLine.makeSound();
	while (Game::isRunning)
	{
		Sleep(10);
		Game::truckLine.updateTrafficLight();
		if (Game::truckLine.isRed())
			Sleep(1000);
		if (Game::truckLine.getLineSize() == 0)
			Game::truckLine.insertNewObstacle(new Truck(Game::endLine, 2*distanceBetweenLine + 1, -1));
		else if (Game::truckLine.getLineSize() < 3 && Game::truckLine.canAddNewObstacle())
			Game::truckLine.insertNewObstacle(new Truck(Game::endLine, 2 * distanceBetweenLine + 1, -1));
		Game::truckLine.move();
		Game::truckLine.deleteReachEndPoint(Game::startLine);
		if (Game::checkHit()) {
			Game::exitGame();
			cout << "Hitted";
		}
	}
}
//void ThreadDogSound() {
//	while (Game::isRunning) {
//		PlaySound(TEXT("mixkit-dog-barking-twice-1.wav"), NULL, SND_ASYNC);
//		Sleep(2000);
//	}
//}
void ThreadDog()
{
	if (Game::dogLine.getLineSize() == 0)
		Game::dogLine.insertNewObstacle(new Dog(Game::startLine, 3 * distanceBetweenLine + 1, 1));
	Game::dogLine.makeSound();
	while (Game::isRunning)
	{
		Sleep(10);
		Game::dogLine.updateTrafficLight();
		if (Game::dogLine.isRed())
			Sleep(1000);
		if (Game::dogLine.getLineSize() == 0)
			Game::dogLine.insertNewObstacle(new Dog(Game::startLine, 3 * distanceBetweenLine + 1, 1));
		else if (Game::dogLine.getLineSize() < 4 && Game::dogLine.canAddNewObstacle())
			Game::dogLine.insertNewObstacle(new Dog(Game::startLine, 3 * distanceBetweenLine + 1, 1));
		Game::dogLine.move();
		Game::dogLine.deleteReachEndPoint(Game::endLine);
		if (Game::checkHit()) {
			Game::exitGame();
			cout << "Hitted";
			Game::isRunning = false;
		}
	}
	
}
//void ThreadPlayer()
//{
//	while (Game::isRunning)
//	{
//		
//	}
//}
void ThreadCrossLine()
{
	for (int i = 0; i < 4; i++)
	{
		Game::crossLine.push_back(CrossLine(Game::startLine, distanceBetweenLine*(i+1), Game::endLine - Game::startLine));
	}
	while (Game::isRunning)
	{
		Sleep(10);
		for (int i = 0; i < 4; i++)
		{
			Game::crossLine[i].draw();
		}
	}
}
int main()
{
	TextColor(colorDefault);
	fixConsoleWindow();

	thread t1(ThreadCar);
	thread t2(ThreadTruck);
	thread t3(ThreadDog);
	thread t4(ThreadCrossLine);
	Game::player.draw();
	while (Game::isRunning)
	{
		if (Game::checkHit()) {
			Game::exitGame();
			cout << "Hitted";
			Game::isRunning = false;
			if (t1.joinable())
				t1.join();
			if (t2.joinable())
				t2.join();
			if (t3.joinable())
				t3.join();
			if (t4.joinable())
				t4.join();
			return 0;
		}
		int temp = toupper(_getch());
		if (temp == 27) {
			Game::isRunning = false;
			if (t1.joinable())
				t1.join();
			if (t2.joinable())
				t2.join();
			if (t3.joinable())
				t3.join();
			if (t4.joinable())
				t4.join();
			return 0;
		}
		Game::player.undraw();
		Game::player.move(char(temp));
		Game::player.draw();
	}
	if (t1.joinable())
		t1.join();
	if (t2.joinable())
		t2.join();
	if (t3.joinable())
		t3.join();
	if (t4.joinable())
		t4.join();
	return 0;
}