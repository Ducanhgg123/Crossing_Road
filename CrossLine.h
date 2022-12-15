#pragma once
#include "point.h"

class CrossLine
{
	deque<point> p;
	int length;
public:
	CrossLine();
	CrossLine(int x, int y,int);
	int getLength();
	void draw();
	void undraw();
	bool isCollideWithPlayer(point p);
	vector<point> getListPoint();
};