#include "Game.h"
int Game::level = 1;
int Game::score = 0;
int Game::fruitRequired = 3;
int Game::fruitForThisLevel = 3;
int Game::startLine = 6;
int Game::endLine = 95;
Line Game::carLine = Line(104, distanceBetweenLine+2);
Line Game::truckLine = Line(1, 2*distanceBetweenLine+2);
Line Game::dogLine = Line(104, 3*distanceBetweenLine+2);
vector<CrossLine> Game::crossLine = vector<CrossLine>();
vector<point> Game::gate = vector<point>();
Player Game::player = Player(65, 30);
Player Game::playerTwo = Player(81, 30);
Fruit Game::fruit = Fruit();
bool Game::isRunning = 1;
bool Game::waiting = 0;
bool Game::isInTwoPlayerMode = false;
mutex Game::m;
GameControl Game::gameControl = GameControl();
Game::Game() {
	level = 1;
	score = 0;
	fruitRequired = 3;
	fruitForThisLevel = 3;
	startLine = 10;
	endLine = 95;
	carLine = Line();
	truckLine = Line();
	dogLine = Line();
	player = Player(65, 5 * distanceBetweenLine);
	playerTwo = Player(81, 5 * distanceBetweenLine);
	isRunning = 1;
}
void Game::restartGame() {
	level = 1;
	score = 0;
	fruitRequired = 3;
	startLine = 10;
	endLine = 95;
	carLine = Line();
	truckLine = Line();
	dogLine = Line();
	player = Player(65, 5 * distanceBetweenLine);
	playerTwo = Player(81, 5 * distanceBetweenLine);
	isRunning = 1;
}
bool Game::isColide(Player& player, Obstacle*& obstacle) {
	vector<point> listPointPlayer = player.getListPoint();
	vector<point> listPointObstacle = obstacle->getListPoint();
	for (int i=0;i<listPointPlayer.size();i++)
		for (int j = 0; j < listPointObstacle.size(); j++) {
			if (listPointPlayer[i].getX() == listPointObstacle[j].getX() && listPointPlayer[i].getY() == listPointObstacle[j].getY())
				return true;
		}
	return false;
}

bool Game::isCollideWithFruit(point& temp)
{
	if (temp.getX() <= 0)
		return false;
	deque<point> listFruit = Game::fruit.getListPoint();
	for (int i = 0; i < listFruit.size(); i++)
	{
		if (temp.getX() == listFruit[i].getX() && temp.getY() == listFruit[i].getY())
			return true;
	}
	return false;
}

bool Game::isCollideWithPlayer(point& temp, Player& player)
{
	vector<point> listPlayer = player.getListPoint();
	for (int i = 0; i < listPlayer.size(); i++)
	{
		if (temp.getX() == listPlayer[i].getX() && temp.getY() == listPlayer[i].getY())
			return true;
	}
	return false;
}

bool Game::isColidePlayerWithFruit(Player& player, Fruit& fruit)
{
	vector<point> listPlayer = player.getListPoint();
	deque<point> listFruit = fruit.getListPoint();
	for (int i = 0; i < listPlayer.size(); i++)
	{
		for (int j = 0; j < listFruit.size(); j++)
		{
			if (listPlayer[i].getX() == listFruit[j].getX() && listPlayer[i].getY() == listFruit[j].getY())
				return true;
		}
	}
	return false;
}

