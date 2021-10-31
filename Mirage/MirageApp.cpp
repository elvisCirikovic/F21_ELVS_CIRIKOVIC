#include "pch.h"
#include "MirageApp.h"
#include  "GLFW/glfw3.h"

namespace Mirage
{
	void MirageApp::Run()
	{
		std::cout << "Mirage is running..." << std::endl;

		



		mGameWindow.CreateWindow(800,600,"test");

		while (true)
		{
			OnUpdate();

			mGameWindow.SwapBuffers();
			mGameWindow.PollEvents();
;

		}
	}

	void MirageApp::OnUpdate()
	{

	}
	MirageApp::MirageApp()
	{
		
	}
}