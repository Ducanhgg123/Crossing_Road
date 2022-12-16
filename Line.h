#pragma once
#include "TrafficLight.h"
#include "Obstacle.h"
class Line
{
	deque <Obstacle*> line;
	TrafficLight trafficLight;
public:
	Line();
	Line(const Line&);
	Line(int, int);
	~Line();
	deque<Obstacle*> getLine();
	Line& operator=(const Line&);
	void setLine(deque<Obstacle*>);
	void updateTrafficLight();
	bool isRed();
	void clear();
	void setTrafficLight(TrafficLight);
	TrafficLight getTrafficLight();
	void move();
	void insertNewObstacle(Obstacle*);
	int getLineSize();
	Obstacle* getObstacleAt(int);
	void draw();
	void undraw();
	void deleteReachEndPoint(int);
	void makeSound();
	bool canAddNewObstacle();
};