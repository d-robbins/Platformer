#include "platform.h"

CPlatform::CPlatform(const sf::Vector2f& pos)
	: mShape(sf::Vector2f(100.0f, 15.0f))
{
	mClickable = true;
	mShape.setFillColor(sf::Color::Black);
	mShape.setPosition(pos);
}

bool CPlatform::HitTest(const int& x, const int& y)
{
	return mShape.getGlobalBounds().contains(sf::Vector2f((float)x, (float)y));
}
