#pragma once
#include "lib.h"
#include "Obstacle.h"
class Dog :public Obstacle
{
public:
	Dog(const Dog&);
	Dog(int, int, int);
	Obstacle* clone();
	void makeSound();
};