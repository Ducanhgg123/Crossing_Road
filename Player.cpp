#include "Player.h"
#include "Game.h"

Player::Player() {
	OFFSET_X = 0;
	OFFSET_Y = 0;
}
Player::Player(int OFFSET_X, int OFFSET_Y) {
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
void Player::draw() {
	//setShape1();
	for (int i = 0; i < p.size(); i++) {
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
	for (int i = 0; i < p.size(); i++) {
		if (c == 'W' || c == 'w') {
			p[i].setY(p[i].getY() - 1);
		}
		if (c == 'S' || c == 's')
			p[i].setY(p[i].getY() + 1);
		if (c == 'A' || c == 'a')
			p[i].setX(p[i].getX() - 1);
		if (c == 'D' || c == 'd')
			p[i].setX(p[i].getX() + 1);
	}
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
	
	for (int loop = 0; loop < 10; loop++)
	{
		Sleep(1000);
		vector<string> vShape;
		if (loop % 2) {
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
		}else{
			undraw();
			shape.changeToWin2();
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
		}
		
	}
	undraw();
}