#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <string>
#include <random>
#include <ctime>


#include "player.h"
#include "map.h"
#include "platform.h"

class CGame
{
public:
	CGame(const unsigned int& width, const unsigned& height, const std::wstring& name);
	CGame() = delete;
	~CGame() {}

	void Start() { GameLoop(); }
private:
	void GameLoop();
	void Draw();
	void Update();

	sf::Vector2f mWindowSize;
	sf::Texture mGroundTexture;
	sf::RectangleShape mGround;
	sf::Clock mClock;
	CMap mMap;

	sf::Text mPlayerLevelText;
	sf::Font mGameFont;

	float mLastPlayerPosition = 0.f;
	float mDelta = 0.f;

	sf::View mWindowView;
	sf::RenderWindow mWindow;
};

