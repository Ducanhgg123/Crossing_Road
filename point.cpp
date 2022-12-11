#include "point.h"
void goToXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
point::point() {
	x = 0;
	y = 0;
	c = ' ';
}
point::point(int x, int y, char c) {
	setX(x);
	setY(y);
	setC(c);
}
void point::setX(int x) {
	this->x = max(0, x);
}
void point::setY(int y) {
	this->y = max(0, y);
}
void point::setC(char c) {
	this->c = c;
}
int point::getX() {
	return x;
}
int point::getY() {
	return y;
}
char point::getC() {
	return c;
}

void TextColor(int x)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, x);
}