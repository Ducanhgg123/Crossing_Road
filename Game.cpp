#include "Game.h"
int Game::level = 1;
int Game::startLine = 6;
int Game::endLine = 95;
Line Game::carLine = Line(104, distanceBetweenLine+2 );
Line Game::truckLine = Line(1, 2*distanceBetweenLine+2);
Line Game::dogLine = Line(104, 3*distanceBetweenLine+2);
vector<CrossLine> Game::crossLine = vector<CrossLine>();
Player Game::player = Player(65, 30);
bool Game::isRunning = 1;
bool Game::waiting = 0;
mutex Game::m;
GameControl Game::gameControl = GameControl();
Game::Game() {
	level = 1;
	startLine = 10;
	endLine = 130;
	carLine = Line();
	truckLine = Line();
	dogLine = Line();
	player = Player(65, 5 * distanceBetweenLine);
	isRunning = 1;
}
bool Game::isColide(Player player, Obstacle*& obstacle) {
	vector<point> listPointPlayer = player.getListPoint();
	vector<point> listPointObstacle = obstacle->getListPoint();
	for (int i=0;i<listPointPlayer.size();i++)
		for (int j = 0; j < listPointObstacle.size(); j++) {
			if (listPointPlayer[i].getX() == listPointObstacle[j].getX() && listPointPlayer[i].getY() == listPointObstacle[j].getY())
				return true;
		}
	return false;
}
bool Game::checkHit() {
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
void Game::isHit() {
	if (checkHit()) {
		exitGame();
	}
}
void Game::exitGame() {
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
		Game::carLine.insertNewObstacle(new Car(Game::startLine, distanceBetweenLine + 1, 1));
	Game::carLine.makeSound();
	while (Game::isRunning)
	{
		Sleep(10);
		Game::carLine.updateTrafficLight();
		if (Game::carLine.isRed())
			Sleep(1000);
		if (Game::carLine.getLineSize() == 0)
			Game::carLine.insertNewObstacle(new Car(Game::startLine, distanceBetweenLine + 1, 1));
		else if (Game::carLine.getLineSize() < 4 && Game::carLine.canAddNewObstacle())
			Game::carLine.insertNewObstacle(new Car(Game::startLine, distanceBetweenLine + 1, 1));
		Game::carLine.move();
		Game::carLine.deleteReachEndPoint(Game::endLine);
		if (Game::checkHit()) {
			Game::exitGame();
			cout << "Hitted";
		}
	}
}
void ThreadTruck()
{
	if (Game::truckLine.getLineSize() == 0)
		Game::truckLine.insertNewObstacle(new Truck(Game::endLine, 2 * distanceBetweenLine + 1, -1));
	Game::truckLine.makeSound();
	while (Game::isRunning)
	{
		Sleep(10);
		Game::truckLine.updateTrafficLight();
		if (Game::truckLine.isRed())
			Sleep(1000);
		if (Game::truckLine.getLineSize() == 0)
			Game::truckLine.insertNewObstacle(new Truck(Game::endLine, 2 * distanceBetweenLine + 1, -1));
		else if (Game::truckLine.getLineSize() < 3 && Game::truckLine.canAddNewObstacle())
			Game::truckLine.insertNewObstacle(new Truck(Game::endLine, 2 * distanceBetweenLine + 1, -1));
		Game::truckLine.move();
		Game::truckLine.deleteReachEndPoint(Game::startLine);
		if (Game::checkHit()) {
			Game::exitGame();
			cout << "Hitted";
		}
	}
}
void ThreadDog()
{
	if (Game::dogLine.getLineSize() == 0)
		Game::dogLine.insertNewObstacle(new Dog(Game::startLine, 3 * distanceBetweenLine + 1, 1));
	Game::dogLine.makeSound();
	while (Game::isRunning)
	{
		Sleep(10);
		Game::dogLine.updateTrafficLight();
		if (Game::dogLine.isRed())
			Sleep(1000);
		if (Game::dogLine.getLineSize() == 0)
			Game::dogLine.insertNewObstacle(new Dog(Game::startLine, 3 * distanceBetweenLine + 1, 1));
		else if (Game::dogLine.getLineSize() < 4 && Game::dogLine.canAddNewObstacle())
			Game::dogLine.insertNewObstacle(new Dog(Game::startLine, 3 * distanceBetweenLine + 1, 1));
		Game::dogLine.move();
		Game::dogLine.deleteReachEndPoint(Game::endLine);
		if (Game::checkHit()) {
			Game::exitGame();
			cout << "Hitted";
			Game::isRunning = false;
		}
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
void Game::startGame() {
	thread t1(ThreadCar);
	thread t2(ThreadTruck);
	thread t3(ThreadDog);
	thread t4(ThreadCrossLine);
	Game::player.draw();
	while (Game::isRunning)
	{
		if (Game::checkHit()) {
			Game::exitGame();
			cout << "Hitted";
			Game::isRunning = false;
			if (t1.joinable())
				t1.join();
			if (t2.joinable())
				t2.join();
			if (t3.joinable())
				t3.join();
			if (t4.joinable())
				t4.join();
			break;
		}
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
			break;
		}
		Game::player.undraw();
		Game::player.move(char(temp));
		Game::player.draw();
	}
	if (t1.joinable())
		t1.join();
	if (t2.joinable())
		t2.join();
	if (t3.joinable())
		t3.join();
	if (t4.joinable())
		t4.join();
}
