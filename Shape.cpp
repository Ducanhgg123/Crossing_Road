#include "Shape.h"


Shape::Shape()
{
	string tmpStr[3];
	tmpStr[0] = "  ('')  ";
	tmpStr[1] = " //[]\\\\ ";
	tmpStr[2] = " _/  \\_ ";
	for (int i = 0; i < 3; i++)
	{
		this->str.push_back(tmpStr[i]);
	}
}

Shape::Shape(const Shape& temp)
{
	str.clear();
	for (int i = 0; i < temp.str.size(); i++)
	{
		str.push_back(temp.str[i]);
	}
}

Shape& Shape::operator=(const Shape& temp)
{
	str.clear();
	str = temp.str;
	return *this;
}

vector<string> Shape::getShape()
{
	return str;
}

void Shape::setShape(vector<string> temp)
{
	str.clear();
	str = temp;
}

void Shape::changeToNormal()
{
	str.clear();
	string tmpStr[3];
	tmpStr[0] = "  ('')  ";
	tmpStr[1] = " //[]\\\\ ";
	tmpStr[2] = " _/  \\_ ";
	for (int i = 0; i < 3; i++)
	{
		str.push_back(tmpStr[i]);
	}
}

void Shape::changeToWin1()
{
	str.clear();
	string tmpStr[3];
	tmpStr[0] = " \\(^^)/ ";
	tmpStr[1] = " / [] \\ ";
	tmpStr[2] = "  /  \\  ";
	for (int i = 0; i < 3; i++)
	{
		str.push_back(tmpStr[i]);
	}
}

void Shape::changeToWin2()
{
	str.clear();
	string tmpStr[3];
	tmpStr[0] = "  (^^)  ";
	tmpStr[1] = " /<[]>\\ ";
	tmpStr[2] = " _/  \\_ ";
	for (int i = 0; i < 3; i++)
	{
		str.push_back(tmpStr[i]);
	}
}

void Shape::changeToLose()
{
	str.clear();
	string tmpStr[3];
	tmpStr[0] = "  (TT)  ";
	tmpStr[1] = " \\/[]\\G ";
	tmpStr[2] = " _/  \\_ ";
	for (int i = 0; i < 3; i++)
	{
		str.push_back(tmpStr[i]);
	}
}

void Shape::changeToSnowman()
{
	str.clear();
	string tmpStr[3];
	tmpStr[0] = "  (**)  ";
	tmpStr[1] = " Y/..\\Y ";
	tmpStr[2] = " ( :: ) ";
	for (int i = 0; i < 3; i++)
	{
		str.push_back(tmpStr[i]);
	}
}