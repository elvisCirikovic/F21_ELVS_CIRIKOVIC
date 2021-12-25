#pragma once

#include "MirageUtils.h"
#include "GameWindow.h"
#include "Sprite.h"

#define FRAMES_PER_SECOND 30

namespace Mirage
{
	class MIRAGE_API MirageApp
	{
	public:
		void Run();
		virtual void OnUpdate();
		virtual void OnKeyPressed(KeyPressedEvent &event);
		int GetGameWindowWidth() const;
		int GetGameWindowHeight() const;

	protected:
		MirageApp();

	private:
		GameWindow mGameWindow;

		std::chrono::steady_clock::time_point mTimeOfNextFrame;
		std::chrono::milliseconds mFrameDuration{ 1000/FRAMES_PER_SECOND };

	};
}
