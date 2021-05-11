#include <iostream>
#include <string>
#include <random>
#include <ctime>

#include "game.h"

#include <SFML/Graphics.hpp>

const unsigned int WINDOW_WIDTH = 640;
const unsigned int WINDOW_HEIGHT = 480;
const std::wstring WINDOW_NAME = L"Platformer";

int main()
{ 
	srand((unsigned)time(0));

	CGame game(WINDOW_WIDTH, WINDOW_HEIGHT, WINDOW_NAME);
	game.Start();

	return 0;
}