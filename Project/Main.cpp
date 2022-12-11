#include "lib.h"
#include "Game.h"

void printFromPosition(int x, int y, int width, int height,vector<string> player) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < width; j++) {
			Game::gotoOxy(x + j, y + i);
			cout << player[i][j];
		}
	}
}
void deleteFromPosition(int x, int y, int width, int height,vector<string> player) {
	for (int i = 0; i < height; i++) {
		for (int j = 0; j < player[i].size(); j++) {
			Game::gotoOxy(x + j, y + i);
			cout << ' ';
		}
	}
}
int Game::level = 1;
int Game::startLine = 10;
int Game::endLine = 130;
deque<Car> Game::carLine = deque<Car>();
deque<Dog> Game::dogLine = deque<Dog>();
deque<Truck> Game::truckLine = deque<Truck>();
//Player Game::player = Player(65, 30);
bool Game::isRunning = 1;

//void ThreadT1()
//{
//	while (Game::isRunning)
//	{
//		Sleep(30);
//		if (Game::waiting)
//			continue;
//		//Car
//		if (Game::carLine.size() == 0)
//		{
//			Game::carLine.push_back(Car(Game::startLine, 10, 1));
//		}
//		else if (Game::carLine.size() < 4 && Game::carLine[Game::carLine.size() - 1].getDistanceFromStart() > Game::carLine[Game::carLine.size() - 1].getDistance())
//			Game::carLine.push_back(Car(Game::startLine, 10, 1));
//		for (int i = 0; i < Game::carLine.size(); i++) {
//			Game::carLine[i].undrawBack();
//			Game::carLine[i].move();
//			Game::carLine[i].draw();
//		}
//		if (Game::carLine[0].reachEndPoint(Game::endLine)) {
//			Game::carLine[0].undraw();
//			Game::carLine.pop_front();
//		}
//
//		//Truck
//		if (Game::truckLine.size() == 0)
//		{
//			Game::truckLine.push_back(Truck(Game::endLine, 15, -1));
//		}
//		else if (Game::truckLine.size() < 3 && Game::truckLine[Game::truckLine.size() - 1].getDistanceFromStart() > Game::truckLine[Game::truckLine.size() - 1].getDistance())
//			Game::truckLine.push_back(Truck(Game::endLine, 15, -1));
//		for (int i = 0; i < Game::truckLine.size(); i++) {
//			Game::truckLine[i].undrawBack();
//			Game::truckLine[i].move();
//			Game::truckLine[i].draw();
//		}
//		if (Game::truckLine[0].reachEndPoint(Game::startLine)) {
//			Game::truckLine[0].undraw();
//			Game::truckLine.pop_front();
//		}
//		//Dog
//		if (Game::dogLine.size() == 0 && !Game::waiting)
//		{
//			Game::dogLine.push_back(Dog(Game::startLine, 20, 1));
//		}
//		else if (Game::dogLine.size() < 4 && Game::dogLine[Game::dogLine.size() - 1].getDistanceFromStart() > Game::dogLine[Game::dogLine.size() - 1].getDistance() && !Game::waiting)
//			Game::dogLine.push_back(Dog(Game::startLine, 20, 1));
//		for (int i = 0; i < Game::dogLine.size(); i++) {
//			Game::dogLine[i].undrawBack();
//			Game::dogLine[i].move();
//			Game::dogLine[i].draw();
//		}
//		if (Game::dogLine[0].reachEndPoint(Game::endLine)) {
//			Game::dogLine[0].undraw();
//			Game::dogLine.pop_front();
//		}
//		if (Game::checkHit()) {
//			Game::exitGame();
//			cout << "Hitted";
//		}
//	}
//}
//void t2() {
//	while (Game::isRunning) {
//
//	}
//}

void FixConsoleWindow()
{
	HWND hwnd = GetConsoleWindow();
	RECT rect = { 50, 50, 1500, 800 };
	MoveWindow(hwnd, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, TRUE);
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);

	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);
} 
void writeMockData() {
	fstream file; 
	file.open("players.dat", ios::binary | ios::out); 

	vector<string> names = { "Quy Hoa", "Thanh Dat", "Duc Anh" }; 
	for (auto& name : names){
		file.write((char*)&name, sizeof(name)); 
	}
}

int main()
{
	//thread t1(ThreadT1);
	//Game game;
	Game::SetWindowSize(600, 600); 
	Game::FixConsoleWindow(); 
	//Game::player.draw();
	
	Game game; 
	//writeMockData(); 
	/*game.saveGame("Quy Hoa Clone"); 
	game.getPlayerFromFile("Quy Hoa Clone"); */ 
	return 0;
}
//Player player;
//printFromPosition(player.x, player.y, 3, 3, player.getPlayer());
//while (Game::isRunning)
//{
//	if (Game::checkHit()) {
//		Game::isHit();
//		cout << "Hitted";
//		Game::isRunning = false;
//		return 0;
//	}
//
//	if (_kbhit()) {
//		char c = _getch();
//		if (c == 'w') {
//			deleteFromPosition(player.x, player.y, 3, 3, player.getPlayer());
//			player.up();
//			printFromPosition(player.x, player.y, 3, 3, player.getPlayer());
//		}
//		if (c == 's') {
//			deleteFromPosition(player.x, player.y, 3, 3, player.getPlayer());
//			player.down();
//			printFromPosition(player.x, player.y, 3, 3, player.getPlayer());
//		}
//		if (c == 'a') {
//			deleteFromPosition(player.x, player.y, 3, 3, player.getPlayer());
//			player.left();
//			printFromPosition(player.x, player.y, 3, 3, player.getPlayer());
//		}
//		if (c == 'd') {
//			deleteFromPosition(player.x, player.y, 3, 3, player.getPlayer());
//			player.right();
//			printFromPosition(player.x, player.y, 3, 3, player.getPlayer());
//		}
//	}
//	if (Game::carLine.size() == 0)
//	{
//		Game::carLine.push_back(Car(Game::startLine, 10, 1));
//	}
//	else if (Game::carLine.size() < 4 && Game::carLine[Game::carLine.size() - 1].getDistanceFromStart() > Game::carLine[Game::carLine.size() - 1].getDistance())
//		Game::carLine.push_back(Car(Game::startLine, 10, 1));
//	for (int i = 0; i < Game::carLine.size(); i++) {
//		Game::carLine[i].undrawBack();
//		Game::carLine[i].move();
//		Game::carLine[i].draw();
//	}
//	if (Game::carLine[0].reachEndPoint(Game::endLine)) {
//		Game::carLine[0].undraw();
//		Game::carLine.pop_front();
//	}
//
//	//Truck
//	if (Game::truckLine.size() == 0)
//	{
//		Game::truckLine.push_back(Truck(Game::endLine, 15, -1));
//	}
//	else if (Game::truckLine.size() < 3 && Game::truckLine[Game::truckLine.size() - 1].getDistanceFromStart() > Game::truckLine[Game::truckLine.size() - 1].getDistance())
//		Game::truckLine.push_back(Truck(Game::endLine, 15, -1));
//	for (int i = 0; i < Game::truckLine.size(); i++) {
//		Game::truckLine[i].undrawBack();
//		Game::truckLine[i].move();
//		Game::truckLine[i].draw();
//	}
//	if (Game::truckLine[0].reachEndPoint(Game::startLine)) {
//		Game::truckLine[0].undraw();
//		Game::truckLine.pop_front();
//	}
//}
