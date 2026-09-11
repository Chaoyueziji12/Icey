#pragma once

#include "Core.h"

namespace Ic {
	
	class IC_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	Application* CreateApplication();
}