#include <Icey.h>

class Sandbox : public Ic::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

Ic::Application* Ic::CreateApplication()
{
	return new Sandbox();
}