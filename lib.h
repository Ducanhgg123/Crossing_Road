#pragma once
#pragma once
#include <iostream>
#include <vector>
#include <deque>
#include <algorithm>
#include <thread>
#include <conio.h>
#include <windows.h>
#include <mutex>
#include <map>
#include <fstream>
#include <string>
#include <filesystem>
using namespace std;
namespace fs = std::filesystem;
const int colorRed = 244;
const int colorShit = 246;
const int colorCyan = 249;
const int colorYellow = 252;
const int colorBoldBlue = 241;
const int colorBlue = 243;
const int colorGreen = 250;
const int colorDeepGreen = 242;
const int colorDefault = 240;
const int distanceBetweenLine = 7;
const int activeColor = 15;
const int gateLength = 10;
const int gateWidth = 6;
#define KEY_ESC 27
#define KEY_DOWN 80
#define KEY_UP 72
#define KEY_LEFT 75
#define KEY_RIGHT 77
#define KEY_ESC 27
#define KEY_ENTER 13

#define DOWN_BLACK_PIECE char(220)
#define UP_BLACK_PIECE char(223)
#define VERTICAL_BLACK_PIECE char(219)
#define BLOCK char(254)