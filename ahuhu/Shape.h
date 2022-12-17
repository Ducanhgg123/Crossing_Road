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
	Shape& operator=(const Shape&);
	vector<string> getShape();
	void setShape(vector<string> temp);
	void changeToNormal(int);
	void changeToLose(int);
	void changeToWin1(int);
	void changeToWin2(int);
	void changeToSnowman();
};