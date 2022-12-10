#include "Game.h"
bool Game::waiting = 0;
mutex Game::m;

Game::Game() {
	level = 1;
	startLine = 10;
	endLine = 130;
	carLine = deque<Car>();
	dogLine = deque<Dog>();
	truckLine = deque<Truck>();
	player = Player(65, 30);
	isRunning = 1;
}
void Game::FixConsoleWindow()
{
	HWND hwnd = GetConsoleWindow();
	RECT rect = { 50, 50, 1500, 800 };
	MoveWindow(hwnd, rect.left, rect.top, rect.right - rect.left, rect.bottom - rect.top, TRUE);
	HWND consoleWindow = GetConsoleWindow();
	LONG style = GetWindowLong(consoleWindow, GWL_STYLE);

	style = style & ~(WS_MAXIMIZEBOX) & ~(WS_THICKFRAME);
	SetWindowLong(consoleWindow, GWL_STYLE, style);

	removeCursor(); 
}
void Game::SetWindowSize(SHORT width, SHORT height)
{

	COORD outbuff;
	outbuff.X = 50; // tem que ser 1 maior que o tamanho X
	outbuff.Y = 70; // tem que ser 1 maior que o tamanho Y
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleScreenBufferSize(hConsole, outbuff);
	Sleep(130);
	SMALL_RECT windowSize = { 0, 0, 900, 70 };
	SetConsoleWindowInfo(hConsole, TRUE, &windowSize);
}
void Game::gotoOxy(int x, int y)
{
	static HANDLE h = NULL;
	if (!h)
		h = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD c = { x, y };
	SetConsoleCursorPosition(h, c);

}
void Game::clrscr()
{
	COORD topLeft = { 0, 0 };
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, topLeft, &written
	);
	SetConsoleCursorPosition(console, topLeft);

}
void Game::drawBorder()
{
	int width = 80;
	int height = 30;
	int offsetX = 0;
	int offsetY = 0;
	for (int i = 0; i < height; i++) {
		if (i == 0) {
			Game::gotoOxy(offsetX, offsetY + i - 1);
			cout << char(220);
			continue;
		}
		Game::gotoOxy(offsetX, offsetY + i);
		cout << char(219);
	}
	for (int i = 0; i < width; i++) {
		Game::gotoOxy(offsetX + i, offsetY - 1);
		cout << char(220);
	}
	for (int i = 0; i < height; i++) {
		Game::gotoOxy(offsetX + width, offsetY + i);
		cout << char(219);
	}
	for (int i = 0; i < width; i++) {
		Game::gotoOxy(offsetX + 1 + i, offsetY);
		cout << char(220);
	}
	drawInfoMenu();

	while (1) {};
}
void Game::startGame()
{
	drawBorder();  
}
void Game::settingGame()
{
	gotoOxy(10, 10);
	cout << "Setting game";
}
void Game::drawMenu()
{
	menu(0, 10);
	int active = 0;
	bool isLoading = true; 
	while (isLoading) {
		char c = _getch();
		if (c == KEY_UP || c == 'w') {
			active--;
			if (active < 1) {
				active = 3;
			}
		}
		if (c == KEY_DOWN || c == 's') {
			active++;
			if (active > 3)
				active = 1;
		}
		if (c == KEY_ENTER) {
			if (active == 1) {
				isLoading = true; 
				system("cls");
				/*Game::gotoOxy(40, 40);*/
				/*Game::txtColor(DEFAULT_COLOR);*/
				startGame();
				break; 
			}
			if (active == 2) {
				isLoading = true; 
				clrscr();
				Game::gotoOxy(40, 40);
				Game::txtColor(DEFAULT_COLOR);
				settingGame();
				break; 
			}
			if (active == 3) {
				exit(1);
			}
			break;
		}
		clrscr();
		menu(active, 240);
	}

}
void Game::menu(int active = 0, int color = 10) {
	int x = 50, y = 3;
	Game::txtColor(color);
	if (active == 0) {
		Game::gotoOxy(x + 5, y + 3); cout << "New Game";
		Game::gotoOxy(x + 5, y + 5); cout << "Settings";
		Game::gotoOxy(x + 5, y + 7); cout << "Exit";
	}
	if (active == 1) {
		Game::txtColor(color);
		Game::gotoOxy(x + 5, y + 3); cout << "NEW GAME";
		Game::txtColor(10);
		Game::gotoOxy(x + 5, y + 5); cout << "Settings";
		Game::gotoOxy(x + 5, y + 7); cout << "Exit";
	}
	if (active == 2) {
		Game::txtColor(color);
		Game::gotoOxy(x + 5, y + 5); cout << "SETTINGS";
		Game::txtColor(10);
		Game::gotoOxy(x + 5, y + 3); cout << "NEW GAME";
		Game::gotoOxy(x + 5, y + 7); cout << "Exit";
	}
	if (active == 3) {
		Game::txtColor(color);
		Game::gotoOxy(x + 5, y + 7); cout << "Exit";
		Game::txtColor(10);
		Game::gotoOxy(x + 5, y + 3); cout << "NEW GAME";
		Game::gotoOxy(x + 5, y + 5); cout << "Settings";
	}
}
void Game::drawInfoMenu()
{
	int offsetX = 92;  
	map<int, string> keyboards = {
		{1, "W: Up"},
		{2, "S: Down"},
		{3, "A: Left"},
		{4, "D: Right"},
	}; 
	map<int, string> commands = {
		{1, "J: Save Game"},
		{2, "L: Load Game"},
		{3, "P: Pause Game"}
	}; 
	txtColor(79); 
	gotoOxy(offsetX, 10); 
	cout << "Moving keyboards: "; 
	for (int i = 1; i <= 4; i++) {
		gotoOxy(offsetX, 10 + i); 
		txtColor(14); 
		cout << keyboards[i]; 
	}
	txtColor(79); 
	gotoOxy(offsetX, 15); 
	cout << "Command keyboards: "; 
	for (int i = 1; i <= 4; i++) {
		gotoOxy(offsetX, 15 + i);
		txtColor(14); 
		cout << commands[i];
	}
	

}
void Game::drawLoserScreen() {
	cout << "__     __                                    _                     _" << endl; 
	cout << "\ \   / /                                   | |                   | |" << endl; 
	cout << "\ \_/ /__  _   _    __ _ _ __ ___    __ _  | | ___  ___  ___ _ __| |" << endl; 
	cout << "\ / _ \| | | |  / _` | '__/ _ \  / _` | | |/ _ \/ __|/ _ \ '__| |" << endl; 
	cout << "| | (_) | |_| | | (_| | | |  __/ | (_| | | | (_) \__ \  __/ |  |_|" << endl; 
	cout << "|_ | \___ / \__, _ | \__, _ | _ | \___ | \__, _| |_ | \___/|___ / \___ | _ | (_)" << endl; 

}
void Game::drawLeaderboardScreen()
{
	map<int, string> players = {
		{1, "Quy Hoa"},
		{2, "Thanh Dat"},
		{3, "Duc Anh"},
	}; 
	gotoOxy(50, 5); 
	cout << "All players: "; 
	for (auto& el : players) {
		gotoOxy(50, 5 + el.first);
		cout << el.first << "." << el.second;
	}
	while (1) {
		txtColor(1); 
		char c = _getch();
		auto it = players.find(int(c) - '0'); 
		if (it != players.end()) {
			gotoOxy(50, 5 + it->first); 
			txtColor(240); 
			cout << it->first << "." << it->second;
			txtColor(7); 
			for (auto p = players.begin(); p != players.end(); p++) {
				if (p != it) {
					gotoOxy(50, 5 + p->first);
					cout << p->first << "." << p->second;
				}
			}
		}
	}
}

