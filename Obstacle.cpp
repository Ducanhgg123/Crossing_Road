#include "Obstacle.h"
#include "Game.h"
void Obstacle::move() {
	for (int i = 0; i < p.size(); i++) {
		p[i].setX(p[i].getX() + direction);
	}
}
bool Obstacle::reachEndPoint(int x) {
	int back[3];
	back[0] = 0;
	back[1] = 0 + shape[0].size();
	back[2] = back[1] + shape[1].size();
	for (int i = 0; i < 3; i++) {
		if (p[back[i]].getX() == x)
			return true;
	}
	return false;
}
void Obstacle::draw() {
	for (int i = 0; i < p.size(); i++) {
		Game::m.lock();
		goToXY(p[i].getX(), p[i].getY());
		cout << p[i].getC();
		Game::m.unlock();
	}
}
void Obstacle::undraw() {
	for (int i = 0; i < p.size(); i++) {
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
		Game::m.lock();
		goToXY(tmp.getX(), tmp.getY());
		cout << " ";
		Game::m.unlock();
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