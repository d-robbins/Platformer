#include <iostream>
#include <string>
#include <random>
#include <ctime>

#include "Player.h"
#include "Map.h"
#include "Platform.h"

#include <SFML/Graphics.hpp>

const unsigned int WINDOW_WIDTH = 640;
const unsigned int WINDOW_HEIGHT = 480;
const float PLAYER_WIDTH = 50.0f;
const float PLAYER_HEIGHT = 50.0f;

const std::wstring WINDOW_NAME = L"Platformer";

int main()
{ 
	sf::Clock clock;

	srand((unsigned)time(0));

	sf::RenderWindow window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT), WINDOW_NAME);
	window.setFramerateLimit(60);

	sf::View view(sf::FloatRect(0, 0, 640, 480));
	window.setView(view);

	CMap map(L"", PLAYER_WIDTH, PLAYER_HEIGHT);

	sf::RectangleShape ground(sf::Vector2f(640, 240));
	sf::Texture groundTex;
	groundTex.loadFromFile("images/ground.png");
	ground.setTexture(&groundTex);

	ground.setPosition(sf::Vector2f(0, 480));

	bool attached = false;

	map.AddRandomPlatforms(10);

	float lastPlayerPos = 0;

	float dt;

	while (window.isOpen())
	{
		dt = clock.restart().asSeconds();

		sf::Event e;
		while(window.pollEvent(e))
		{
			if (e.type == sf::Event::Closed) { window.close(); }

			if (e.type == sf::Event::MouseButtonPressed)
			{
				
			}
		}
		
		if (map.GetPlayerPos().y < lastPlayerPos)
		{
			map.AddRandomPlatforms(10);
			lastPlayerPos -= 480;
		}

		map.Update(dt);	
	
		window.clear(sf::Color(53, 153, 204, 50));
		view.setCenter(sf::Vector2f(WINDOW_WIDTH / 2, map.GetPlayerPos().y));
		window.setView(view);
	
		map.Draw(window);		

		window.draw(ground);

		window.display();		
	}

	return 0;
}