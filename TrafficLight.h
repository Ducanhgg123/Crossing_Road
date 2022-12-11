#pragma once
#include "point.h"

class TrafficLight
{
	point p;
	int status; //0 la red, >0 la green
public:
	TrafficLight();
	TrafficLight(const TrafficLight&);
	TrafficLight(int, int);
	point getPoint();
	void setPoint(int, int);
	int randomStatus();
	void changeColor();
	int getStatus();
	void draw();
};