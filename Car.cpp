#include "Car.h"
#include "Game.h"
Car::Car(int OFFSET_X, int OFFSET_Y, int direction)
{
	this->OFFSET_X = OFFSET_X;
	this->OFFSET_Y = OFFSET_Y;
	this->direction = direction;
	shape[0] = " _.-.___\\_";
	shape[1] = "|  _      _`-.";
	shape[2] = "'-(_)----(_)--`";
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < shape[i].size(); j++)
		{
			point temp(OFFSET_X + direction * j, OFFSET_Y + i, shape[i][j]);
			p.push_back(temp);
		}
	distance = 40;
}
Car::Car(const Car& car) {
	this->OFFSET_X = car.OFFSET_X;
	this->OFFSET_Y = car.OFFSET_Y;
	this->direction = car.direction;
	shape[0] = " _.-.___\\_";
	shape[1] = "|  _      _`-.";
	shape[2] = "'-(_)----(_)--`";
	p.clear();
	p = car.p;
	this->distance = car.distance;
}
Car::Car(int OFFSET_X,int OFFSET_Y,vector<point> listPoint, int direction, int distance) {
	p.clear();
	this->OFFSET_X = OFFSET_X;
	this->OFFSET_Y = OFFSET_Y;
	shape[0] = " _.-.___\\_";
	shape[1] = "|  _      _`-.";
	shape[2] = "'-(_)----(_)--`";
	int k = 0;
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < shape[i].size(); j++)
		{
			p.push_back(point(listPoint[k]));
			p[k].setC(shape[i][j]);
			k++;
		}
		
	this->direction = direction;
	this->distance = distance;
}
Obstacle* Car::clone() {
	return new Car(*this);
}
void ThreadCarSound() {
	while (Game::isRunning) {
		PlaySound(TEXT("mixkit-car-horn-718.wav"), NULL, SND_ASYNC);
		Sleep(2000);
	}
}
void Car::makeSound() {
	thread sound(ThreadCarSound);
	sound.detach();
}
ostream& operator<<(ostream& out, const Car& car) {
	out << car.p.size() << endl;
	vector<point> listPoint = car.p;
	for (int i = 0; i < listPoint.size(); i++) {
		out << listPoint[i].getX()<<" "<<listPoint[i].getY()<<'\n';
	}
	out << car.direction << " " << car.distance << '\n';
	return out;
}