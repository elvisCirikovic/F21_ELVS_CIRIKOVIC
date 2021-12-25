#include "ElvisGameApp.h"
#include "Mirage.h"



ElvisGameApp::ElvisGameApp() : mHero("Assets/Textures/Hero.png", 0, 0, 10), mFrameCounter(0)
{
	mShader.Load("Assets/Shader/myVertexShader.glsl", "Assets/Shader/myFragmentShader.glsl");
	mShader.SetVec2IntUniform("screenSize", 800, 800);

}

void ElvisGameApp::OnUpdate()
{
	mHero.UpdatePosition();
	//update existing enemies
	for (auto& enemy : mEnemies)
	{
		enemy.UpdatePosition();
	}
	for (auto& newEnemy : mNewEnemies)
	{
		newEnemy.UpdatePosition();
	}
	//introduce new enemies every second
	if (mFrameCounter % FRAMES_PER_SECOND == 0 && mEnemies.size()<10 && mNewEnemies.size()<5)
	{

		int newX = { rand() % 700 };
		int newY = { rand() % 700 };
		Unit::Direction newDir;
		int dirVal{ rand() % 4 };
		if (dirVal == 0)
		{
			newDir = Unit::Direction::Down;
		}
		else if (dirVal == 1)
		{
			newDir = Unit::Direction::Up;
		}
		else if (dirVal == 2)
		{
			newDir = Unit::Direction::Left;
		}
		else
		{
			newDir = Unit::Direction::Right;
		}
		int enemyGenerator = { rand() % 3 };
		if (enemyGenerator != 1)
		{
			mEnemies.push_back(Unit{ "Assets/Textures/BadGuy.png", newX, newY, 10 });
			mEnemies.back().SetDirection(newDir);
		}
		else
		{
			mNewEnemies.push_back(Unit{ "Assets/Textures/DontTouch.png",newX,newY,2 });
			mNewEnemies.back().SetDirection(newDir);
		}

	}

	//check for collisions
	auto it = mEnemies.begin();
	while(it!=mEnemies.end())
	{
		if (mHero.CollideWith(*it))
		{
			it = mEnemies.erase(it);

		}
		else
		{
			it++;
		}
	}
	for (auto& enemy : mEnemies)
	{
		enemy.Draw(mShader);
	}
	auto temp = mNewEnemies.begin();
	while (temp != mNewEnemies.end())
	{
		if (mHero.CollideWith(*temp))
		{
			int temp2 = mHero.GetSpeed();
			mHero.SetSpeed(mHero.GetSpeed()-1);
			temp = mNewEnemies.erase(temp);
		}
		else
		{
			temp++;
		}


	}
	for (auto& newEnemy : mNewEnemies)
	{
		newEnemy.Draw(mShader);
	}
	mHero.Draw(mShader);

	mFrameCounter++;
}

void ElvisGameApp::OnKeyPressed(Mirage::KeyPressedEvent& event)
{
	switch (event.GetKeyCode())
	{
	case MIRAGE_KEY_LEFT:
		//mHero.SetPosX(mHero.GetPosX() - mHero.GetSpeed());
		mHero.SetDirection(Unit::Direction::Left);
		break;
	case MIRAGE_KEY_RIGHT:
		//mHero.SetPosX(mHero.GetPosX() + mHero.GetSpeed());
		mHero.SetDirection(Unit::Direction::Right);
		break;
	case MIRAGE_KEY_DOWN:
		//mHero.SetPosY(mHero.GetPosY() - mHero.GetSpeed());
		mHero.SetDirection(Unit::Direction::Down);
		break;
	case MIRAGE_KEY_UP:
		//mHero.SetPosY(mHero.GetPosY() + mHero.GetSpeed());
		mHero.SetDirection(Unit::Direction::Up);
		break;
	}
}
