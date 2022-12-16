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
void GameControl::FontSize(int size)
{
	static CONSOLE_FONT_INFOEX  fontex;
	fontex.cbSize = sizeof(CONSOLE_FONT_INFOEX);
	HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	GetCurrentConsoleFontEx(hOut, 0, &fontex);
	fontex.FontWeight = 700;
	fontex.dwFontSize.X = size;
	fontex.dwFontSize.Y = size;
	SetCurrentConsoleFontEx(hOut, NULL, &fontex);
}
void GameControl::TextColor(int x)
{
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, x);
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
	drawLogoCrossingGame();
	int active = 0;
	bool isLoading = true;
	map<int, string>  menus = {
		{1, "New game"},
		{2, "Two players mode"},
		{3, "Settings"},
		{4, "Leaderboard"},
		{5, "Exit"}
	};

	TextColor(colorCyan);
	int offsetX = 60;
	int offsetY = 20;
	for (auto& menu : menus) {
		goToXY(offsetX, offsetY + menu.first);
		cout << menu.second;
	}
	while (isLoading) {
		char c = _getch();
		if (c == KEY_UP || c == 'w') {
			active--;
			if (active < 1) {
				active = 5;
			}
		}
		if (c == KEY_DOWN || c == 's') {
			active++;
			if (active > 5)
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
			if (active == 3) {
				isLoading = true;

				system("cls");
				goToXY(40, 40);
				TextColor(colorDefault);
				settingGame();

				break;
			}
			if (active == 4) {

				system("cls");
				drawLeaderboard();

			}
			if (active == 5) {
				system("cls");
				exit(1);
			}
			break;
		}
		for (auto& menu : menus) {
			if (active == menu.first) {
				TextColor(activeColor); // active color
				goToXY(offsetX - 5, offsetY + menu.first);
				cout << "--->";
				goToXY(offsetX + menu.second.size() + 1, offsetY + menu.first);
				cout << "<---";
				goToXY(offsetX, offsetY + menu.first);
				cout << menu.second;
				TextColor(colorCyan); // Default Color
				continue;
			}
			TextColor(colorGreen); // Active color
			goToXY(offsetX - 5, offsetY + menu.first);
			cout << "    ";
			goToXY(offsetX + menu.second.size() + 1, offsetY + menu.first);
			cout << "    ";
			TextColor(colorCyan);
			goToXY(offsetX, offsetY + menu.first);
			cout << menu.second;

		}
	}
}
void GameControl::drawBorder() {
	int width = 120;
	int height = 34;
	int offsetX = 0;
	int offsetY = 0;

	drawRectangle(offsetX, offsetY, width, height, colorCyan);
	
	drawLogoTeam(); 
	drawScore();
	drawFruitRequired(); 
	drawInfoMenu();
}
void GameControl::drawLeaderboard() {
	map<int, string> players = {
		{1, "Quy Hoa"},
		{2, "Thanh Dat"},
		{3, "Duc Anh"},
	};
	int active = 0;
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

		if (c == KEY_DOWN) {
			active++;
			if (active > players.size()) {
				active = 1;
			}
			auto it = players.find(int(active));
			if (it != players.end()) {
				goToXY(50, 5 + it->first);
				TextColor(3);
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

		if (c == KEY_UP) {
			active--;
			if (active < 1) {
				active = players.size();
			}
			auto it = players.find(active);
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

		if (c == KEY_ESC) {
			system("cls");
			drawMenu();
		}
	}
}
void GameControl::drawGameOverPopup() {
	int width = 60;
	int height = 15;
	int offsetX = 15;
	int offsetY = 10;
	drawRectangle(offsetX - 1, offsetY - 1, width + 2, height + 2, colorShit); 
	drawRectangle(offsetX, offsetY, width, height, colorGreen);
	goToXY(offsetX + 8, offsetY + 1);
	cout << R"(
		   _____                                             _ 
		  / ____|                                           | |
		  | |  __  __ _ _ __ ___   ___    _____   _____ _ __| |
		  | | |_ |/ _` | '_ ` _ \ / _ \  / _ \ \ / / _ \ '__| |
		  | |__| | (_| | | | | | |  __/ | (_) \ V /  __/ |  |_|
		   \_____|\__,_|_| |_| |_|\___|  \___/ \_/ \___|_|  (_)
)" << endl; 
	map<int, string> contents = {
		{1, "1.Back to menu"},
		{2, "2.Restart"},
	};

	for (auto& el : contents) {
		Game::m.lock();
		goToXY(offsetX + 15, offsetY + el.first + 9); 	
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
void GameControl::drawGameWinPopup()
{

	int width = 30;
	int height = 7;
	int offsetX = 15;
	int offsetY = 10;
	drawRectangle(offsetX, offsetY, width, height, colorYellow);
	goToXY(offsetX + 8, offsetY + 1);
	cout << R"(

   _____                            _         _       _   _             _ 
  / ____|                          | |       | |     | | (_)           | |
 | |     ___  _ __   __ _ _ __ __ _| |_ _   _| | __ _| |_ _  ___  _ __ | |
 | |    / _ \| '_ \ / _` | '__/ _` | __| | | | |/ _` | __| |/ _ \| '_ \| |
 | |___| (_) | | | | (_| | | | (_| | |_| |_| | | (_| | |_| | (_) | | | |_|
  \_____\___/|_| |_|\__, |_|  \__,_|\__|\__,_|_|\__,_|\__|_|\___/|_| |_(_)
                     __/ |                                                
                    |___/                                                 
)" << endl; 


	map<int, string> contents = {
		{1, "Back to menu"},
		{2, "Restart"},
	};
	for (auto& el : contents) {
		goToXY(offsetX + 4, offsetY + el.first + 2);
		cout << el.second;
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
void GameControl::drawLoadGamePopup()
{
	int width = 60;
	int height = 15;
	int offsetX = 15;
	int offsetY = 10;
	drawRectangle(offsetX, offsetY, width, height, colorRed);
	//string loadGame = "Load game";
	goToXY(offsetX + 12, offsetY);
	cout << R"(
		   _                     _    _____                      
		  | |                   | |  / ____|                     
		  | |     ___   __ _  __| | | |  __  __ _ _ __ ___   ___ 
		  | |    / _ \ / _` |/ _` | | | |_ |/ _` | '_ ` _ \ / _ \
		  | |___| (_) | (_| | (_| | | |__| | (_| | | | | | |  __/
		  |______\___/ \__,_|\__,_|  \_____|\__,_|_| |_| |_|\___|)" << endl; 
	int active = 0;
	map<int, string> players = {
		{1, "Quy Hoa"},
		{2, "Thanh Dat"},
		{3, "Duc Anh"},
	};
	for (auto& player : players) {
		TextColor(colorDefault);
		goToXY(offsetX + 23, offsetY + player.first + 7);
		cout << player.second;
	}

	while (1) {
		char c = _getch();
		auto it = players.find(int(c) - '0');
		if (it != players.end()) {
			goToXY(offsetX + 23, offsetY + it->first + 7);
			TextColor(activeColor);
			cout << it->second;
			TextColor(colorDefault);
			for (auto p = players.begin(); p != players.end(); p++) {
				if (p != it) {
					goToXY(offsetX + 23, offsetY + p->first + 7);
					cout << p->second;
				}
			}
		}

		if (c == KEY_DOWN) {
			active++;
			if (active > players.size()) {
				active = 1;
			}
			auto it = players.find(int(active));
			if (it != players.end()) {
				goToXY(offsetX + 23, offsetY + it->first + 7);
				TextColor(3);
				cout << it->second;
				TextColor(colorDefault);
				for (auto p = players.begin(); p != players.end(); p++) {
					if (p != it) {
						goToXY(offsetX + 23, offsetY + p->first + 7);
						cout << p->second;
					}
				}
			}
		}

		if (c == KEY_UP) {
			active--;
			if (active < 1) {
				active = players.size();
			}
			auto it = players.find(active);
			if (it != players.end()) {
				goToXY(offsetX + 23, offsetY + it->first + 7);
				TextColor(activeColor);
				cout << it->second;
				TextColor(colorDefault);
				for (auto p = players.begin(); p != players.end(); p++) {
					if (p != it) {
						goToXY(offsetX + 23, offsetY + p->first + 7);
						cout << p->second;
					}
				}
			}
		}

		if (c == KEY_ESC) {
			cout << "Continue";
		}
		
		if (c == KEY_ESC) {
			for (int i = offsetX; i <= offsetX + width; i++)
				for (int j = offsetY; j <= offsetY + height; j++) {
					Game::m.lock();
					goToXY(i, j);
					cout << " ";
					Game::m.unlock();
				}
			break;
		}
		
	}

}
void GameControl::drawContinuePopup()
{
	int width = 58;
	int height = 11;
	int offsetX = 38;
	int offsetY = 10;
	drawRectangle(offsetX, offsetY, width, height, colorYellow);
	goToXY(offsetX + 2, offsetY + 1);
	
	cout << R"(
					        _____            _   _                  
					       / ____|          | | (_)                 
					      | |     ___  _ __ | |_ _ _ __  _   _  ___ 
					      | |    / _ \| '_ \| __| | '_ \| | | |/ _ \
					      | |___| (_) | | | | |_| | | | | |_| |  __/
					       \_____\___/|_| |_|\__|_|_| |_|\__,_|\___|
)" << endl; 
	
	while (1) {

		char c = _getch();
		if (c == KEY_ESC) {
			for (int i = offsetX; i <= offsetX + width; i++)
				for (int j = offsetY; j <= offsetY + height; j++) {
					Game::m.lock();
					goToXY(i, j);
					cout << " ";
					Game::m.unlock();
				}
			break;
		}
	}
}
void GameControl::settingGame() {

}
void GameControl::drawSaveGamePopup()
{
	int width = 40;
	int height = 7;
	int offsetX = 38;
	int offsetY = 10;
	drawRectangle(offsetX, offsetY, width, height, colorYellow);
	goToXY(offsetX + 2, offsetY + 3);
	string userName;
	cout << "Enter your name: ";/* cin >> userName;*/
	/*cout << R"(
	   _____                    _____                      
	  / ____|                  / ____|                     
	 | (___   __ ___   _____  | |  __  __ _ _ __ ___   ___ 
	  \___ \ / _` \ \ / / _ \ | | |_ |/ _` | '_ ` _ \ / _ \
	  ____) | (_| |\ V /  __/ | |__| | (_| | | | | | |  __/
	 |_____/ \__,_| \_/ \___|  \_____|\__,_|_| |_| |_|\___|                                                      
)" << endl;*/ 
	while (1) {

	char c = _getch();
		if (c == KEY_ENTER) {
			system("cls");
			cout << "save game";
		}
		if (c == KEY_ESC) {
			cout << "esc"; 
			for (int i = offsetX; i <= offsetX + width; i++)
				for (int j = offsetY; j <= offsetY + height; j++) {
					Game::m.lock();
					goToXY(i, j);
					cout << " ";
					Game::m.unlock();
				}
			break; 
		}
	}
}
void GameControl::drawPauseGamePopup()
{
	int width = 65;
	int height = 13;
	int offsetX = 15;
	int offsetY = 10;
	drawRectangle(offsetX, offsetY, width, height, colorYellow);
	/*tring pauseGame = "Pause game";
	goToXY(offsetX + width / 2 - pauseGame.size() / 2, offsetY + 2);
	cout << pauseGame;*/
	cout << R"(
		    _____                        _____                      
		   |  __ \                      / ____|                     
		   | |__) |_ _ _   _ ___  ___  | |  __  __ _ _ __ ___   ___ 
		   |  ___/ _` | | | / __|/ _ \ | | |_ |/ _` | '_ ` _ \ / _ \
		   | |  | (_| | |_| \__ \  __/ | |__| | (_| | | | | | |  __/
		   |_|   \__,_|\__,_|___/\___|  \_____|\__,_|_| |_| |_|\___|)" << endl; 

	map<int, string> contents = {
		{1, "Continue"},
		{2, "Back to menu"},
	};

	for (auto& content : contents) {
		TextColor(colorShit);
		goToXY(offsetX + 20, offsetY + content.first + 7);
		cout << content.second;
	}
	int active = 0; 
	while (1) {
		char c = _getch(); 
		if (c == KEY_ESC) {
			for (int i = offsetX; i <= offsetX + width; i++)
				for (int j = offsetY; j <= offsetY + height; j++) {
					Game::m.lock();
					goToXY(i, j);
					cout << " ";
					Game::m.unlock();
				}
			break; 
		}

		if (c == KEY_DOWN) {
			active++;
			if (active > contents.size()) {
				active = 1;
			}
			auto it = contents.find(int(active));
			if (it != contents.end()) {
				goToXY(offsetX + 20, offsetY + it->first + 7);
				TextColor(3);
				cout << it->second;
				TextColor(colorDefault);
				for (auto p = contents.begin(); p != contents.end(); p++) {
					if (p != it) {
						goToXY(offsetX + 20, offsetY + p->first + 7);
						cout << p->second;
					}
				}
			}
		}

		if (c == KEY_UP) {
			active--;
			if (active < 1) {
				active = contents.size();
			}
			auto it = contents.find(active);
			if (it != contents.end()) {
				goToXY(offsetX + 20, offsetY + it->first + 7);
				TextColor(activeColor);
				cout << it->second;
				TextColor(colorDefault);
				for (auto p = contents.begin(); p != contents.end(); p++) {
					if (p != it) {
						goToXY(offsetX + 20, offsetY + p->first + 7);
						cout << p->second;
					}
				}
			}
		}
	}
}
void GameControl::startGame() {
	system("cls");
	TextColor(colorDefault);
	drawBorder();
	//Game::startGame();
}
void GameControl::drawInfoMenu() {
	int offsetX = 130;
	int offsetY = 14;
	int offsetY2 = 19;
	map<int, string> scores = {
		{1, "Score"},
		{2, "Highscore"}
	};
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
	TextColor(colorGreen);
	goToXY(offsetX, offsetY);
	string movingKeyboards = "Moving keyboards";
	cout << movingKeyboards;
	for (int i = 1; i <= 4; i++) {
		goToXY(offsetX, offsetY + i);
		TextColor(colorBoldBlue);
		cout << keyboards[i];
	}
	TextColor(colorGreen);
	goToXY(offsetX, offsetY2);
	cout << "Command keyboards: ";
	for (int i = 1; i <= 4; i++) {
		goToXY(offsetX, offsetY2 + i);
		TextColor(colorBoldBlue);
		cout << commands[i];
	}
	Game::m.unlock();

	while (1) {
		char c = toupper(_getch());

		if (c == 'S') {
			drawSaveGamePopup(); 
		}
		if (c == 'L') {
			drawLoadGamePopup(); 
		}
		if (c == 'P') {
			drawPauseGamePopup(); 
		}
		if (c == 'C') {
			drawContinuePopup(); 
		}
	}

}
void GameControl::drawScore()
{
	int offsetX = 130;
	int offsetY = 8;
	TextColor(colorShit);
	goToXY(offsetX, offsetY);

	
	cout << "Score: " << 1;
}
void GameControl::drawLogoTeam()
{
	TextColor(colorCyan);
	
	goToXY(100, 0); 
		cout << R"(
													    		     ______                        _____
													    		    /_  __/__  ____ _____ ___     / ___/
													    		     / / / _ \/ __ `/ __ `__ \   / __ \ 
													    		    / / /  __/ /_/ / / / / / /  / /_/ / 
													    		   /_/  \___/\__,_/_/ /_/ /_/   \____/  

)" << endl;
		char b = char(219);
		for (int i = 0; i < 5; i++) {
			goToXY(120, i + 1);
			cout << b;
		}
}
void GameControl::drawFruitRequired(){
	goToXY(130, 9); 
	cout << "Fruit requried: " << 2; 
}
void GameControl::saveGame() {}; 
void GameControl::drawLogoCrossingGame()
{
	goToXY(50, 10);
	TextColor(colorBoldBlue);
	cout << R"(	
			 _____                    _               _____                 _    _____                       
			/ ____|                  (_)             |  __ \               | |  / ____|                      
			| |     _ __ ___  ___ ___ _ _ __   __ _  | |__) |___   __ _  __| | | |  __  __ _ _ __ ___   ___  
			| |    | '__/ _ \/ __/ __| | '_ \ / _` | |  _  // _ \ / _` |/ _` | | | |_ |/ _` | '_ ` _ \ / _ \ 
			| |____| | | (_) \__ \__ \ | | | | (_| | | | \ \ (_) | (_| | (_| | | |__| | (_| | | | | | |  __/ 
			\_____ |_|  \___/|___/___/_|_||_|\__,  | |_|  \_\___/ \__,_|\__,_|  \_____|\__,_|_| |_| |_|\___| 
			                                   __/ |                                                         
			                                  |___/ )" << endl;

}
