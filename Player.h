#pragma once
#include "point.h"
#include "Shape.h"
class Player {
private:
	int OFFSET_X;
	int OFFSET_Y;
	Shape shape;
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
	void winAnimation();
	void deathAnimation1();
	void deathAnimation2();
	bool canMove(char, int);
	bool isCollideGateBorder(point&, int, char);
};