void Game::removeCursor() {
	CONSOLE_CURSOR_INFO Info;
	Info.bVisible = FALSE;
	Info.dwSize = 20;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Info);
}
void Game::txtColor(int color) {
	HANDLE hConsoleColor;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
void gotooxy(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), c);
}
void Game::exitGame() {
	isRunning = false;
}

void Game::showConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_CURSOR_INFO cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag;
	SetConsoleCursorInfo(out, &cursorInfo);
};
bool Game::isColide(Player player, Obstacle obstacle) {
	vector<point> listPointPlayer = player.getListPoint();
	vector<point> listPointObstacle = obstacle.getListPoint();
	for (int i = 0; i < listPointPlayer.size(); i++)
		for (int j = 0; j < listPointObstacle.size(); j++) {
			if (listPointPlayer[i].getX() == listPointObstacle[j].getX() && listPointPlayer[i].getY() == listPointObstacle[j].getY())
				return true;
		}
	return false;
}
bool Game::checkHit() {
	for (int i = 0; i < carLine.size(); i++) {
		if (isColide(player, carLine[i]))
			return true;
	}
	for (int i = 0; i < truckLine.size(); i++) {
		if (isColide(player, truckLine[i]))
			return true;
	}
	for (int i = 0; i < dogLine.size(); i++) {
		if (isColide(player, dogLine[i]))
			return true;
	}
	return false;
}
void Game::isHit() {
	 if (checkHit()) {
		 exitGame();
	 }
 }


