#include <iostream>
#include <Windows.h>
#include <deque>
using namespace std;

int OFFSET_X = 10, OFFSET_Y = 10;

void showConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
}
void fixConsoleWindow()
{
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);

	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);

	showConsoleCursor(false);
}
void TextColor(int color)
{
	HANDLE mau;
	mau = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(mau, color);
}
void goToXY(int x, int y)
{
	COORD coord;

	coord.X = x;
	coord.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}


class Wall
{

};

class point
{
	COORD c;
	char ch;
public:
	point()
	{
		c.X = 0;
		c.Y = 0;
		ch = 0;
	};
	point(COORD c, char ch)
	{
		this->c = c;
		this->ch = ch;
	};
	void increaseX()
	{
		this->c.X++;
	}
	void increaseY()
	{
		this->c.Y++;
	}
	COORD getCoord()
	{
		return this->c;
	}
	//getter
	int cX()
	{
		return this->c.X;
	}
	int cY()
	{
		return this->c.Y;
	}
	char getChar()
	{
		return this->ch;
	}
};


class Car
{
	deque<point> p;
	string a = " _.-.___\\__";
	string b = "|  _      _`-.";
	string c = "'-(_)----(_)--`";
	int size;
public:
	Car()
	{
		for (int i = 0; i < 3; i++)
		{
			COORD temp;
			temp.Y = OFFSET_Y + i;
			if (i == 0)
			{
				for (int j = 0; j < 11; j++)
				{
					temp.X = OFFSET_X + j;
					point tempP(temp, a[j]);
					p.push_back(tempP);
				}
			}
			else if (i == 1)
			{
				for (int j = 0; j < 15; j++)
				{
					temp.X = OFFSET_X + j;
					point tempP(temp, b[j]);
					p.push_back(tempP);
				}
			}
			else if (i == 2)
			{
				for (int j = 0; j < 16; j++)
				{
					temp.X = OFFSET_X + j;
					point tempP(temp, c[j]);
					p.push_back(tempP);
				}
			}
		}
		size = p.size();
	}
	Car(const Car& temp)
	{
		*this = temp;
	}
	int getSize()
	{
		return this->size;
	}
	Car& operator++()
	{
		for (int i = 0; i < p.size(); i++)
		{
			p[i].increaseX();
		}
		return *this;
	}
	Car operator++(int x)
	{
		Car temp(*this);
		++(*this);
		return temp;
	}
	bool isColide(const COORD& coord)
	{
		for (int i = 0; i < p.size(); i++)
		{
			if (p[i].cX() == coord.X && p[i].cY() == coord.Y)
			{
				return true;
			}
		}
		return false;
	}
	friend ostream& operator<<(ostream& out, Car& car)
	{
		for (int i = 0; i < car.p.size(); i++)
		{
			goToXY(car.p[i].cX(), car.p[i].cY());
			cout << car.p[i].getChar();
		}
		return out;
	}
	void undrawCar1()
	{
		goToXY(p[0].cX(), p[0].cY());
		cout << " ";
		goToXY(p[11].cX(), p[11].cY());
		cout << " ";
		goToXY(p[26].cX(), p[26].cY());
		cout << " ";
	}
	void undrawCar2()
	{
		for (int i = 0; i < p.size(); i++)
		{
			goToXY(p[i].cX(), p[i].cY());
			cout <<" ";
		}
	}
	COORD getCoord()
	{
		return p[0].getCoord();
	}
};



int main()
{
	fixConsoleWindow();
	
	COORD wall;
	wall.X = OFFSET_X + 90;
	wall.Y = OFFSET_Y;
	goToXY(OFFSET_X - 1, OFFSET_Y);
	cout << "|";
	goToXY(100+1, OFFSET_Y);
	cout << "|";
	deque <Car> d;
	while (1)
	{
		//Sleep(50/5 + 20); 
		Car car;
		if (d.size() == 0)
		{
			d.push_back(car);
		}
		if (d.size() < 4 && (d[d.size() - 1].getCoord().X >= OFFSET_X + 20))
		{
			d.push_back(car);
		}
		for (int i = 0; i < d.size(); i++)
		{
			d[i].undrawCar1();
			d[i]++;
			
		}
		for (int i = 0; i < d.size(); i++)
		{
			
			cout << d[i];
		}
		if (d[0].isColide(wall))
		{
			d[0].undrawCar2();
			d.pop_front();
		}
		//while (1) {
		//	/*COORD c;
		//	c.X = OFFSET_X;
		//	c.Y = OFFSET_Y;
		//	if (d.size() == 0)
		//	{
		//		d.push_back(c);
		//	}
		//	if (d.size() < 5 && d[d.size()-1].X >= OFFSET_X + 20)
		//		d.push_back(c);
		//	for (int i = 0; i < d.size(); i++)
		//	{
		//		goToXY(d[i].X, d[i].Y);
		//		cout << " ";
		//		d[i].X++;
		//	}
		//	for (int i = 0; i < d.size(); i++)
		//	{
		//		goToXY(d[i].X, d[i].Y);
		//		cout << "A";
		//	}
		//	if (d[0].X == 100)
		//	{
		//		goToXY(d[0].X, d[0].Y);
		//		cout << " ";
		//		d.pop_front();
		//	}*/
		//}
	}
	return 0;
}