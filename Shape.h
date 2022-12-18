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
	Shape& operator=(const Shape&);
	vector<string> getShape();
<<<<<<< HEAD
	Shape& operator=(const Shape&);
=======
>>>>>>> a7dc7579fe252822b262d27f2ae73f661b20a978
	void setShape(vector<string> temp);
<<<<<<< HEAD
	void changeToNormal(int);
	void changeToLose(int);
	void changeToWin1(int);
	void changeToWin2(int);
=======
	void changeToNormal();
	void changeToLose();
	void changeToWin1();
	void changeToWin2();
<<<<<<< HEAD
>>>>>>> fdb4b171e8ae21e71034e42e9187fdc21519fe2f
	void changeToSnowman();
=======
<<<<<<< HEAD
	void changeToSnowman();
=======
>>>>>>> a7dc7579fe252822b262d27f2ae73f661b20a978
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
};