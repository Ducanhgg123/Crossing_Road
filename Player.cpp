#include "Player.h"
#include "Game.h"

Player::Player() 
{
	//score = 0;
	OFFSET_X = 0;
	OFFSET_Y = 0;
}
Player::Player(int OFFSET_X, int OFFSET_Y, int playerIndex) 
{
	//score = 0
	this->OFFSET_X = OFFSET_X;
	this->OFFSET_Y = OFFSET_Y;
	this->playerIndex = playerIndex;
	status = 1;
	vector<string> listShape;
	if (playerIndex == 1)
	{
		listShape = shape.getShape();
	}
	else
	{
		shape.changeToSnowman();
		listShape = shape.getShape();
	}
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
void Player::move(char c, int playerIndex) 
{
	int hop = 2;
	if (canMove(c, hop))
	{
		for (int i = 0; i < p.size(); i++)
		{
			if (playerIndex == 1)
			{
				if ((c == 'W' || c == 'w'))
					p[i].setY(p[i].getY() - hop);
				if ((c == 'S' || c == 's'))
					p[i].setY(p[i].getY() + hop);
				if ((c == 'A' || c == 'a'))
					p[i].setX(p[i].getX() - hop);
				if ((c == 'D' || c == 'd'))
					p[i].setX(p[i].getX() + hop);
			}
			if (playerIndex == 2)
			{
				//PlayerTwo
				if ((c == KEY_UP))
					p[i].setY(p[i].getY() - hop);
				if ((c == KEY_DOWN))
					p[i].setY(p[i].getY() + hop);
				if ((c == KEY_LEFT))
					p[i].setX(p[i].getX() - hop);
				if ((c == KEY_RIGHT))
					p[i].setX(p[i].getX() + hop);
			}
		}
	}
}

bool Player::canMove(char c, int hop)
{
	if (Game::gate.size() > 0)
	{
		for (int i = 0; i < p.size(); i++)
		{
			if ((c == 'W' || c == 'w'))
				if ((p[i].getY() - hop) <= 1 || isCollideGateBorder(p[i], hop, c))
				{
					return false;
				}

			if ((c == 'S' || c == 's'))
				if ((p[i].getY() + hop) >= 30 || isCollideGateBorder(p[i], hop, c))
				{
					return false;
				}
			if ((c == 'A' || c == 'a'))
				if ((p[i].getX() - hop) <= 0 || isCollideGateBorder(p[i], hop, c))
				{
					return false;
				}
			if ((c == 'D' || c == 'd'))
				if ((p[i].getX() + hop) >= 105 || isCollideGateBorder(p[i], hop, c))
				{
					return false;
				}
		}
	}
	else
	{
		for (int i = 0; i < p.size(); i++)
		{
			//PlayerOne
			if ((c == 'W' || c == 'w'))
				if ((p[i].getY() - hop) <= 0)
				{
					return false;
				}

			if ((c == 'S' || c == 's'))
				if ((p[i].getY() + hop) >= 30)
				{
					return false;
				}
			if ((c == 'A' || c == 'a'))
				if ((p[i].getX() - hop) <= 0)
				{
					return false;
				}
			if ((c == 'D' || c == 'd'))
				if ((p[i].getX() + hop) >= 105)
				{
					return false;
				}
			//PlayerTwo
			if ((c == KEY_UP))
				if ((p[i].getY() - hop) <= 0)
				{
					return false;
				}

			if ((c == KEY_DOWN))
				if ((p[i].getY() + hop) >= 30)
				{
					return false;
				}
			if ((c == KEY_LEFT))
				if ((p[i].getX() - hop) <= 0)
				{
					return false;
				}
			if ((c == KEY_RIGHT))
				if ((p[i].getX() + hop) >= 105)
				{
					return false;
				}
		}
	}
	return true;
}

bool Player::isCollideGateBorder(point& temp, int hop, char c)
{
	vector<point> gate = Game::gate;
	for (int i = 0; i < gate.size(); i++)
	{
		if ((c == 'W' || c == 'w'))
			if (temp.getX() == gate[i].getX() && (temp.getY()-hop) == gate[i].getY())
				return true;
		if ((c == 'S' || c == 's'))
			if (temp.getX() == gate[i].getX() && (temp.getY()+hop) == gate[i].getY())
				return true;
		if ((c == 'A' || c == 'a'))
			if ((temp.getX()-hop) == gate[i].getX() && temp.getY() == gate[i].getY())
				return true;
		if ((c == 'D' || c == 'd'))
			if ((temp.getX()+hop) == gate[i].getX() && temp.getY() == gate[i].getY())
				return true;
	}
	return false;
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

void Player::winAnimation(int playerIndex)
{
	draw();
	Sleep(500);
	int colorIndex = 240;
	for (int loop = 0; loop < 3; loop++)
	{
		vector<string> vShape;
		undraw();
		shape.changeToWin1(playerIndex);
		vShape = shape.getShape();
		int k = 0;
		for (int i = 0; i < vShape.size(); i++)
		{
			for (int j = 0; j < vShape[i].size(); j++)
			{
				p[k++].setC(vShape[i][j]);
			}
		}
		TextColor(colorIndex);
		draw();
		TextColor(colorDefault);
		Sleep(500);
		undraw();
		shape.changeToWin2(playerIndex);
		vShape = shape.getShape();

		k = 0;
		for (int i = 0; i < vShape.size(); i++)
		{
			for (int j = 0; j < vShape[i].size(); j++)
			{
				p[k++].setC(vShape[i][j]);
			}
		}
		TextColor(colorIndex);
		draw();
		TextColor(colorDefault);
		Sleep(500);
		if (colorIndex < 253)
		{
			colorIndex++;
		}
	}
	
	undraw();
	shape.changeToNormal(playerIndex);
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
void Player::deathAnimation1(int playerIndex)
{
	vector<string> vShape;
	shape.changeToLose(playerIndex);
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
	shape.changeToNormal(playerIndex);
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
int Player::getScore()
{
	return score;
}

void Player::setScore(int score)
{
	this->score = score;
}
