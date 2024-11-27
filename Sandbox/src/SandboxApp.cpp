#include <AutSim.h>

class Sandbox : public AutSim::Application
{
public:
	Sandbox()
	{

	}

	~Sandbox()
	{

	}

};

AutSim::Application* AutSim::CreateApplication()
{
	return new Sandbox();
}