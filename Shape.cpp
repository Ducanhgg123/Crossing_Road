#include "Shape.h"

Shape::Shape()
{
	string tmpStr[3];
<<<<<<< HEAD
	tmpStr[0] = " ('') ";
	tmpStr[1] = "//[]\\\\";
	tmpStr[2] = "_/  \\_";
=======
<<<<<<< HEAD
	tmpStr[0] = "  ('')  ";
	tmpStr[1] = " //[]\\\\ ";
	tmpStr[2] = " _/  \\_ ";
=======
	tmpStr[0] = "   (\") ";
	tmpStr[1] = "  \\/0\\G ";
	tmpStr[2] = "  _/ \\_ ";
>>>>>>> a7dc7579fe252822b262d27f2ae73f661b20a978
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
	for (int i = 0; i < 3; i++)
	{
		this->str.push_back(tmpStr[i]);
	}
}

Shape::Shape(const Shape& temp)
{
<<<<<<< HEAD
=======
<<<<<<< HEAD
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
	str.clear();
	for (int i = 0; i < temp.str.size(); i++)
	{
		str.push_back(temp.str[i]);
	}
}
<<<<<<< HEAD

=======
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
Shape& Shape::operator=(const Shape& temp)
{
	str.clear();
	str = temp.str;
	return *this;
<<<<<<< HEAD
=======
}
=======
	str[0] = temp.str[0];
	str[1] = temp.str[1];
	str[2] = temp.str[2];
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
}

>>>>>>> a7dc7579fe252822b262d27f2ae73f661b20a978
vector<string> Shape::getShape()
{
	return str;
}

void Shape::setShape(vector<string> temp)
{
	str.clear();
	str = temp;
}

void Shape::changeToNormal(int playerIndex)
{
<<<<<<< HEAD
	if (playerIndex == 1)
=======
	str.clear();
	string tmpStr[3];
<<<<<<< HEAD
	tmpStr[0] = " ('') ";
	tmpStr[1] = "//[]\\\\";
	tmpStr[2] = "_/  \\_";
=======
<<<<<<< HEAD
	tmpStr[0] = "  ('')  ";
	tmpStr[1] = " //[]\\\\ ";
	tmpStr[2] = " _/  \\_ ";
=======
	tmpStr[0] = "   (\") ";
	tmpStr[1] = "  \\/0\\G ";
	tmpStr[2] = "  _/ \\_ ";
>>>>>>> a7dc7579fe252822b262d27f2ae73f661b20a978
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
	for (int i = 0; i < 3; i++)
>>>>>>> fdb4b171e8ae21e71034e42e9187fdc21519fe2f
	{
		str.clear();
		string tmpStr[3];
		tmpStr[0] = " ('') ";
		tmpStr[1] = "//[]\\\\";
		tmpStr[2] = "_/  \\_";
		for (int i = 0; i < 3; i++)
		{
			str.push_back(tmpStr[i]);
		}
	}
	else
	{
		changeToSnowman();
	}
}

void Shape::changeToWin1(int playerIndex)
{
<<<<<<< HEAD
	if (playerIndex == 1)
=======
	str.clear();
	string tmpStr[3];
<<<<<<< HEAD
	tmpStr[0] = "\\(^^)/";
	tmpStr[1] = "/ [] \\";
	tmpStr[2] = " /  \\ ";
=======
<<<<<<< HEAD
	tmpStr[0] = " \\(^^)/ ";
	tmpStr[1] = " / [] \\ ";
	tmpStr[2] = "  /  \\  ";
=======
	tmpStr[0] = "  \\(\")/";
	tmpStr[1] = "  /(0)\\ ";
	tmpStr[2] = "   / \\  ";
>>>>>>> a7dc7579fe252822b262d27f2ae73f661b20a978
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
	for (int i = 0; i < 3; i++)
>>>>>>> fdb4b171e8ae21e71034e42e9187fdc21519fe2f
	{
		str.clear();
		string tmpStr[3];
		tmpStr[0] = "*(^^)*";
		tmpStr[1] = " <[]> ";
		tmpStr[2] = " /  \\ ";
		for (int i = 0; i < 3; i++)
		{
			str.push_back(tmpStr[i]);
		}
	}
	else
	{
		str.clear();
		string tmpStr[3];
		tmpStr[0] = " (^^) ";
		tmpStr[1] = "</..\\>";
		tmpStr[2] = "( :: )";
		for (int i = 0; i < 3; i++)
		{
			str.push_back(tmpStr[i]);
		}
	}
}

