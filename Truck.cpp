#include "Truck.h"
Truck::Truck(int OFFSET_X, int OFFSET_Y, int direction)
{
	this->OFFSET_X = OFFSET_X;
	this->OFFSET_Y = OFFSET_Y;
	this->direction = direction;
	shape[0] = " _//]| |~~~~~~~~|";
	shape[1] = "|____|-|________|";
	shape[2] = "   O     O     O ";
	for (int i = 0; i < 3; i++) {
		string st = "";
		for (int j = 0; j < shape[i].size(); j++)
			st = shape[i][j] + st;
		shape[i] = st;
	}
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < shape[i].size(); j++)
		{
			point temp(OFFSET_X + direction * j, OFFSET_Y + i, shape[i][j]);
			p.push_back(temp);
		}
	distance = 30;
}
Truck::Truck(const Truck& truck) {
	this->OFFSET_X = truck.OFFSET_X;
	this->OFFSET_Y = truck.OFFSET_Y;
	this->direction = truck.direction;
	this->distance = truck.distance;
	shape[0] = " _//]| |~~~~~~~~|";
	shape[1] = "|____|-|________|";
	shape[2] = "   O     O     O ";
	for (int i = 0; i < 3; i++) {
		string st = "";
		for (int j = 0; j < shape[i].size(); j++)
			st = shape[i][j] + st;
		shape[i] = st;
	}
	p.clear();
	p = truck.p;
}
Obstacle* Truck::clone() {
	return new Truck(*this);
}