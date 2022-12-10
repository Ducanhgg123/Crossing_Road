
#include "TrafficLight.h"
#include "Game.h"
TrafficLight::TrafficLight()
{
	p.setX(0);
	p.setX(0);
	p.setC('X');
}

TrafficLight::TrafficLight(int x, int y)
{
	p.setX(x);
	p.setX(y);
	p.setC('X');
}

TrafficLight::TrafficLight(const TrafficLight& temp)
{
	p = temp.p;
	status = temp.status;
}

point TrafficLight::getPoint() //get coord
{
	return p;
}

void TrafficLight::setPoint(int x, int y) //set coord
{
	p.setX(x);
	p.setY(y);
}
int TrafficLight::getStatus() {
	return status;
}
int TrafficLight::randomStatus()
{
	status = rand() % 10;
	return status;
}

void TrafficLight::changeColor()
{
	int status = randomStatus();
	if (status == 0)
	{
		textColor(colorRed);
		draw();
		textColor(colorDefault);
	}
	else
	{
		textColor(colorGreen);
		draw();
		textColor(colorDefault);
	}
}

void TrafficLight::draw()
{
	Game::m.lock();
	goToXY(p.getX(), p.getY());
	cout << p.getC();
	Game::m.unlock();
}