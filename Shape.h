#pragma once
#include <string>
#include <vector>
#include <iostream>
using namespace std;
<<<<<<< HEAD
=======

>>>>>>> a7dc7579fe252822b262d27f2ae73f661b20a978
class Shape
{
	vector<string> str;
public:
	Shape();
	Shape(const Shape&);
	Shape(string[]);
	vector<string> getShape();
<<<<<<< HEAD
	Shape& operator=(const Shape&);
=======
>>>>>>> a7dc7579fe252822b262d27f2ae73f661b20a978
	void setShape(vector<string> temp);
	void changeToNormal();
	void changeToLose();
	void changeToWin1();
	void changeToWin2();
<<<<<<< HEAD
	void changeToSnowman();
=======
>>>>>>> a7dc7579fe252822b262d27f2ae73f661b20a978
};