bool Game::checkHit(Player& player) {
	deque<Obstacle*> listCar = carLine.getLine();
	deque<Obstacle*> listTruck = truckLine.getLine();
	deque<Obstacle*> listDog = dogLine.getLine();
	bool ok = false;
	for (int i = 0; i < listCar.size() && ok==false; i++) {
		if (isColide(player, listCar[i])) {
			ok=true;
			break;
		}
	}
	for (int i = 0; i < listTruck.size() && ok == false; i++) {
		if (isColide(player, listTruck[i])) {
			ok = true;
			break;
		}
	}
	for (int i = 0; i < listDog.size() && ok==false; i++) {
		if (isColide(player, listDog[i])) {
			ok = true;
			break;
		}
	}
	for (int i = 0; i < listCar.size(); i++)
		delete listCar[i];
	for (int i = 0; i < listTruck.size(); i++)
		delete listTruck[i];
	for (int i = 0; i < listDog.size(); i++)
		delete listDog[i];
	return ok;
}
void Game::isHit(Player& player) {
	if (checkHit(player)) 
	{
		exitGame();
	}
}
void Game::exitGame() 
{
	isRunning = false;
}
void Game::drawRectangle(int offset_X, int offset_Y, int width, int height,int color)
{
	// Delete everything in the table
	for (int i = offset_X; i < offset_X + width; i++)
		for (int j = offset_Y; j < offset_Y + height; j++) {
			Game::m.lock();
			goToXY(i, j);
			cout << " ";
			Game::m.unlock();
		}
			
	// Draw left
	for (int i = offset_Y; i < offset_Y + height; i++) {
		Game::m.lock();
		TextColor(color);
		goToXY(offset_X, i);
		cout << char(219);
		TextColor(colorDefault);
		Game::m.unlock();
	}
	// Draw lower
	for (int i = offset_X; i < offset_X + width; i++) {
		Game::m.lock();
		TextColor(color);
		goToXY(i, offset_Y+height-1);
		cout << char(219);
		TextColor(colorDefault);
		Game::m.unlock();
	}
	// Draw right
	for (int i = offset_Y + height - 1; i >= offset_Y; i--) {
		Game::m.lock();
		TextColor(color);
		goToXY(offset_X+width,i);
		cout << char(219);
		TextColor(colorDefault);
		Game::m.unlock();
	}
	// Draw upper
	for (int i = offset_X + width - 1; i >= offset_X; i--) {
		Game::m.lock();
		TextColor(color);
		goToXY(i, offset_Y);
		cout << char(219);
		TextColor(colorDefault);
		Game::m.unlock();
	}
}
void ThreadCar()
{
	if (Game::carLine.getLineSize() == 0)
		Game::carLine.insertNewObstacle(new Car(Game::startLine - 15, distanceBetweenLine + 1, 1));
	Game::carLine.makeSound();
	while (Game::isRunning)
	{
		Sleep(100);
		Game::carLine.updateTrafficLight();
		if (Game::carLine.isRed())
			Sleep(1000);
		if (Game::carLine.getLineSize() == 0)
			Game::carLine.insertNewObstacle(new Car(Game::startLine - 15, distanceBetweenLine + 1, 1));
		else if (Game::carLine.getLineSize() < 1 && Game::carLine.canAddNewObstacle())
			Game::carLine.insertNewObstacle(new Car(Game::startLine - 15, distanceBetweenLine + 1, 1));
		Game::carLine.move();
		Game::carLine.deleteReachEndPoint(Game::endLine);
		Game::isHit(Game::player);
		Game::isHit(Game::playerTwo);
	}
}

void ThreadTruck()
{
	if (Game::truckLine.getLineSize() == 0)
		Game::truckLine.insertNewObstacle(new Truck(Game::endLine + 17, 2 * distanceBetweenLine + 1, -1));
	Game::truckLine.makeSound();
	while (Game::isRunning)
	{
		Sleep(100);
		Game::truckLine.updateTrafficLight();
		if (Game::truckLine.isRed())
			Sleep(1000);
		if (Game::truckLine.getLineSize() == 0)
			Game::truckLine.insertNewObstacle(new Truck(Game::endLine + 17, 2 * distanceBetweenLine + 1, -1));
		else if (Game::truckLine.getLineSize() < 1 && Game::truckLine.canAddNewObstacle())
			Game::truckLine.insertNewObstacle(new Truck(Game::endLine + 17, 2 * distanceBetweenLine + 1, -1));
		Game::truckLine.move();
		Game::truckLine.deleteReachEndPoint(Game::startLine);
		Game::isHit(Game::player);
		Game::isHit(Game::playerTwo);
	}
}
void ThreadDog()
{
	if (Game::dogLine.getLineSize() == 0)
		Game::dogLine.insertNewObstacle(new Dog(Game::startLine -9, 3 * distanceBetweenLine + 1, 1));
	Game::dogLine.makeSound();
	while (Game::isRunning)
	{
		Sleep(100);
		Game::dogLine.updateTrafficLight();
		if (Game::dogLine.isRed())
			Sleep(1000);
		if (Game::dogLine.getLineSize() == 0)
			Game::dogLine.insertNewObstacle(new Dog(Game::startLine-9, 3 * distanceBetweenLine + 1, 1));
		else if (Game::dogLine.getLineSize() < 1 && Game::dogLine.canAddNewObstacle())
			Game::dogLine.insertNewObstacle(new Dog(Game::startLine-9, 3 * distanceBetweenLine + 1, 1));
		Game::dogLine.move();
		Game::dogLine.deleteReachEndPoint(Game::endLine);
		Game::isHit(Game::player);
		Game::isHit(Game::playerTwo);
	}
}

