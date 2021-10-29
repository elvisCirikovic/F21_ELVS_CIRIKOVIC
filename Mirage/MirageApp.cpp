#include "pch.h"
#include "MirageApp.h"
#include  "GLFW/glfw3.h"

namespace Mirage
{
	void MirageApp::Run()
	{
		std::cout << "Mirage is running..." << std::endl;
		GLFWwindow* window;

		glfwInit();

		window = glfwCreateWindow(800, 600, "test", NULL, NULL);

		while (true)
		{
			OnUpdate();
			glfwSwapBuffers(window);
			glfwPollEvents();

		}
	}

	void MirageApp::OnUpdate()
	{

	}
	MirageApp::MirageApp()
	{

	}
}