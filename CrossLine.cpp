#include "CrossLine.h"
#include "Game.h"
CrossLine::CrossLine()
{
	
}

CrossLine::CrossLine(int x, int y,int length)
{
	for (int i = 0; i < length; i++)
	{
		p.push_back(point(x+i, y, '-'));
	}
}

void CrossLine::draw()
{
	for (int i = 0; i < p.size();i++)
		if (!isCollideWithPlayer(p[i]))
	{
		Game::m.lock();
		goToXY(p[i].getX(), p[i].getY());
		cout << p[i].getC();
		Game::m.unlock();
	}
}
int CrossLine::getLength()
{
	return length;
}
bool CrossLine::isCollideWithPlayer(point p) {
	vector<point>listPoint = Game::player.getListPoint();
	for (int i = 0; i < listPoint.size(); i++) {
		if (p.getX() == listPoint[i].getX() && p.getY() == listPoint[i].getY())
			return true;
	}
	return false;
}

vector<point> CrossLine::getListPoint()
{
	vector<point> temp;
	for (int i = 0; i < p.size(); i++)
	{
		temp.push_back(p[i]);
	}
	return temp;
}