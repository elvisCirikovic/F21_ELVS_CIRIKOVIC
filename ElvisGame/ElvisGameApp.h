#pragma once

#include "Mirage.h"
#include "Unit.h"
#include <vector>

class ElvisGameApp : public Mirage::MirageApp
{
public:
	ElvisGameApp();
	virtual void OnUpdate() override;
	virtual void OnKeyPressed(Mirage::KeyPressedEvent& event) override;



private:
	Unit mHero;
	std::vector<Unit> mEnemies;
	int mFrameCounter;
	Mirage::Shader mShader;
	std::vector<Unit> mNewEnemies;
};