void Shape::changeToWin2(int playerIndex)
{
<<<<<<< HEAD
	if (playerIndex == 1)
=======
	str.clear();
	string tmpStr[3];
<<<<<<< HEAD
	tmpStr[0] = " (^^) ";
	tmpStr[1] = "/<[]>\\";
	tmpStr[2] = "_/  \\_";
=======
<<<<<<< HEAD
	tmpStr[0] = "  (^^)  ";
	tmpStr[1] = " /<[]>\\ ";
	tmpStr[2] = " _/  \\_ ";
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
	for (int i = 0; i < 3; i++)
>>>>>>> fdb4b171e8ae21e71034e42e9187fdc21519fe2f
	{
		str.clear();
		string tmpStr[3];
		tmpStr[0] = " (^^) ";
		tmpStr[1] = " /[]\\ ";
		tmpStr[2] = "_/  \\_";
		for (int i = 0; i < 3; i++)
		{
			str.push_back(tmpStr[i]);
		}
	}
	else
	{
		str.clear();
		string tmpStr[3];
		tmpStr[0] = "*(^^)*";
		tmpStr[1] = "Y/..\\Y";
		tmpStr[2] = "( :: )";
		for (int i = 0; i < 3; i++)
		{
			str.push_back(tmpStr[i]);
		}
	}
}

void Shape::changeToLose(int playerIndex)
{
<<<<<<< HEAD
	if (playerIndex == 1)
=======
	str.clear();
	string tmpStr[3];
<<<<<<< HEAD
	tmpStr[0] = " (TT) ";
	tmpStr[1] = "\\/[]\\G";
	tmpStr[2] = "_/  \\_";
=======
	tmpStr[0] = "  (TT)  ";
	tmpStr[1] = " \\/[]\\G ";
	tmpStr[2] = " _/  \\_ ";
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
	for (int i = 0; i < 3; i++)
>>>>>>> fdb4b171e8ae21e71034e42e9187fdc21519fe2f
	{
		str.clear();
		string tmpStr[3];
		tmpStr[0] = " (TT) ";
		tmpStr[1] = "//[]\\\\";
		tmpStr[2] = "_/  \\_";
		for (int i = 0; i < 3; i++)
		{
			str.push_back(tmpStr[i]);
		}
	}
	else
	{
		str.clear();
		string tmpStr[3];
		tmpStr[0] = "~(TT)~";
		tmpStr[1] = "Y/..\\Y";
		tmpStr[2] = "( :: )";
		for (int i = 0; i < 3; i++)
		{
			str.push_back(tmpStr[i]);
		}
	}
}

void Shape::changeToSnowman()
{
	str.clear();
	string tmpStr[3];
<<<<<<< HEAD
	tmpStr[0] = " ('') ";
=======
<<<<<<< HEAD
	tmpStr[0] = " (**) ";
>>>>>>> fdb4b171e8ae21e71034e42e9187fdc21519fe2f
	tmpStr[1] = "Y/..\\Y";
	tmpStr[2] = "( :: )";
=======
	tmpStr[0] = "  (**)  ";
	tmpStr[1] = " Y/..\\Y ";
	tmpStr[2] = " ( :: ) ";
=======
	tmpStr[0] = "   (\") ";
	tmpStr[1] = "  /<0>\\ ";
	tmpStr[2] = "  _/ \\_ ";
>>>>>>> a7dc7579fe252822b262d27f2ae73f661b20a978
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
	for (int i = 0; i < 3; i++)
	{
		str.push_back(tmpStr[i]);
	}
}