#pragma once
#include "point.h"
class Player {
private:
	int OFFSET_X;
	int OFFSET_Y;
	string shape[3];
	vector<point> p;
	bool status;
public:
	Player();
	Player(int, int);
	void draw();
	void undraw();
	void move(char);
	bool isAlive();
	void isHit();
	vector<point> getListPoint();
};