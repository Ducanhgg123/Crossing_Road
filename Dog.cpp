#include "Dog.h"
Dog::Dog(int OFFSET_X, int OFFSET_Y, int direction)
{
	this->OFFSET_X = OFFSET_X;
	this->OFFSET_Y = OFFSET_Y;
	this->direction = direction;
	shape[0] = "(___()'`;";
	shape[1] = "/,    /`";
	shape[2] = "\\\\\"--\\\\";
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < shape[i].size(); j++)
		{
			point temp(OFFSET_X + direction * j, OFFSET_Y + i, shape[i][j]);
			p.push_back(temp);
		}
	distance = 30;
}
Dog::Dog(const Dog& dog) {
	this->OFFSET_X = dog.OFFSET_X;
	this->OFFSET_Y = dog.OFFSET_Y;
	this->direction = dog.direction;
	this->distance = dog.distance;
	shape[0] = "(___()'`;";
	shape[1] = "/,    /`";
	shape[2] = "\\\\\"--\\\\";
	p.clear();
	p = dog.p;
}
Obstacle* Dog::clone() {
	return new Dog(*this);
}