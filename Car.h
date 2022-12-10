#pragma once
#include "lib.h"
#include "Obstacle.h"
class Car :public Obstacle
{
public:
	Car(const Car&);
	Car(int, int, int);
	Obstacle* clone();
};