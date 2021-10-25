#include "pch.h"
#include "MirageApp.h"


namespace Mirage
{
	void MirageApp::Run()
	{
		std::cout << "Mirage is running..." << std::endl;
		while (true)
		{
			OnUpdate();


		}
	}

	void MirageApp::OnUpdate()
	{

	}
	MirageApp::MirageApp()
	{

	}
}