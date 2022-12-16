#pragma once
#include "lib.h"
#include "Obstacle.h"
class Truck :public Obstacle
{
public:
	Truck(const Truck&);
	Truck(int, int, int);
	Truck(int, int, vector<point>, int, int);
	Obstacle* clone();
	void makeSound();
	friend ostream& operator<<(ostream&, const Truck&);
};