#include "game.h"

const float PLAYER_WIDTH = 50.0f;
const float PLAYER_HEIGHT = 50.0f;

CGame::CGame(const unsigned int& width, const unsigned& height, const std::wstring& name)
	: mWindow(sf::VideoMode(width, height), name), 
	  mMap(L"", PLAYER_WIDTH, PLAYER_HEIGHT), 
	  mWindowSize(width, height),
	  mWindowView(sf::FloatRect(0, 0, width, height))
{
	mWindow.setFramerateLimit(60);
	mWindow.setVerticalSyncEnabled(true);

	mGroundTexture.loadFromFile("images/ground.png");
	mGround.setTexture(&mGroundTexture);

	mGround.setSize(sf::Vector2f(640, 240));
	mGround.setPosition(sf::Vector2f(0, 480));

	mMap.AddRandomPlatforms(10);

	mGameFont.loadFromFile("fonts/arial.ttf");
	mPlayerLevelText.setFont(mGameFont);
	mPlayerLevelText.setCharacterSize(24);
	mPlayerLevelText.setFillColor(sf::Color::Black);
}

void CGame::GameLoop()
{
	while (mWindow.isOpen())
	{
		mDelta = mClock.restart().asSeconds();

		sf::Event e;
		while (mWindow.pollEvent(e))
		{
			if (e.type == sf::Event::Closed) { mWindow.close(); }

			if (e.type == sf::Event::MouseButtonPressed)
			{

			}
		}

		if (mMap.GetPlayerPos().y < mLastPlayerPosition)
		{
			mMap.AddRandomPlatforms(10);
			mLastPlayerPosition -= 480;
		}

		Update();
		Draw();

		mWindow.display();
	}
}

void CGame::Draw()
{
	mWindow.clear(sf::Color(53, 153, 204, 50));
	mWindowView.setCenter(sf::Vector2f(mWindowSize.x / 2, mMap.GetPlayerPos().y));
	mWindow.setView(mWindowView);

	mMap.Draw(mWindow);

	mWindow.draw(mGround);

	mPlayerLevelText.setString(std::to_string((int)(mMap.GetPlayerPos().y + PLAYER_HEIGHT)));
	mPlayerLevelText.setPosition(sf::Vector2f(500, mMap.GetPlayerPos().y));
	mWindow.draw(mPlayerLevelText);
}

void CGame::Update()
{
	mMap.Update(mDelta);
}
