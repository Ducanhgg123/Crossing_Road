#pragma once
#include "point.h"
#include "Shape.h"

class Fruit
{
	deque<point> p;
	Shape shape;
public:
	Fruit();
	Fruit(const Fruit&);
	bool initNewFruit();
	void draw();
	void undraw();
	void generateNewFruit();
	bool isCollide();
	void collisionHandle();
	deque<point> getListPoint();
};