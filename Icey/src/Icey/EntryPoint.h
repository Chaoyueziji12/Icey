#pragma once
#include "Application.h"
#include "Log.h"
#ifdef  IC_PLATFORM_WINDOWS

extern Ic::Application* Ic::CreateApplication();

int main(int argc, char** argv)
{
	Ic::Log::Init();
	IC_CORE_WARN("Initialized Log!");
	IC_INFO("Hello!");
	auto app = Ic::CreateApplication();
	app->Run();
	delete app;
}

#endif