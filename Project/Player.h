#pragma once
#include "point.h"
class Player {
private:
	int OFFSET_X;
	int OFFSET_Y;
	vector<string> shape;
	vector<point> p;
	bool status;
public:
	int x;
	int y;
	Player(); 
	Player(int,int);
	vector<string> getPlayer(); 
	void draw(); 
	void undraw();
	void move(char);
	bool isAlive();
	void isHit();
	void up(); 
	void down(); 
	void left(); 
	void right(); 
	vector<point> getListPoint();
};