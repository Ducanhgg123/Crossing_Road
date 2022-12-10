#pragma once
#include "lib.h"
#include "Obstacle.h"
class Truck :public Obstacle
{
public:
	Truck(const Truck&);
	Truck(int, int, int);
	Obstacle* clone();
};