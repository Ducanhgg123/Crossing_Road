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
	while (Game::isRunning)
	{
		Sleep(10);
		if (Game::carLine.size() == 0)
		{
			Game::carLine.push_back(Car(Game::startLine, 10, 1));
		}
		else if (Game::carLine.size() < 4 && Game::carLine[Game::carLine.size() - 1].getDistanceFromStart() > Game::carLine[Game::carLine.size() - 1].getDistance())
			Game::carLine.push_back(Car(Game::startLine, 10, 1));
		for (int i = 0; i < Game::carLine.size(); i++) {
			Game::carLine[i].undrawBack();
			Game::carLine[i].move();
			Game::carLine[i].draw();
		}
		if (Game::carLine[0].reachEndPoint(Game::endLine)) {
			Game::carLine[0].undraw();
			Game::carLine.pop_front();
		}
	}
}
void ThreadTruck()
{
	while (Game::isRunning)
	{
		Sleep(10);
		//Truck
		if (Game::truckLine.size() == 0)
		{
			Game::truckLine.push_back(Truck(Game::endLine, 15, -1));
		}
		else if (Game::truckLine.size() < 3 && Game::truckLine[Game::truckLine.size() - 1].getDistanceFromStart() > Game::truckLine[Game::truckLine.size() - 1].getDistance())
			Game::truckLine.push_back(Truck(Game::endLine, 15, -1));
		for (int i = 0; i < Game::truckLine.size(); i++) {
			Game::truckLine[i].undrawBack();
			Game::truckLine[i].move();
			Game::truckLine[i].draw();
		}
		if (Game::truckLine[0].reachEndPoint(Game::startLine)) {
			Game::truckLine[0].undraw();
			Game::truckLine.pop_front();
		}
		if (Game::checkHit()) {
			Game::exitGame();
			cout << "Hitted";
		}
	}
}
void ThreadDog()
{

	while (Game::isRunning)
	{
		Sleep(10);
		//Dog
		if (Game::dogLine.size() == 0 && !Game::waiting)
		{
			Game::dogLine.push_back(Dog(Game::startLine, 20, 1));
		}
		else if (Game::dogLine.size() < 4 && Game::dogLine[Game::dogLine.size() - 1].getDistanceFromStart() > Game::dogLine[Game::dogLine.size() - 1].getDistance() && !Game::waiting)
			Game::dogLine.push_back(Dog(Game::startLine, 20, 1));
		for (int i = 0; i < Game::dogLine.size(); i++) {
			Game::dogLine[i].undrawBack();
			Game::dogLine[i].move();
			Game::dogLine[i].draw();
		}
		if (Game::dogLine[0].reachEndPoint(Game::endLine)) {
			Game::dogLine[0].undraw();
			Game::dogLine.pop_front();
		}
		if (Game::checkHit()) {
			Game::exitGame();
			cout << "Hitted";
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
int main()
{
	fixConsoleWindow();

	/*thread t1(ThreadCar);
	thread t2(ThreadTruck);
	thread t3(ThreadDog);
	Game::player.draw();
	TrafficLight tmp(0, 0);
	while (Game::isRunning)
	{
		if (Game::checkHit()) {
			Game::exitGame();
			cout << "Hitted";
			Game::isRunning = false;
			t1.join();
			return 0;
		}
		int temp = toupper(_getch());
		if (temp == 27) {
			Game::isRunning = false;
			t1.join();
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
		t3.join();*/
	Line line;

	while (1)
	{
		//Sleep(10);
		if (line.getLineSize() == 0)
			line.insertNewObstacle(new Car(Game::startLine, 10, 1));
		else if (line.getLineSize() < 4 && line.getObstacleAt(line.getLineSize() - 1)->getDistanceFromStart() > line.getObstacleAt(line.getLineSize() - 1)->getDistance())
			line.insertNewObstacle(new Car(Game::startLine, 10, 1));
		line.move();
		line.deleteReachEndPoint();
	}
	return 0;
}