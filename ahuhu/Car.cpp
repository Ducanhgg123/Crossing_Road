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