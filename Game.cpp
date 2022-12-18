#include "Game.h"
bool Game::twoPlayerMode = false;
int Game::fruitRequired = 3;
int Game::fruitForThisLevel = 3;
Fruit Game::fruit = Fruit();
int Game::level = 1;
int Game::score = 0;
<<<<<<< HEAD
int Game::fruitRequired = 3;
int Game::fruitForThisLevel = 3;
int Game::startLine = 6;
int Game::endLine = 95;
Line Game::carLine = Line(104, distanceBetweenLine+2);
=======
int Game::score2 = 0;
bool Game::musicOn = true;
int Game::startLine = 6;
int Game::endLine = 119;
Line Game::carLine = Line(119, distanceBetweenLine+2 );
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
Line Game::truckLine = Line(1, 2*distanceBetweenLine+2);
Line Game::dogLine = Line(119, 3*distanceBetweenLine+2);
vector<CrossLine> Game::crossLine = vector<CrossLine>();
<<<<<<< HEAD
vector<point> Game::gate = vector<point>();
Player Game::player = Player(65, 30,1);
Player Game::playerTwo = Player(91, 30,2);
Fruit Game::fruit = Fruit();
bool Game::isRunning = 1;
bool Game::waiting = 0;
bool Game::isInTwoPlayerMode = false;
=======
Player Game::player = Player(45, 4 * distanceBetweenLine+1);
bool Game::isRunning = 1;
bool Game::isPaused = 0;
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
mutex Game::m;
GameControl Game::gameControl = GameControl();
Game::Game() {
	fruitRequired = 3;
	fruitForThisLevel = 3;
	fruit = Fruit();
	level = 1;
	score = 0;
<<<<<<< HEAD
	fruitRequired = 3;
	fruitForThisLevel = 3;
	startLine = 10;
	endLine = 95;
	carLine = Line();
	truckLine = Line();
	dogLine = Line();
<<<<<<< HEAD
	player = Player(65, 5 * distanceBetweenLine, 1);
	playerTwo = Player(91, 5 * distanceBetweenLine, 2);
=======
	player = Player(65, 5 * distanceBetweenLine);
	playerTwo = Player(81, 5 * distanceBetweenLine);
=======
	score2 = 0;
	musicOn = true;
	startLine = 10;
	endLine = 119;
	carLine = Line();
	truckLine = Line();
	dogLine = Line();
	crossLine = vector<CrossLine>();
	player = Player(45, 4 * distanceBetweenLine+1);
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
>>>>>>> fdb4b171e8ae21e71034e42e9187fdc21519fe2f
	isRunning = 1;
	isPaused = 0;
}
void Game::restartGame() {
<<<<<<< HEAD
	level = 1;
	score = 0;
	fruitRequired = 3;
	startLine = 10;
	endLine = 95;
	carLine = Line();
	truckLine = Line();
	dogLine = Line();
	player = Player(65, 5 * distanceBetweenLine, 1);
	playerTwo = Player(91, 5 * distanceBetweenLine, 2);
	isRunning = 1;
=======
	fruitRequired = 3;
	fruitForThisLevel = 3;
	fruit = Fruit();
	level = 1;
	score = 0;
	score2 = 0;
	startLine = 10;
	endLine = 119;
	carLine = Line();
	truckLine = Line();
	dogLine = Line();
	crossLine = vector<CrossLine>();
	player = Player(45, 4 * distanceBetweenLine+1);
	isRunning = 1;
	isPaused = 0;
	gameControl = GameControl();
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
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
<<<<<<< HEAD
void Game::isHit(Player& player) {
	if (checkHit(player)) 
	{
		exitGame();
	}
}
void Game::exitGame() 
{
	isRunning = false;
=======
void ThreadDeadSound() {
	PlaySound(TEXT("pacman-die.wav"), NULL, SND_ASYNC);
	Sleep(2000);
}
void Game::isHit() {
	if (checkHit()) {
		isRunning = false;
		thread dieSound(ThreadDeadSound);
		dieSound.detach();
		player.deathAnimation();
		Sleep(100);
		exitGame();
	}
}
void Game::exitGame() {
	gameControl.drawGameOverPopup();
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
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
<<<<<<< HEAD
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
=======
		Game::carLine.insertNewObstacle(new Car(Game::startLine, distanceBetweenLine + 1, 1));
	//Game::carLine.makeSound();
	while (Game::isRunning)
	{
		if (!Game::isPaused) {
			Sleep(100);
			Game::carLine.updateTrafficLight();
			if (Game::carLine.isRed())
				Sleep(1000);
			if (Game::carLine.getLineSize() == 0)
				Game::carLine.insertNewObstacle(new Car(Game::startLine, distanceBetweenLine + 1, 1));
			else if (Game::carLine.getLineSize() < 1 && Game::carLine.canAddNewObstacle())
				Game::carLine.insertNewObstacle(new Car(Game::startLine, distanceBetweenLine + 1, 1));
			Game::carLine.move();
			Game::carLine.deleteReachEndPoint(Game::endLine);
			Game::isHit();
		}
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
	}
}

void ThreadTruck()
{
	if (Game::truckLine.getLineSize() == 0)
<<<<<<< HEAD
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
=======
		Game::truckLine.insertNewObstacle(new Truck(Game::endLine, 2 * distanceBetweenLine + 1, -1));
	//Game::truckLine.makeSound();
	while (Game::isRunning)
	{
		if (!Game::isPaused) {
			Sleep(100);
			Game::truckLine.updateTrafficLight();
			if (Game::truckLine.isRed())
				Sleep(1000);
			if (Game::truckLine.getLineSize() == 0)
				Game::truckLine.insertNewObstacle(new Truck(Game::endLine, 2 * distanceBetweenLine + 1, -1));
			else if (Game::truckLine.getLineSize() < 1 && Game::truckLine.canAddNewObstacle())
				Game::truckLine.insertNewObstacle(new Truck(Game::endLine, 2 * distanceBetweenLine + 1, -1));
			Game::truckLine.move();
			Game::truckLine.deleteReachEndPoint(Game::startLine);
			Game::isHit();
		}
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
	}
}
void ThreadDog()
{
	if (Game::dogLine.getLineSize() == 0)
<<<<<<< HEAD
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
=======
		Game::dogLine.insertNewObstacle(new Dog(Game::startLine, 3 * distanceBetweenLine + 1, 1));
	//Game::dogLine.makeSound();
	while (Game::isRunning)
	{
		if (!Game::isPaused) {
			Sleep(100);
			Game::dogLine.updateTrafficLight();
			if (Game::dogLine.isRed())
				Sleep(1000);
			if (Game::dogLine.getLineSize() == 0)
				Game::dogLine.insertNewObstacle(new Dog(Game::startLine, 3 * distanceBetweenLine + 1, 1));
			else if (Game::dogLine.getLineSize() < 1 && Game::dogLine.canAddNewObstacle())
				Game::dogLine.insertNewObstacle(new Dog(Game::startLine, 3 * distanceBetweenLine + 1, 1));
			Game::dogLine.move();
			Game::dogLine.deleteReachEndPoint(Game::endLine);
			Game::isHit();
		}
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
	}
}

void ThreadCrossLine()
{
	for (int i = 0; i < 4; i++)
	{
		Game::crossLine.push_back(CrossLine(1, distanceBetweenLine * (i + 1), 119));
	}
	while (Game::isRunning)
	{
		if (!Game::isPaused) {
			Sleep(10);
			for (int i = 0; i < 4 && !Game::isPaused && Game::isRunning; i++)
			{
				Game::crossLine[i].draw();
			}
		}
	}
}
void ThreadFruit()
{
	Game::fruit.generateNewFruit();
	while (Game::isRunning)
	{
		Game::gameControl.drawScore();
		Game::gameControl.drawFruitRequired();
		Game::gameControl.drawLevel();
		if (Game::isColidePlayerWithFruit(Game::player, Game::fruit) && Game::fruitRequired > 0)
		{
			Game::fruitRequired--;
			Game::score += Game::level * 100;
			Game::fruit.collisionHandle();
		}
	}
}

void ThreadFruit()
{
	Game::fruit.generateNewFruit();
	bool gateDrawed = false;

	while (Game::isRunning)
	{
		////
		//Game::gameControl.drawScore();
		//if (!Game::isInTwoPlayerMode)
		//{
		//	Game::gameControl.drawFruitRequired();
		//}
		////
		//Game::isInTwoPlayerMode = true;
		////
		if (Game::isInTwoPlayerMode)
		{
			if (Game::isColidePlayerWithFruit(Game::player, Game::fruit))
			{
				Game::player.setScore(Game::player.getScore() + 100);
				Game::fruit.collisionHandle();
			}
			if (Game::isColidePlayerWithFruit(Game::playerTwo, Game::fruit))
			{
				Game::player.setScore(Game::player.getScore() + 100);
				Game::fruit.collisionHandle();
			}
		}
		else
		{
			if (Game::fruitRequired > 0)
			{
				if (Game::isColidePlayerWithFruit(Game::player, Game::fruit))
				{
					Game::fruitRequired--;
					Game::score += Game::level * 100;
					Game::fruit.collisionHandle();
				}
			}
			else
			{
				if (gateDrawed == false)
				{
					gateDrawed = true;
					Game::generateGate();
					Game::gameControl.drawGate();
				}
				if (Game::playerEnterGate(Game::player))
				{
					Game::player.winAnimation(1);
				}
			}
		}
	}
}

void Game::generateGate()
{
	int startPointGate = 1 + ((Game::endLine - Game::startLine + 1) / 2 - (gateLength / 2)) + Game::startLine;
	char gateCornerLeft = char(201);
	char gateCornerRight = char(187);
	char gatePointHorizontalChar = char(205);
	char gatePointVerticalLeftChar = char(186);
	char gatePointVerticalRightChar = char(186);

	for (int i = 0; i < gateLength; i++)
	{
		if (i == 0)
		{
			Game::gate.push_back(point(startPointGate + i, 0, gateCornerLeft));
		}
		else if (i == gateLength - 1)
		{
			Game::gate.push_back(point(startPointGate + i, 0, gateCornerRight));
		}
		else
		{
			Game::gate.push_back(point(startPointGate + i, 0, gatePointHorizontalChar));
		}
	}
	for (int i = 0; i < gateLength; i++)
	{
		if (i == 0)
		{
			Game::gate.push_back(point(startPointGate + i, 1, gatePointVerticalLeftChar));
		}
		else if (i == gateLength - 1)
		{
			Game::gate.push_back(point(startPointGate + i, 1, gatePointVerticalRightChar));
		}
		else
		{
			Game::gate.push_back(point(startPointGate + i, 1, '$'));
		}
	}
	for (int i = 2; i < gateWidth; i++)
	{
		Game::gate.push_back(point(startPointGate, i, gatePointVerticalLeftChar));
	}
	for (int i = 2; i < gateWidth; i++)
	{
		Game::gate.push_back(point(startPointGate + gateLength - 1, i, gatePointVerticalRightChar));
	}
}

bool Game::playerEnterGate(Player& player) {
	vector<point> listPlayer = player.getListPoint();
	point temp = Game::gate[0];
	int startX = temp.getX() + 1;
	int endX = temp.getX() + gateLength - 2;
	int startY = temp.getY() + 2;
	int endY = temp.getY() + gateWidth - 1;
	for (int i = 0; i < listPlayer.size(); i++) {
		if (!(listPlayer[i].getX() >= startX && listPlayer[i].getX() <= endX))
		{
			return false;
		}
		if (!(listPlayer[i].getY() >= startY && listPlayer[i].getY() <= endY))
		{
			return false;
		}
	}
	return true;
}

void Game::startGame() {
	Game::player.draw();
	/*Game::playerTwo.draw();*/
	Game::isInTwoPlayerMode = false;

	thread t1(ThreadCar);
	thread t2(ThreadTruck);
	thread t3(ThreadDog);
	thread t4(ThreadCrossLine);
	thread t5(ThreadFruit);
	
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
<<<<<<< HEAD
			if (t5.joinable())
				t5.join();
			break;
		}
		Game::player.undraw();
		Game::player.move(char(temp), 1);
		Game::player.draw();

		Game::playerTwo.undraw();
		Game::playerTwo.move(char(temp), 2);
		Game::playerTwo.draw();
<<<<<<< HEAD
=======

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
=======
			system("cls");
			gameControl.drawMenu();
			break;
		}
		
		if (temp == int('P')) {
			Game::gameControl.pauseGame();
		}
		if (temp == int('R')) {
			Game::gameControl.resumeGame();
		}
		if (temp == int('J')) {
			Game::gameControl.saveGame();
		}
		if (temp == int('L')) {
			Game::isPaused = true;
			Game::gameControl.drawLoadGamePopup();
			
			Game::isPaused = false;
		}
		if (!Game::isPaused) {
			player.undraw();
			Game::player.move(char(temp));
			Game::player.draw();
			if (Game::fruitRequired == 0) {
				Game::isRunning = false;
				Game::gameControl.drawGate();
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
			}
		}
>>>>>>> fdb4b171e8ae21e71034e42e9187fdc21519fe2f
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
<<<<<<< HEAD
	if (Game::fruitRequired == 0 ) 
	{
		if (Game::playerEnterGate(player))
		{
			Game::gameControl.levelUp();
			system("cls");
			startGame();
		}
	}
<<<<<<< HEAD
=======
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
=======
	if (Game::fruitRequired == 0) {
		Game::gameControl.levelUp();
		system("cls");
		gameControl.drawBorder();
		
		startGame();
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
	}
}
void Game::saveToFile(fstream& f) {
	f << level << " " << score<<'\n';
	f << fruitRequired << " " << fruitForThisLevel << '\n';
	f << carLine.getLineSize() << '\n';
	for (int i = 0; i < carLine.getLineSize(); i++) {
		f << carLine.getObstacleAt(i); 
	}
	f << truckLine.getLineSize() << '\n';
	for (int i = 0; i < truckLine.getLineSize(); i++) {
		f << truckLine.getObstacleAt(i);
	}
	f << dogLine.getLineSize() << '\n';
	for (int i = 0; i < dogLine.getLineSize(); i++) {
		f << dogLine.getObstacleAt(i);
	}
	vector<point> listPoint = player.getListPoint();
	f << listPoint.size() << '\n';
	for (int i = 0; i < listPoint.size(); i++)
		f << listPoint[i].getX() << " " << listPoint[i].getY()<< '\n';
}
void Game::loadGame(fstream& f) {
	restartGame();
	f >> level >> score;
	f >> fruitRequired >> fruitForThisLevel;
	int num;
	int OFFSET_X, OFFSET_Y;
	f >> num;
	while (num--) {
		int numPoint;
		f >> numPoint;
		f >> OFFSET_X >> OFFSET_Y;
		vector<point> listPoint;
		while (numPoint--) {
			int x, y;
			f >> x >> y;
			listPoint.push_back(point(x, y, ' '));
		}
		int direction, distance;
		f >> direction >> distance;
		carLine.insertNewObstacle(new Car(OFFSET_X,OFFSET_Y,listPoint, direction, distance));
	}
	f >> num;
	while (num--) {
		int numPoint;
		f >> numPoint;
		f >> OFFSET_X >> OFFSET_Y;
		vector<point> listPoint;
		while (numPoint--) {
			int x, y;
			f >> x >> y;
			listPoint.push_back(point(x, y, ' '));
		}
		int direction, distance;
		f >> direction >> distance;
		truckLine.insertNewObstacle(new Truck(OFFSET_X,OFFSET_Y,listPoint, direction, distance));
	}
	f >> num;
	while (num--) {
		int numPoint;
		f >> numPoint;
		f >> OFFSET_X >> OFFSET_Y;
		vector<point> listPoint;
		while (numPoint--) {
			int x, y;
			f >> x >> y;
			listPoint.push_back(point(x, y, ' '));
		}
		int direction, distance;
		f >> direction >> distance;
		dogLine.insertNewObstacle(new Dog(OFFSET_X,OFFSET_Y,listPoint, direction, distance));
	}
	f >> num;
	vector<point> listPoint;
	while (num--) {
		int x, y;
		f >> x >> y;
		listPoint.push_back(point(x, y, ' '));
	}
	player = Player(listPoint);
}
bool Game::isCollideWithFruit(point& temp)
{
	deque<point> listFruit = Game::fruit.getListPoint();
	for (int i = 0; i < listFruit.size(); i++)
	{
		if (temp.getX() == listFruit[i].getX() && temp.getY() == listFruit[i].getY())

			return true;
	}
	return false;
}
bool Game::isCollideWithPlayer(point& temp)
{
	vector<point> listPlayer = player.getListPoint();
	for (int i = 0; i < listPlayer.size(); i++)
	{
		if (temp.getX() == listPlayer[i].getX() && temp.getY() == listPlayer[i].getY())
			return true;
	}
	return false;
}
bool Game::isColidePlayerWithFruit(Player player, Fruit fruit)
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
>>>>>>> fdb4b171e8ae21e71034e42e9187fdc21519fe2f
}