#pragma once
#include "point.h"
#include <deque>

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
};