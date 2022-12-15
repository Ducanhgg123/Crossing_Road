#include "Player.h"
#include "Game.h"

Player::Player() 
{
	OFFSET_X = 0;
	OFFSET_Y = 0;
}
Player::Player(int OFFSET_X, int OFFSET_Y) 
{
	this->OFFSET_X = OFFSET_X;
	this->OFFSET_Y = OFFSET_Y;
	status = 1;
	vector<string> listShape = shape.getShape();
	for (int i = 0; i < listShape.size(); i++)
		for (int j = 0; j < listShape[i].size(); j++)
		{
			point temp(OFFSET_X + j, OFFSET_Y + i, listShape[i][j]);
			p.push_back(temp);
		}
}
void Player::draw() 
{
	//setShape1();
	for (int i = 0; i < p.size(); i++) 
	{
		Game::m.lock();
		goToXY(p[i].getX(), p[i].getY());
		cout << p[i].getC();
		Game::m.unlock();
	}
}
void Player::undraw() {
	for (int i = 0; i < p.size(); i++) {
		Game::m.lock();
		goToXY(p[i].getX(), p[i].getY());
		cout << " ";
		Game::m.unlock();
	}
}
void Player::move(char c) {
	int hop = 3;
	if (canMove(c))
	{
		for (int i = 0; i < p.size(); i++) 
		{
			if ((c == 'W' || c == 'w') && p[i].getY() >= 3) {
				p[i].setY(p[i].getY() - hop);
			}
			if ((c == 'S' || c == 's') && p[i].getY() <= 32)
				p[i].setY(p[i].getY() + hop);
			if ((c == 'A' || c == 'a') && p[i].getX() >= 3)
				p[i].setX(p[i].getX() - hop);
			if ((c == 'D' || c == 'd') && p[i].getX() <= 102)
				p[i].setX(p[i].getX() + hop);
		}
	}
}

bool Player::canMove(char c)
{
	int hop = 3;
	for (int i = 0; i < p.size(); i++) {
		if ((c == 'W' || c == 'w'))
			if (!(p[i].getY() >= 3))
				return false;
		if ((c == 'S' || c == 's') )
			if (!(p[i].getY() <= 32))
				return false;
		if ((c == 'A' || c == 'a'))
			if (!(p[i].getX() >= 3))
				return false;
		if ((c == 'D' || c == 'd') )
			if (!(p[i].getX() <= 105))
				return false;
	}
	return true;
}

bool Player::isAlive() {
	return status;
}
void Player::isHit() {
	status = 0;
}
vector<point> Player::getListPoint() {
	return p;
}

void Player::winAnimation()
{
	draw();
	Sleep(2000);
	for (int loop = 0; loop < 3; loop++)
	{
		vector<string> vShape;
		undraw();
		shape.changeToWin1();
		vShape = shape.getShape();
		int k = 0;
		for (int i = 0; i < vShape.size(); i++)
		{
			for (int j = 0; j < vShape[i].size(); j++)
			{
				p[k++].setC(vShape[i][j]);
			}
		}
		draw();
		Sleep(1000);
		undraw();
		shape.changeToWin2();
		vShape = shape.getShape();
			
		k = 0;
		for (int i = 0; i < vShape.size(); i++)
		{
			for (int j = 0; j < vShape[i].size(); j++)
			{
				p[k++].setC(vShape[i][j]);
			}
		}
		draw();
		Sleep(1000);
		
	}
	undraw();
	shape.changeToNormal();
	vector<string> vShape;
	vShape = shape.getShape();
	int k = 0;
	for (int i = 0; i < vShape.size(); i++)
	{
		for (int j = 0; j < vShape[i].size(); j++)
		{
			p[k++].setC(vShape[i][j]);
		}
	}
}

void Player::deathAnimation1()
{
	vector<string> vShape;
	shape.changeToLose();
	vShape = shape.getShape();
	int k = 0;
	for (int i = 0; i < vShape.size(); i++)
	{
		for (int j = 0; j < vShape[i].size(); j++)
		{
			p[k++].setC(vShape[i][j]);
		}
	}
	for (int i = 0; i < 3; i++)
	{
		Sleep(100);
		undraw();
		Sleep(100);
		draw();
	}
	for (int i = 0; i < 5; i++)
	{
		Sleep(50);
		undraw();
		Sleep(50);
		draw();
	}
	undraw();
	shape.changeToNormal();
	vShape.clear();
	vShape = shape.getShape();
	k = 0;
	for (int i = 0; i < vShape.size(); i++)
	{
		for (int j = 0; j < vShape[i].size(); j++)
		{
			p[k++].setC(vShape[i][j]);
		}
	}
}

void Player::deathAnimation2()
{
	int center = p.size() / 2;
	char c = 'O';
	int r = 4;
	int sleepTime = 50;
	for (int loop = 0; loop < 3; loop++)
	{
		goToXY(p[center].getX(), p[center].getY());
		cout << c;
		Sleep(sleepTime);
		goToXY(p[center].getX(), p[center].getY());
		cout << " ";
		
		int i = 1;
		goToXY(p[center].getX() -i, p[center].getY());
		cout << c;
		goToXY(p[center].getX() , p[center].getY() - i);
		cout << c;
		goToXY(p[center].getX() + i, p[center].getY());
		cout << c;
		goToXY(p[center].getX(), p[center].getY() + i);
		cout << c;
		Sleep(sleepTime);
		goToXY(p[center].getX() - i, p[center].getY());
		cout << " ";
		goToXY(p[center].getX(), p[center].getY() - i);
		cout << " ";
		goToXY(p[center].getX() + i, p[center].getY());
		cout << " ";
		goToXY(p[center].getX(), p[center].getY() + i);
		cout << " ";
		for (int j = 1; j < r; j++)
		{
			goToXY(p[center].getX() - i, p[center].getY() - i);
			cout << c;
			goToXY(p[center].getX() + i, p[center].getY() - i);
			cout << c;
			goToXY(p[center].getX() + i, p[center].getY() + i);
			cout << c;
			goToXY(p[center].getX() - i, p[center].getY() + i);
			cout << c;
			i = i+j;
			goToXY(p[center].getX() - i, p[center].getY());
			cout << c;
			goToXY(p[center].getX(), p[center].getY() - i);
			cout << c;
			goToXY(p[center].getX() + i, p[center].getY());
			cout << c;
			goToXY(p[center].getX(), p[center].getY() + i);
			cout << c;

			i =i-j;
			Sleep(sleepTime);
			goToXY(p[center].getX() - i, p[center].getY() - i);
			cout << " ";
			goToXY(p[center].getX() + i, p[center].getY() - i);
			cout << " ";
			goToXY(p[center].getX() + i, p[center].getY() + i);
			cout << " ";
			goToXY(p[center].getX() - i, p[center].getY() + i);
			cout << " ";
			i = i + j;
			goToXY(p[center].getX() - i, p[center].getY());
			cout << " ";
			goToXY(p[center].getX(), p[center].getY() - i);
			cout << " ";
			goToXY(p[center].getX() + i, p[center].getY());
			cout << " ";
			goToXY(p[center].getX(), p[center].getY() + i);
			cout << " ";
		}
		Sleep(200);
	}
}