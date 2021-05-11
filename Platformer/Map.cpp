#include "Map.h"

#include <random>

CMap::CMap(const std::wstring& fileName, const int& playerWidth, const int& playerHeight)
	: mPlayer(playerWidth, playerHeight)
{
	
}

void CMap::Draw(sf::RenderWindow& window)
{
	mPlayer.Draw(window);

	for (auto& i : mPlatforms)
	{
		i->Draw(window);
	}
}

void CMap::SetPlayerPosition(const sf::Vector2f& pos)
{
	mPlayer.SetPosition(pos);
}

void CMap::Update(float dt)
{
	mPlayer.Update(dt);

	if (mCurrent == nullptr)
	{
		if (mPlayer.GetVelocityY() >= 0)
		{
			for (auto& i : mPlatforms)
			{
				if (mPlayer.IntersectingPlatform(*i))
				{
					mPlayer.OverrideVelocity(sf::Vector2f(0.0f, 0.0f));
					mCurrent = i.get();
				}
			}
		}
	}
	else
	{
		if (!mPlayer.IntersectingPlatform(*mCurrent))
		{
			mCurrent = nullptr;
			mPlayer.SetFalling(true);
		}
	}
}

void CMap::AddRandomPlatforms(const int& number)
{
	int lastX = 0;
	int lastY = 0;

	for (int i = 0; i < number; i++)
	{
		int randX, randY;

		do
		{
			randX = (rand() % 380);
		} while (std::abs(randX - lastX) < 50);

		lastX = randX;
		
		do
		{
			randY = (rand() % 150) + 30;
		} while (std::abs(randY - lastY) < 140);

 		if (mPlatforms.size() == 0)
		{
			mPlatforms.push_back(std::make_shared<CPlatform>(sf::Vector2f(randX, 480 - randY)));
		}
		else
		{
			mPlatforms.push_back(std::make_shared<CPlatform>(sf::Vector2f(0.0 + randX, mPlatforms.back()->GetPosition().y - randY / 2)));	
		}
	}
}
