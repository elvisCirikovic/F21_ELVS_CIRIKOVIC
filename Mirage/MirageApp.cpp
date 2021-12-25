#include "pch.h"
#include "MirageApp.h"
#include "Sprite.h"
#include "Shader.h"
#include "Renderer.h"


#define GLFW_INCLUDE_NONE
#include  "GLFW/glfw3.h"
#include "glad/glad.h"

#include "stb_image.h"




namespace Mirage
{
	void MirageApp::Run()
	{
		MIRAGE_LOG("Mirage App is running...");

		
		mTimeOfNextFrame = std::chrono::steady_clock::now()+mFrameDuration;

		while (true)
		{
			Renderer::ClearFrame();

			OnUpdate();
			std::this_thread::sleep_until(mTimeOfNextFrame);

			
			mGameWindow.SwapBuffers();
			mGameWindow.PollEvents();

			mTimeOfNextFrame += mFrameDuration;

		}
		Renderer::ShutDown();
	}

	void MirageApp::OnUpdate()
	{

	}
	void MirageApp::OnKeyPressed(KeyPressedEvent& event)
	{
		MIRAGE_LOG(event.GetKeyCode());
	}
	int MirageApp::GetGameWindowWidth() const
	{
		return mGameWindow.GetWindowWidth();
	}
	int MirageApp::GetGameWindowHeight() const
	{
		return mGameWindow.GetWindowHeight();
	}
	MirageApp::MirageApp()
	{
		mGameWindow.CreateWindow(800, 800, "Game");

		mGameWindow.SetKeyPressedCallBack([this](KeyPressedEvent& event)
			{
				OnKeyPressed(event);
			});

		Renderer::Init();
	}
}