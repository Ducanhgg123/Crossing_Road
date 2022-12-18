#pragma once
#include "lib.h"
#include "Obstacle.h"
class Car :public Obstacle
{
public:
	Car(const Car&);
	Car(int, int, int);
	Car(int,int,vector<point>, int, int);
	Obstacle* clone();
	void makeSound();
	friend ostream& operator<<(ostream&, const Car&);
};