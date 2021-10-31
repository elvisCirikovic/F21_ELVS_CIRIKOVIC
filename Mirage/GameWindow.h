#pragma once

#include "MirageUtils.h"
#include "WindowImplementation.h"
#include "pch.h"

namespace Mirage
{
	class MIRAGE_API GameWindow
	{
	public:
		GameWindow();
		void CreateWindow(int width, int height, const std::string & name);
		void SwapBuffers();
		void PollEvents();
		int GetWindowWidth() const;
		int GetWindowHeight() const;

	private:
		std::unique_ptr <WindowImplementation> mWindow;
	};
}
