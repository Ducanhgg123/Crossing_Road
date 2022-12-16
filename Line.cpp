#include "Line.h"
#include "Game.h"
Line::Line()
{
	line = deque<Obstacle*>();
	trafficLight = TrafficLight();
}

Line::Line(const Line& temp)
{
	if (this == &temp)
		return;
	clear();
	for (int i = 0; i < temp.line.size(); i++)
	{
		line.push_back(temp.line[i]->clone());
	}
	trafficLight = temp.trafficLight;
}
Line::Line(int x, int y) {
	line = deque<Obstacle*>();
	trafficLight = TrafficLight(x, y);
}
Line::~Line() {
	clear();
}
deque<Obstacle*> Line::getLine()
{
	deque<Obstacle*> tmp;
	for (int i = 0; i < line.size(); i++)
	{
		tmp.push_back(line[i]->clone());
	}
	return tmp;
	/*return line;*/
}

Line& Line::operator=(const Line& temp)
{
	if (this == &temp)
		return *this;
	clear();
	for (int i = 0; i < temp.line.size(); i++)
	{
		line.push_back(temp.line[i]->clone());
	}
	this->trafficLight = temp.trafficLight;
	return *this;
}

void Line::setLine(deque<Obstacle*> tempLine)
{
	clear();
	for (int i = 0; i < tempLine.size(); i++)
	{
		line.push_back(tempLine[i]->clone());
	}
}

void Line::updateTrafficLight()
{
	trafficLight.changeColor();
}

bool Line::isRed()
{
	if (trafficLight.getStatus() == 0)
		return true;
	else
		return false;
}

void Line::clear()
{
	for (int i = 0; i < line.size(); i++)
	{
		delete line[i];
		line[i] = NULL;
	}
	line.clear();
}

void Line::setTrafficLight(TrafficLight tmp)
{
	trafficLight = tmp;
}

TrafficLight Line::getTrafficLight()
{
	return trafficLight;
}

void Line::move()
{
	for (int i = 0; i < line.size(); i++)
	{
		line[i]->undrawBack();
		line[i]->move();
		line[i]->draw();
	}
}
void Line::deleteReachEndPoint(int endPoint) {
	if (line[0]->reachEndPoint(endPoint)) {
		line[0]->undraw();
		delete line[0];
		line.pop_front();
	}
}
void Line::insertNewObstacle(Obstacle* temp)
{
	line.push_back(temp->clone());
}

int Line::getLineSize()
{
	return line.size();
}

Obstacle* Line::getObstacleAt(int index)
{
	return line[index]->clone();
}

void Line::draw()
{
	for (int i = 0; i < line.size(); i++)
	{
		line[i]->draw();
	}
}

void Line::undraw()
{
	for (int i = 0; i < line.size(); i++)
	{
		line[i]->undraw();
	}
}
void Line::makeSound() {
	if (line.size() > 0) {
		line[0]->makeSound();
	}
}
bool Line::canAddNewObstacle() {
	return (getLineSize()>0 && line[getLineSize()-1]->getDistanceFromStart()>line[0]->getDistance());
}