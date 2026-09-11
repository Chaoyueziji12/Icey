#pragma once

#ifdef  IC_PLATFORM_WINDOWS

extern Ic::Application* Ic::CreateApplication();

int main(int argc, char** argv)
{
	auto app = Ic::CreateApplication();
	app->Run();
	delete app;
}

#endif