void ThreadCrossLine()
{
	for (int i = 0; i < 4; i++)
	{
		Game::crossLine.push_back(CrossLine(1, distanceBetweenLine * (i + 1), 104));
	}
	while (Game::isRunning)
	{
		Sleep(10);
		for (int i = 0; i < 4; i++)
		{
			Game::crossLine[i].draw();
		}
	}
}

void ThreadFruit()
{
	Game::fruit.generateNewFruit();
	while (Game::isRunning)
	{
		Game::gameControl.drawScore();
		if (!Game::isInTwoPlayerMode)
		{
			Game::gameControl.drawFruitRequired();
		}
		if (Game::isColidePlayerWithFruit(Game::player, Game::fruit) && Game::fruitRequired>0 && Game::isColidePlayerWithFruit(Game::playerTwo, Game::fruit))
		{
			Game::fruitRequired--;
			Game::score += Game::level * 100;
			Game::fruit.collisionHandle();
		}
	}
}
void Game::startGame() {
	thread t1(ThreadCar);
	thread t2(ThreadTruck);
	thread t3(ThreadDog);
	thread t4(ThreadCrossLine);
	thread t5(ThreadFruit);
	Game::player.draw();
	Game::playerTwo.draw();
	while (Game::isRunning)
	{
		int temp = toupper(_getch());
		if (temp == 27) {
			Game::isRunning = false;
			if (t1.joinable())
				t1.join();
			if (t2.joinable())
				t2.join();
			if (t3.joinable())
				t3.join();
			if (t4.joinable())
				t4.join();
			if (t5.joinable())
				t5.join();
			break;
		}
		Game::player.undraw();
		Game::player.move(char(temp));
		Game::player.draw();

		Game::playerTwo.undraw();
		Game::playerTwo.move(char(temp));
		Game::playerTwo.draw();

		if (Game::fruitRequired == 0) {
			/*Game::isRunning = false;*/
			Game::generateGate();
			Game::gameControl.drawGate();
			if (Game::playerEnterGate(player) && Game::playerEnterGate(playerTwo))
			{
				Game::m.lock();
				goToXY(0, 0);
				cout << "hahahaha";
				Game::m.unlock();
			}
		}
	}
	if (t1.joinable())
		t1.join();
	if (t2.joinable())
		t2.join();
	if (t3.joinable())
		t3.join();
	if (t4.joinable())
		t4.join();
	if (t5.joinable())
		t5.join();
	if (Game::fruitRequired == 0 ) 
	{
		if (Game::playerEnterGate(player) && Game::playerEnterGate(playerTwo))
		{
			Game::gameControl.levelUp();
			system("cls");
			startGame();
		}
	}
}
bool Game::playerEnterGate(Player& player) {
	if (fruitRequired > 0)
		return false;
	vector<point> listPlayer = player.getListPoint();
	point temp = Game::gate[0];
	int startX = temp.getX() + 1;
	int endX = temp.getX() + gateLength - 2;
	int startY = temp.getY() + 2;
	int endY = temp.getY() + gateWidth - 1;
	for (int i = 0; i < listPlayer.size(); i++) {
		if (!(listPlayer[i].getX() >= startX && listPlayer[i].getX() <= endX))
			return false;
		if (!(listPlayer[i].getY() >= startY && listPlayer[i].getY() <= endY))
			return false;
	}
	return true;
}

void Game::generateGate()
{
	int startPointGate =1+ ((Game::endLine - Game::startLine + 1) / 2 - (gateLength / 2)) + Game::startLine;
	char gatePointHorizontalChar = 'X';
	char gatePointVerticalLeftChar = 'X';
	char gatePointVerticalRightChar = 'X';

	for (int i = 0; i < gateLength; i++)
	{
		Game::gate.push_back(point(startPointGate + i, 0, gatePointHorizontalChar));
		Game::gate.push_back(point(startPointGate + i, 1, gatePointHorizontalChar));
	}
	for (int i = 0; i < gateWidth; i++)
	{
		Game::gate.push_back(point(startPointGate, i, gatePointVerticalLeftChar));
	}
	for (int i = 0; i < gateWidth; i++)
	{
		Game::gate.push_back(point(startPointGate + gateLength - 1, i, gatePointVerticalRightChar));
	}
}
