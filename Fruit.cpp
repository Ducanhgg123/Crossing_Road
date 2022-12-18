#include "Fruit.h"
#include "Game.h"

Fruit::Fruit()
{
	vector<string> tempV;
	string tempStr = " $ ";
	tempStr[0] = char(201);
	tempStr[2] = char(187);
	tempV.push_back(tempStr);
	tempStr[0] = char(200);
	tempStr[2] = char(188);
	tempV.push_back(tempStr);
	shape.setShape(tempV);
	for (int i = 0; i < shape.getShape().size(); i++)
	{
		p.push_back(point(0, 0, 'X'));
	}
}

Fruit::Fruit(const Fruit& temp)
{
	for (int i = 0; i < temp.p.size(); i++)
	{
		p.push_back(temp.p[i]);
	}
	shape = temp.shape;
}

bool Fruit::initNewFruit()
{
	do
	{
		p.clear();
		/*vector<string> tempV;
		string tempStr = " $ ";
		tempStr[0] = char(201);
		tempStr[2] = char(187);
		tempV.push_back(tempStr);
		tempStr[0] = char(200);
		tempStr[2] = char(188);
		tempV.push_back(tempStr);
		shape.setShape(tempV);*/
<<<<<<< HEAD
		
		vector<string> listShape = shape.getShape();
		//rand()%(max - min +1)+min
		int tempX = rand() % ((Game::endLine + 1) - (Game::startLine - 1) + 1) + (Game::startLine + 1);
		int tempY = rand() % ((28-1) - (7+1) + 1) + ((7 + 1) + 1);
=======

		vector<string> listShape = shape.getShape();
		//rand()%(max - min +1)+min
		int tempX = rand() % ((Game::endLine + 1) - (Game::startLine - 1) + 1) + (Game::startLine + 1);
		int tempY = rand() % ((28 - 1) - (7 + 1) + 1) + ((7 + 1) + 1);
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
		for (int i = 0; i < listShape.size(); i++)
			for (int j = 0; j < listShape[i].size(); j++)
			{
				point tempP(tempX + j, tempY + i, listShape[i][j]);
				p.push_back(tempP);
			}
	} while (isCollide());
<<<<<<< HEAD
	
=======

>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
	return (!isCollide());
}

void Fruit::draw()
{
	for (int i = 0; i < p.size(); i++)
	{
		Game::m.lock();
		goToXY(p[i].getX(), p[i].getY());
		if (i == 0 || i == 2 || i == 3 || i == 5)
		{
			TextColor(colorRed);
			cout << p[i].getC();
			TextColor(colorDefault);
		}
		else
		{
			TextColor(colorGreen);
			cout << p[i].getC();
			TextColor(colorDefault);
		}
		Game::m.unlock();
	}
}

void Fruit::undraw()
{
	for (int i = 0; i < p.size(); i++)
<<<<<<< HEAD
		if (!(Game::isCollideWithPlayer(p[i], Game::player)) && !(Game::isCollideWithPlayer(p[i], Game::playerTwo)))
=======
		if (!(Game::isCollideWithPlayer(p[i])))
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
		{
			{
				Game::m.lock();
				goToXY(p[i].getX(), p[i].getY());
				cout << " ";
				Game::m.unlock();
			}
		}
}

void Fruit::generateNewFruit()
{
	undraw();
	if (initNewFruit())
	{
		undraw();
		draw();
	}
}

bool Fruit::isCollide()
{
	vector<point> ListCrossLine;
	for (int i = 0; i < Game::crossLine.size(); i++)
	{
		ListCrossLine = Game::crossLine[i].getListPoint();
		for (int j = 0; j < p.size(); j++)
		{
			for (int k = 0; k < ListCrossLine.size(); k++)
			{
				if (p[j].getX() == ListCrossLine[k].getX() && p[j].getY() == ListCrossLine[k].getY())
					return true;
			}
		}
	}

	vector<point> ListPlayer = Game::player.getListPoint();
	for (int j = 0; j < p.size(); j++)
	{
		for (int k = 0; k < ListPlayer.size(); k++)
		{
			if (p[j].getX() == ListPlayer[k].getX() && p[j].getY() == ListPlayer[k].getY())
				return true;
		}
	}
	vector<point> ListPlayerTwo = Game::playerTwo.getListPoint();
	for (int j = 0; j < p.size(); j++)
	{
		for (int k = 0; k < ListPlayerTwo.size(); k++)
		{
			if (p[j].getX() == ListPlayerTwo[k].getX() && p[j].getY() == ListPlayerTwo[k].getY())
				return true;
		}
	}

	return false;
}

void Fruit::collisionHandle()
{
	undraw();
<<<<<<< HEAD
	if (Game::fruitRequired>0)
=======
	if (Game::fruitRequired > 0)
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
		generateNewFruit();
}

deque<point> Fruit::getListPoint()
{
	return p;
}