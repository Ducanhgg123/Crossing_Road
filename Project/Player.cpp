#include "Player.h"
Player::Player()
{
	int x = 0; 
	int y = 0; 
	shape.resize(3); 
	shape[0] = " o";
	shape[1] = "/0\\";
	shape[2] = "/ \\";
}
Player::Player(int OFFSET_X, int OFFSET_Y) {
	this->OFFSET_X = OFFSET_X;
	this->OFFSET_Y = OFFSET_Y;
	shape.resize(3); 
	shape[0] = " o";
	shape[1] = "/0\\";
	shape[2] = "/ \\";
	status = 1;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < shape[i].size(); j++)
		{
			point temp(OFFSET_X +  j, OFFSET_Y + i, shape[i][j]);
			p.push_back(temp);
		}
}
vector<string> Player::getPlayer()
{
	return shape; 
}
void Player::draw() {
	for (int i = 0; i < p.size(); i++) {
		goToXY(p[i].getX(),p[i].getY());
		cout << p[i].getC();
	}
}
void Player::undraw() {
	for (int i = 0; i < p.size(); i++) {
		goToXY(p[i].getX(), p[i].getY());
		cout << " ";
	}
}
void Player::move(char c) {
	for (int i = 0; i < p.size(); i++) {
		if (c == 'W' || c=='w') {
			p[i].setY(p[i].getY() - 1);
		}
		if (c == 'S' || c=='s')
			p[i].setY(p[i].getY() + 1);
		if (c == 'A' || c=='a')
			p[i].setX(p[i].getX() - 1);
		if (c == 'D' || c=='d')
			p[i].setX(p[i].getX() + 1);
	}
}
bool Player::isAlive() {
	return status;
}
void Player::isHit() {
	status = 0;
}
void Player::up()
{
	y--; 
}
void Player::down()
{
	y++; 
}
void Player::left()
{
	x--; 
}
void Player::right()
{
	x++; 
}
vector<point> Player::getListPoint() {
	return p;
}