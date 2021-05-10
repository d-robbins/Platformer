#pragma once

#include <SFML/Graphics.hpp>

class CPlatform
{
public:
	CPlatform(const sf::Vector2f& pos);
	~CPlatform() {}

	void Draw(sf::RenderWindow& window) { window.draw(mShape); }

	bool HitTest(const int& x, const int& y);
	void SetPosition(const int& x, const int& y) { mShape.setPosition(sf::Vector2f((float)x, (float)y)); }

	sf::FloatRect GetBounds() const { return mShape.getGlobalBounds(); }
	sf::Vector2f GetPosition() const { return mShape.getPosition(); }
private:
	sf::RectangleShape mShape;
	bool mClickable = false;
};

