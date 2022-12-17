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
void GameControl::undrawRectangle(int offset_X, int offset_Y, int width, int height) {
	// Delete everything in the table
	for (int i = offset_X; i < offset_X + width+1; i++)
		for (int j = offset_Y; j < offset_Y + height+1; j++) {
			Game::m.lock();
			goToXY(i, j);
			cout << " ";
			Game::m.unlock();
		}
}
//void GameControl::drawMenu() {
//	int active = 1;
//	playMenuMusic();
//	map<int, string>  menus = {
//		{1, "New game"},
//		{2, "Load game"},
//		{3, "Settings"},
//		{4, "Leaderboard"},
//		{5, "Exit"}
//	};
//	Game::m.lock();
//	goToXY(25, 5);
//	TextColor(colorDefault);
//	Game::m.unlock();
//	while (true) {
//		for (auto& menu : menus) {
//			if (active == menu.first) {
//				Game::m.lock();
//				TextColor(activeColor);
//				goToXY(25, 5 + menu.first);
//				cout << menu.second;
//				TextColor(colorDefault);
//				Game::m.unlock();
//				continue;
//			}
//			Game::m.lock();
//			TextColor(colorDefault);
//			goToXY(25, 5 + menu.first);
//			cout << menu.second;
//			Game::m.unlock();
//		}
//		char c = _getch();
//		if (c == KEY_UP || c == 'w') {
//			active--;
//			if (active < 1) {
//				active = 4;
//			}
//		}
//		if (c == KEY_DOWN || c == 's') {
//			active++;
//			if (active > 4)
//				active = 1;
//		}
//		if (c == KEY_ENTER) {
//			
//			break;
//		}
//	}
//	if (active == 1) {
//		/*Game::m.lock();
//		system("cls");
//		TextColor(colorDefault);
//		Game::m.unlock();*/
//		startGame();
//	}
//	if (active == 2) {
//		loadGame();
//	}
//	if (active == 3) {
//		/*Game::m.lock();
//		system("cls");
//		goToXY(40, 40);
//		TextColor(colorDefault);
//		Game::m.unlock();*/
//		settingGame();
//
//		
//	}
//	if (active == 4) {
//		/*Game::m.lock();
//		system("cls");
//
//		Game::m.unlock();*/
//		drawLeaderboard();
//		
//	}
//	if (active == 5) {
//		exit(1);
//	}
//}
void GameControl::drawMenu() {
	drawLogoCrossingGame();
	int active = 1;
	bool isLoading = true;
	map<int, string>  menus = {
		{1, "New game"},
		{2, "Load Game"},
		{3, "Two players mode"},
		{4, "Music"},
		{5, "Leaderboard"},
		{6, "Exit"}
	};
<<<<<<< HEAD

	TextColor(colorCyan);
	int offsetX = 60;
	int offsetY = 20;
	for (auto& menu : menus) {
		goToXY(offsetX, offsetY + menu.first);
		cout << menu.second;
=======
	
	goToXY(25, 5);
	TextColor(colorDefault);

	for (auto& menu : menus) {
		
		goToXY(25, 5 + menu.first);
		cout << menu.second;
		
>>>>>>> a7dc7579fe252822b262d27f2ae73f661b20a978
	}
	while (isLoading) {
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
		char c = _getch();
		if (c == KEY_UP || c == 'w') {
			active--;
			if (active < 1) {
				active = 6;
			}
		}
		if (c == KEY_DOWN || c == 's') {
			active++;
			if (active > 6)
				active = 1;
		}
		if (c == KEY_ENTER) {
			if (active == 1) {
				isLoading = true;
<<<<<<< HEAD
				system("cls");
=======
			
				system("cls");
				TextColor(colorDefault);
				/*Game::gotoOxy(40, 40);*/
				/*Game::txtColor(DEFAULT_COLOR);*/
			
>>>>>>> a7dc7579fe252822b262d27f2ae73f661b20a978
				startGame();
				break;
			}
			if (active == 2) {
				system("cls");
				drawLoadGamePopup();
				break;
			}
			if (active == 3) {
				isLoading = true;
<<<<<<< HEAD

=======
				
>>>>>>> a7dc7579fe252822b262d27f2ae73f661b20a978
				system("cls");
				goToXY(40, 40);
				TextColor(colorDefault);
				settingGame();
<<<<<<< HEAD
				break;
			}
			if (active == 4) {

				system("cls");
				drawLeaderboard();

=======
				
				break;
			}
			if (active == 3) {
				
				system("cls");
				drawLeaderboard();
				
>>>>>>> a7dc7579fe252822b262d27f2ae73f661b20a978
			}
			if (active == 5) {
				system("cls");
				exit(1);
			}
			break;
		}
<<<<<<< HEAD
		
=======
		for (auto& menu : menus) {
			if (active == menu.first) {
				
				TextColor(activeColor);
				goToXY(25, 5 + menu.first);
				cout << menu.second;
				TextColor(colorDefault);
				
				continue;
			}
			
			TextColor(colorDefault);
			goToXY(25, 5 + menu.first);
			cout << menu.second;
			
		}
>>>>>>> a7dc7579fe252822b262d27f2ae73f661b20a978
	}
}
void GameControl::drawBorder() {
	int width = 120;
	int height = 34;
	int offsetX = 0;
	int offsetY = 0;

	drawRectangle(offsetX, offsetY, width, height, colorCyan);

	drawLogoTeam();
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
	Game::m.lock();
	goToXY(offsetX + 8, offsetY + 1);
	cout << R"(
		   _____                                             _ 
		  / ____|                                           | |
		  | |  __  __ _ _ __ ___   ___    _____   _____ _ __| |
		  | | |_ |/ _` | '_ ` _ \ / _ \  / _ \ \ / / _ \ '__| |
		  | |__| | (_| | | | | | |  __/ | (_) \ V /  __/ |  |_|
		   \_____|\__,_|_| |_| |_|\___|  \___/ \_/ \___|_|  (_)
)" << endl;
	Game::m.unlock();
	map<int, string> contents = {
		{1, "Press ESC to return to menu"}
	};

	for (auto& el : contents) {
		Game::m.lock();
		goToXY(offsetX + 15, offsetY + el.first + 9);
		cout << el.second;
		Game::m.unlock();
	}
	char c = _getch();
	if (c == KEY_ESC) {
		system("cls");
		drawMenu();
	}
	/*if (c == 'R' || c=='r') {
		undrawRectangle(offsetX - 1, offsetY - 1, width + 2, height + 2);
		startGame();
	}*/
}
void GameControl::settingGame(){

}
void GameControl::startGame() {
	system("cls");
	Game::restartGame();
	playBackgroundMusic();
	TextColor(colorDefault);
	drawBorder();
	Game::startGame();
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
		{1,"P. Pause Game"},
		{2, "J: Save Game"},
		{3, "L: Load Game"},
		{4,"ESC. Back to Menu"}
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
}
<<<<<<< HEAD
void GameControl::saveGame() 
{

}
void GameControl::drawScore() 
{
	Game::m.lock();
	goToXY(105, 5);
	cout << "Your score : " << Game::score;
	Game::m.unlock();
}
void GameControl::drawFruitRequired()
{
	Game::m.lock();
	goToXY(110, 3);
	cout << "Fruit required : " << Game::fruitRequired;
	Game::m.unlock();
}
void GameControl::drawGate() 
{
	//int gateLength = 8; //pixels
	//int gateWidth = 5;//pixels
	//int startPointGate = ((Game::endLine - Game::startLine + 1) / 2 - (gateLength / 2)) + Game::startLine;
	//char gatePointHorizontalChar = 'X';
	//char gatePointVerticalLeftChar = 'X';
	//char gatePointVerticalRightChar = 'X';

	//for (int i = 0; i < gateLength; i++)
	//{
	//	Game::m.lock();
	//	goToXY(startPointGate + i, 0);
	//	cout << gatePointHorizontalChar;
	//	goToXY(startPointGate + i, 1);
	//	cout << gatePointHorizontalChar;
	//	Game::m.unlock();
	//}
	//for (int i = 0; i < gateWidth; i++)
	//{
	//	Game::m.lock();
	//	goToXY(startPointGate, i);
	//	cout << gatePointVerticalLeftChar;
	//	Game::m.unlock();
	//}
	//for (int i = 0; i < gateWidth; i++)
	//{
	//	Game::m.lock();
	//	goToXY(startPointGate + gateLength -1, i);
	//	cout << gatePointVerticalRightChar;
	//	Game::m.unlock();
	//}

	for (int i = 0; i < Game::gate.size(); i++)
	{
		Game::m.lock();
		goToXY(Game::gate[i].getX(), Game::gate[i].getY());
		cout << Game::gate[i].getC();
		Game::m.unlock();
	}
=======
void GameControl::saveGame() {
	Game::isPaused = true;
	int width = 40;
	int height = 7;
	int offsetX = 38;
	int offsetY = 10;
	drawRectangle(offsetX, offsetY, width, height, colorYellow);
	Game::m.lock();
	goToXY(offsetX + 2, offsetY + 3);
	string userName;
	string dir = "Save_Game/";
	cout << "Enter your name: "; 
	getline(cin, userName);
	Game::m.unlock();
	Game::isPaused=0;
	undrawRectangle(offsetX, offsetY, width, height);
	Game::fruit.draw();
	/*cout << R"(
	   _____                    _____
	  / ____|                  / ____|
	 | (___   __ ___   _____  | |  __  __ _ _ __ ___   ___
	  \___ \ / _` \ \ / / _ \ | | |_ |/ _` | '_ ` _ \ / _ \
	  ____) | (_| |\ V /  __/ | |__| | (_| | | | | | |  __/
	 |_____/ \__,_| \_/ \___|  \_____|\__,_|_| |_| |_|\___|
)" << endl;*/
	fstream f;
	f.open(dir + userName + ".txt", ios::out);
	Game::saveToFile(f);
	f.close();
	
}
void GameControl::pauseGame() {
	Game::isPaused = true;
	drawPauseGamePopup();
}
void GameControl::drawPauseGamePopup()
{
	int width = 65;
	int height = 13;
	int offsetX = 15;
	int offsetY = 10;
	drawRectangle(offsetX, offsetY, width, height, colorYellow);
	Game::m.lock();
	cout << R"(
		    _____                        _____                      
		   |  __ \                      / ____|                     
		   | |__) |_ _ _   _ ___  ___  | |  __  __ _ _ __ ___   ___ 
		   |  ___/ _` | | | / __|/ _ \ | | |_ |/ _` | '_ ` _ \ / _ \
		   | |  | (_| | |_| \__ \  __/ | |__| | (_| | | | | | |  __/
		   |_|   \__,_|\__,_|___/\___|  \_____|\__,_|_| |_| |_|\___|)" << endl;
	Game::m.unlock();
	map<int, string> contents = {
		{1, "C: Continue"},
		{2, "ESC: Back to menu"},
	};
	
	for (auto& content : contents) {
		Game::m.lock();
		TextColor(colorShit);
		goToXY(offsetX + 20, offsetY + content.first + 7);
		cout << content.second;
		Game::m.unlock();
	}
	
	int active = 0;
	while (1) {
		char c = _getch();
		if (c == 'C' || c=='c') {
			for (int i = offsetX; i <= offsetX + width; i++)
				for (int j = offsetY; j <= offsetY + height; j++) {
					Game::m.lock();
					goToXY(i, j);
					cout << " ";
					Game::m.unlock();
				}
			Game::isPaused = false;
			Game::fruit.draw();
			break;
		}
		if (c == KEY_ESC) {
			Game::isRunning = false;
			system("cls");
			drawMenu();
		}
		Game::m.lock();
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
		Game::m.unlock();
	}
	Game::m.lock();
	TextColor(colorDefault);
	Game::m.unlock();
}
void GameControl::resumeGame() {
	Game::isPaused = false;
}
void GameControl::loadGame(string filename) {
	fstream f;
	f.open(filename);
	Game::restartGame();
	Game::loadGame(f);
	f.close();
	system("cls");
	drawBorder();
	drawInfoMenu();
	Game::startGame();
}
void GameControl::drawScore() {
	Game::m.lock();
	int offsetX = 130;
	int offsetY = 8;
	TextColor(colorShit);
	goToXY(offsetX, offsetY);
	cout << "Score: ";
	TextColor(colorRed);
	cout << Game::score;
	TextColor(colorDefault);
	Game::m.unlock();
}
void GameControl::drawFruitRequired() {
	Game::m.lock();
	TextColor(colorShit);
	goToXY(130, 9);
	cout << "Fruit requried: ";
	TextColor(colorRed);
	cout << Game::fruitRequired;
	TextColor(colorDefault);
	Game::m.unlock();
}
void GameControl::drawGate() {
	drawRectangle(50, 1, 10, 5, colorGreen);
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
}
void GameControl::levelUp() {
	int level = Game::level;
	int score = Game::score;
	Game::restartGame();
	Game::fruitForThisLevel += 2;
	Game::fruitRequired = Game::fruitForThisLevel;
<<<<<<< HEAD
	Game::level = level+1;
	Game::score = score;
=======
	Game::level = level + 1;
	Game::score = score;
}
void GameControl::turnOnMusic() {
	Game::musicOn = true;
}
void GameControl::turnOffMusic() {
	Game::musicOn = false;
}
void ThreadBackgroundMusic() {
	PlaySound(TEXT("pvz-theme.wav"), NULL, SND_ASYNC);
	Sleep(198000);
}
void GameControl::playBackgroundMusic() {
	if (Game::musicOn) {
		thread t(ThreadBackgroundMusic);
		t.detach();
	}
}
void ThreadMenuMusic() {
	PlaySound(TEXT("pvz-main-theme.wav"), NULL, SND_ASYNC);
	Sleep(1000*(60+27));
}
void GameControl::playMenuMusic() {
	if (Game::musicOn) {
		thread t(ThreadMenuMusic);
		t.detach();
	}
}
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
void GameControl::drawLoadGamePopup()
{
	Game::isRunning = false;
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
	map<int, string> players;
	std::string path = "Save_Game/";
	int count = 0;
	for (const auto& entry : fs::directory_iterator(path)) {
		string s = entry.path().filename().string();
		players.emplace( ++count,s.substr(0,s.size()-4 ));
	}
	for (auto& player : players) {
		TextColor(colorDefault);
		goToXY(offsetX + 23, offsetY + player.first + 7);
		cout << player.second;
	}
	char c;
	while (1) {
		c = _getch();
		/*auto it = players.find(int(c) - '0');
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
		}*/

		if (c == KEY_DOWN || c=='s') {
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

		if (c == KEY_UP || c=='w') {
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
			for (int i = offsetX; i <= offsetX + width; i++)
				for (int j = offsetY; j <= offsetY + height; j++) {
					Game::m.lock();
					goToXY(i, j);
					cout << " ";
					Game::m.unlock();
				}
			drawMenu();
			break;
			
		}
		if (c == KEY_ENTER) {
			break;
		}
	}
	if (c == KEY_ENTER) {
		auto it = players.find(int(active));
		loadGame(path + it->second + ".txt");
	}
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
void GameControl::drawLevel() {
	Game::m.lock();
	int offsetX = 130;
	int offsetY = 10;
	TextColor(colorShit);
	goToXY(offsetX, offsetY);
	cout << "Level: ";
	TextColor(colorRed);
	cout << Game::level;
	TextColor(colorDefault);
	Game::m.unlock();
>>>>>>> 2f71eac0c59b756bf0d314b0a20abf05f975a29c
}