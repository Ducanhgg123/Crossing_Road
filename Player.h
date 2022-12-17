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
	int playerIndex;
	int score;
public:
	Player();
	Player(int, int, int);
	void draw();
	void undraw();
	void move(char, int);
	bool isAlive();
	void isHit();
	vector<point> getListPoint();
	void winAnimation(int);
	void deathAnimation1(int);
	void deathAnimation2();
	bool canMove(char, int);
	bool isCollideGateBorder(point&, int, char);
	int getScore();
	void setScore(int );
};