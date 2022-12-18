#include "Dog.h"
#include "Game.h"
Dog::Dog(int OFFSET_X, int OFFSET_Y, int direction)
{
	this->OFFSET_X = OFFSET_X;
	this->OFFSET_Y = OFFSET_Y;
	this->direction = direction;
	shape[0] = "(___()'`;";
	shape[1] = "/,    /`";
	shape[2] = "\\\\\"--\\\\";
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < shape[i].size(); j++)
		{
			point temp(OFFSET_X + direction * j, OFFSET_Y + i, shape[i][j]);
			p.push_back(temp);
		}
	distance = 30;
}
Dog::Dog(const Dog& dog) {
	this->OFFSET_X = dog.OFFSET_X;
	this->OFFSET_Y = dog.OFFSET_Y;
	this->direction = dog.direction;
	this->distance = dog.distance;
	shape[0] = "(___()'`;";
	shape[1] = "/,    /`";
	shape[2] = "\\\\\"--\\\\";
	p.clear();
	p = dog.p;
}
Dog::Dog(int OFFSET_X,int OFFSET_Y,vector<point> listPoint, int direction, int distance) {
	p.clear();
	this->OFFSET_X = OFFSET_X;
	this->OFFSET_Y = OFFSET_Y;
	shape[0] = "(___()'`;";
	shape[1] = "/,    /`";
	shape[2] = "\\\\\"--\\\\";
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
Obstacle* Dog::clone() {
	return new Dog(*this);
}
void ThreadDogSound() {
	while (Game::isRunning) {
		PlaySound(TEXT("mixkit-dog-barking-twice-1.wav"), NULL, SND_ASYNC);
		Sleep(2000);
	}
}
void Dog::makeSound() {
	thread sound(ThreadDogSound);
	sound.detach();
}
ostream& operator<<(ostream& out, const Dog& dog) {
	out << dog.p.size() << endl;
	vector<point> listPoint = dog.p;
	for (int i = 0; i < listPoint.size(); i++) {
		out << listPoint[i].getX() << " " << listPoint[i].getY() << '\n';
	}
	out << dog.direction << " " << dog.distance << '\n';
	return out;
}