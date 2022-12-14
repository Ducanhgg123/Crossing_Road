#include "Obstacle.h"
#include "Game.h"
void Obstacle::move() {
	for (int i = 0; i < p.size(); i++) {
		p[i].setX(p[i].getX() + direction);
	}
}
bool Obstacle::reachEndPoint(int x) {
	for (int i = 0; i < p.size(); i++) {
		point tmp = p[i];
		if (p[i].getX() == x)
			return true;
	}
	return false;
}
void Obstacle::draw() {
	for (int i = 0; i < p.size(); i++) {
		Game::m.lock();
		if (!(Game::isCollideWithFruit(p[i])))
		{
			goToXY(p[i].getX(), p[i].getY());
			cout << p[i].getC();
		}
		Game::m.unlock();
	}
}
void Obstacle::undraw() {
	for (int i = 0; i < p.size(); i++)
		if (!Game::isCollideWithFruit(p[i]))
		{
			Game::m.lock();
			goToXY(p[i].getX(), p[i].getY());
			cout << " ";
			Game::m.unlock();
		}
}
void Obstacle::undrawBack() {
	int back[3];
	back[0] = 0;
	back[1] = 0 + shape[0].size();
	back[2] = back[1] + shape[1].size();
	for (int i = 0; i < 3; i++) {
		point tmp = p[back[i]];
		if (!Game::isCollideWithFruit(tmp)) {
			Game::m.lock();
			goToXY(tmp.getX(), tmp.getY());
			cout << " ";
			Game::m.unlock();
		}
	}
}
int Obstacle::getDistanceFromStart() {
	point tmp = p[0];
	return direction * (p[0].getX() - OFFSET_X);
}
int Obstacle::getDistance() {
	return distance;
}
vector<point> Obstacle::getListPoint() {
	return p;
}
Obstacle* Obstacle::clone() {
	return new Obstacle(*this);
}
void Obstacle::makeSound(){}
ostream& operator<<(ostream& out, Obstacle* ob) {
	out << ob->p.size() << endl;
	out << ob->OFFSET_X << " " << ob->OFFSET_Y << endl;
	vector<point> listPoint = ob->p;
	for (int i = 0; i < listPoint.size(); i++) {
		out << listPoint[i].getX() << " " << listPoint[i].getY() << '\n';
	}
	out << ob->direction << " " << ob->distance << '\n';
	return out;
}