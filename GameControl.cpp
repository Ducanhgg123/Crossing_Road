#include "GameControl.h"
#include "Game.h"
void GameControl::clrscr() {
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
void GameControl::drawRectangle(int offset_X, int offset_Y, int width, int height, int color) {
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
		goToXY(i, offset_Y + height - 1);
		cout << char(219);
		TextColor(colorDefault);
		Game::m.unlock();
	}
	// Draw right
	for (int i = offset_Y + height - 1; i >= offset_Y; i--) {
		Game::m.lock();
		TextColor(color);
		goToXY(offset_X + width, i);
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
void GameControl::drawMenu() {
	int active = 0;
	bool isLoading = true;
	map<int, string>  menus = {
		{1, "New game"},
		{2, "Settings"},
		{3, "Leaderboard"},
		{4, "Exit"}
	};
	Game::m.lock();
	goToXY(25, 5);
	TextColor(colorDefault);
	Game::m.unlock();
	for (auto& menu : menus) {
		Game::m.lock();
		goToXY(25, 5 + menu.first);
		cout << menu.second;
		Game::m.unlock();
	}
	while (isLoading) {
		char c = _getch();
		if (c == KEY_UP || c == 'w') {
			active--;
			if (active < 1) {
				active = 4;
			}
		}
		if (c == KEY_DOWN || c == 's') {
			active++;
			if (active > 4)
				active = 1;
		}
		if (c == KEY_ENTER) {
			if (active == 1) {
				isLoading = true;
				Game::m.lock();
				system("cls");
				TextColor(colorDefault);
				/*Game::gotoOxy(40, 40);*/
				/*Game::txtColor(DEFAULT_COLOR);*/
				Game::m.unlock();
				startGame();
				
				break;
			}
			if (active == 2) {
				isLoading = true;
				Game::m.lock();
				system("cls");
				goToXY(40, 40);
				TextColor(colorDefault);
				settingGame();
				Game::m.unlock();
				break;
			}
			if (active == 3) {
				Game::m.lock();
				system("cls");
				drawLeaderboard();
				Game::m.unlock();
			}
			if (active == 4) {
				exit(1);
			}
			break;
		}
		for (auto& menu : menus) {
			if (active == menu.first) {
				Game::m.lock();
				TextColor(activeColor);
				goToXY(25, 5 + menu.first);
				cout << menu.second;
				TextColor(colorDefault);
				Game::m.unlock();
				continue;
			}
			Game::m.lock();
			TextColor(colorDefault);
			goToXY(25, 5 + menu.first);
			cout << menu.second;
			Game::m.unlock();
		}
	}
}
void GameControl::drawBorder() {
	int width = 105;
	int height = 35;
	int offsetX = 0;
	int offsetY = 0;
	
	drawRectangle(offsetX, offsetY, width, height, colorDefault);
	drawInfoMenu();
}
void GameControl::drawLeaderboard() {
	map<int, string> players = {
		{1, "Quy Hoa"},
		{2, "Thanh Dat"},
		{3, "Duc Anh"},
	};
	goToXY(50, 5);
	cout << "All players: ";
	for (auto& el : players) {
		goToXY(50, 5 + el.first);
		cout << el.first << "." << el.second;
	}
	while (1) {
		char c = _getch();
		auto it = players.find(int(c) - '0');
		if (it != players.end()) {
			goToXY(50, 5 + it->first);
			TextColor(activeColor);
			cout << it->first << "." << it->second;
			TextColor(colorDefault);
			for (auto p = players.begin(); p != players.end(); p++) {
				if (p != it) {
					goToXY(50, 5 + p->first);
					cout << p->first << "." << p->second;
				}
			}
		}
	}
}
void GameControl::drawGameOverPopup() {
	int width = 25;
	int height = 10;
	int offsetX = 15;
	int offsetY = 10;
	drawRectangle(offsetX, offsetY, width, height,colorDefault);
	map<int, string> contents = {
		{1, "1.Back to menu"},
		{2, "2.Save game"},
	};
	for (auto& el : contents) {
		Game::m.lock();
		goToXY(offsetX + 4, offsetY + el.first + 2);
		cout << el.second;
		Game::m.unlock();
	}
	char c = _getch();
	if (c == '1') {
		system("cls");
		drawMenu();
	}
	if (c == '2') {
		clrscr();
		saveGame();
	};
}
void GameControl::settingGame(){

}
void GameControl::startGame() {
	system("cls");
	TextColor(colorDefault);
	drawBorder();
	Game::startGame();
}
void GameControl::drawInfoMenu() {
	int offsetX = 130;
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
	Game::m.lock();
	TextColor(colorDefault);
	goToXY(offsetX, 10);
	
	cout << "Moving keyboards: ";
	for (int i = 1; i <= 4; i++) {
		goToXY(offsetX, 10 + i);
		TextColor(colorDefault);
		cout << keyboards[i];
	}
	TextColor(colorDefault);
	goToXY(offsetX, 15);
	cout << "Command keyboards: \n";
	for (int i = 1; i <= 4; i++) {
		goToXY(offsetX, 15 + i);
		TextColor(colorDefault);
		cout << commands[i];
	}
	Game::m.unlock();
}
void GameControl::saveGame() {

}