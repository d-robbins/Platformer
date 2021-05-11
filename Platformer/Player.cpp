#include "Player.h"

#include "Map.h"

//#include "Platform.h"

const float SPEED = 200.f;
const float GRAVITY = 12.81f;
const float JUMP_FORCE = 400.0f;

CPlayer::CPlayer(const float& width, const float& height)
	: mVelocity(0, 0)
{
	mPlayer.setSize(sf::Vector2f(width, height));
	mPlayer.setFillColor(sf::Color::Black);
	mPlayer.setOrigin(width / 2, height / 2);
	mPlayer.setPosition(320, 480 - (height / 2));
}

void CPlayer::Draw(sf::RenderWindow& window)
{
	window.draw(mPlayer);
}

void CPlayer::Update(float dt)
{
	mVelocity.x = 0.0f;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		mVelocity.x -= SPEED * dt;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		mVelocity.x += SPEED * dt;
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space) && !mJump)
	{
		mJump = true;

		mVelocity.y -= JUMP_FORCE / 45;
	}

	if (mJump)
	{
		mVelocity.y += GRAVITY * dt;

		if (mPlayer.getPosition().y > 480 - (mPlayer.getGlobalBounds().height / 2))
		{
 			mPlayer.setPosition(mPlayer.getPosition().x, 480 - (mPlayer.getGlobalBounds().height / 2));
			mVelocity.y = 0;
			mJump = false;
		}
	}

	mPlayer.move(mVelocity);
}

void CPlayer::OverrideVelocity(const sf::Vector2f& nV)
{
	mVelocity = nV;
	mJump = false;
}

bool CPlayer::IntersectingPlatform(const CPlatform& plat)
{
	sf::FloatRect platRect, playRect;

	platRect = sf::FloatRect(plat.GetBounds().left, plat.GetBounds().top, plat.GetBounds().width, 5);
	playRect = sf::FloatRect(mPlayer.getGlobalBounds().left, mPlayer.getGlobalBounds().top + 40, mPlayer.getGlobalBounds().width, 10);

	return playRect.intersects(platRect);
}