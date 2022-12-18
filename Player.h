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
<<<<<<< HEAD
	Player(int, int, int);
=======
	Player(int, int);
	Player(vector<point>);
>>>>>>> fdb4b171e8ae21e71034e42e9187fdc21519fe2f
	void draw();
	void undraw();
	void move(char, int);
	bool isAlive();
	void isHit();
	vector<point> getListPoint();
<<<<<<< HEAD
	void winAnimation(int);
	void deathAnimation1(int);
	void deathAnimation2();
	bool canMove(char, int);
	bool isCollideGateBorder(point&, int, char);
	int getScore();
	void setScore(int );
=======
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
>>>>>>> fdb4b171e8ae21e71034e42e9187fdc21519fe2f
};