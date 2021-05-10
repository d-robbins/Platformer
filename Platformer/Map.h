#pragma once

#include <SFML/Graphics.hpp>
#include <memory>
#include <vector>

#include "Platform.h"

#include "Player.h"

class CMap
{
public:
	CMap(const std::wstring& fileName, const int& playerWidth, const int& playerHeight);
	CMap() = delete;
	~CMap() {}

	sf::Vector2f GetPlayerPos() const { return mPlayer.GetPosition(); }

	void Draw(sf::RenderWindow& window);

	void SetPlayerPosition(const sf::Vector2f& pos);

	void Update(float dt);

	//void AddPlatform(CPlatform& platform) { mPlatforms.push_back(&platform); }

	void AddRandomPlatforms(const int& number, const int& level);

private:
	CPlayer mPlayer;
	CPlatform* mCurrent = nullptr; 
	std::vector<std::shared_ptr<CPlatform>> mPlatforms;
};


//f8kzF5kz
