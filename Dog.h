#pragma once
#include "lib.h"
#include "Obstacle.h"
class Dog :public Obstacle
{
public:
	Dog(const Dog&);
	Dog(int, int, int);
	Dog(int, int, vector<point>, int, int);
	Obstacle* clone();
	void makeSound();
	friend ostream& operator<<(ostream&, const Dog&);
};