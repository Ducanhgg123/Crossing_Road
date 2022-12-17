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
	Player(vector<point>);
	void draw();
	void undraw();
	void move(char);
	bool isAlive();
	void isHit();
	vector<point> getListPoint();
	void winAnimation();
<<<<<<< HEAD
	void deathAnimation1();
	void deathAnimation2();
	bool canMove(char, int);
	bool isCollideGateBorder(point&, int, char);
=======
<<<<<<< HEAD
	void deathAnimation();
	void deathAnimation2();
	bool canMove(char);
=======
>>>>>>> a7dc7579fe252822b262d27f2ae73f661b20a978
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
};