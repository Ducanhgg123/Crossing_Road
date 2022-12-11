
#include "TrafficLight.h"
#include "Game.h"
TrafficLight::TrafficLight()
{
	p.setX(0);
	p.setY(0);
	p.setC(char(178));
	status = 1;
}

TrafficLight::TrafficLight(int x, int y)
{
	p.setX(x);
	p.setY(y);
	p.setC(char(178));
	status = 1;
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
	Game::m.lock();
	status = rand() % 300;
	Game::m.unlock();
	return status;
}

void TrafficLight::changeColor()
{
	int status = randomStatus();
	if (status == 0)
	{
		Game::m.lock();
		textColor(colorRed);
		draw();
		textColor(colorDefault);
		Game::m.unlock();
	}
	else
	{
		Game::m.lock();
		textColor(colorGreen);
		draw();
		textColor(colorDefault);
		Game::m.unlock();
	}
}

void TrafficLight::draw()
{
	goToXY(p.getX(), p.getY());
	cout << p.getC();
}