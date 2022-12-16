#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;

class Shape
{
	vector<string> str;
public:
	Shape();
	Shape(const Shape&);
	Shape(string[]);
	vector<string> getShape();
	void setShape(vector<string> temp);
	void changeToNormal();
	void changeToLose();
	void changeToWin1();
	void changeToWin2();
};