#pragma once
#include "lib.h"
using namespace std;
class point {
private:
	int x;
	int y;
	char c;
public:
	point();
	point(int, int, char);
	void setX(int);
	void setY(int);
	void setC(char);
	int getX();
	int getY();
	char getC();
};
void goToXY(int x, int y);
void textColor(int x);