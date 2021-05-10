#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>

class CMap;
class CPlatform;
class CPlayer
{
public:
	CPlayer(const float& width, const float& height);
	CPlayer() = delete;
	~CPlayer() {}

	sf::Vector2f GetPosition() const { return mPlayer.getPosition(); }

	void Draw(sf::RenderWindow& window);

	void Update(float dt);

	void SetPosition(const sf::Vector2f& pos) { mPlayer.setPosition(pos); }

	void SetMap(CMap* map) { if (map != nullptr) mMap = map; }

	void OverrideVelocity(const sf::Vector2f& nV);
	
	bool IntersectingPlatform(const CPlatform& plat);

	float GetVelocityY() { return mVelocity.y; }
	
	void SetFalling(bool val) { mJump = val; }

	sf::FloatRect GetBounds() const { return mPlayer.getGlobalBounds(); }

private:
	CMap* mMap = nullptr;
	sf::RectangleShape mPlayer;
	sf::Vector2f mVelocity;

	bool mJump = false;
};

