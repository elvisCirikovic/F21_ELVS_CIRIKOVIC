#include "pch.h"
#include "GlfwImplementation.h"

namespace Mirage
{


	void GlfwImplementation::Init()
	{
		glfwInit();
	}

	void GlfwImplementation::CreateWindow(int width, int height, const std::string& name)
	{
		mWindow = glfwCreateWindow(width, height, name.c_str(), NULL, NULL);
		glfwMakeContextCurrent(mWindow);

		glfwSetWindowUserPointer(mWindow, &mCallBacks);

		glfwSetKeyCallback(mWindow, [](GLFWwindow* window, int key, int scancode, int action, int mods) {

			if (action == GLFW_PRESS || action == GLFW_REPEAT)
			{
				CallbackFunctions* callbacks{ (CallbackFunctions*)glfwGetWindowUserPointer(window) };
				KeyPressedEvent event{ key };
				callbacks->KeyPressedCallBack(event);
			}

			});
	}

	void GlfwImplementation::SwapBuffers()
	{
		glfwSwapBuffers(mWindow);
	}

	void GlfwImplementation::PollEvents()
	{
		glfwPollEvents();
	}

	int GlfwImplementation::GetWindowWidth() const
	{
		int width = 0;
		int height = 0;
		glfwGetWindowSize(mWindow, &width, &height);
		return width;
	}

	int GlfwImplementation::GetWindowHeight() const
	{
		int width = 0;
		int height = 0;
		glfwGetWindowSize(mWindow, &width, &height);
		return height;
	}

	void GlfwImplementation::SetKeyPressedCallBack(std::function<void(KeyPressedEvent&)> func)
	{
		mCallBacks.KeyPressedCallBack = func;
	}



}