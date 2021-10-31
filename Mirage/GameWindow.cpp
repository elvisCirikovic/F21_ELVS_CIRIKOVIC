#include "pch.h"
#include "GameWindow.h"
#include "GLFWimpl/GlfwImplementation.h"

namespace Mirage
{
	GameWindow::GameWindow()
	{
#ifdef MIRAGE_WINDOWS
		mWindow = new GlfwImplementation();
#elif MIRAGE_MAC
		mWindow = new GlfwImplementation();
#elif MIRAGE_LINUX
		mWindow = new GlfwImplementation();
#else
		#only_Windows_Linux_Mac_are_supported
#endif

		mWindow->Init();
	}

	void GameWindow::CreateWindow(int width, int height, const std::string & name)
	{
		mWindow->CreateWindow(width, height, name);
	}
	void GameWindow::SwapBuffers()
	{
		mWindow->SwapBuffers();
	}
	void GameWindow::PollEvents()
	{
		mWindow->PollEvents();
	}
	int GameWindow::GetWindowWidth() const
	{
		return mWindow->GetWindowWidth();
	}
	int GameWindow::GetWindowHeight() const
	{
		return mWindow->GetWindowHeight();
	}
}