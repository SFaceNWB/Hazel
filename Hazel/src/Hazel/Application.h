#pragma once

#include "Core.h"

namespace Hazel {

	class __declspec(dllexport) Application
	{

	public:
		Application();
		~Application();
		void Run();

	};

	//To be defined in client
	Application* CreateApplication();

}

