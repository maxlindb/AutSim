#include "Application.h"

#include "AutSim/Events/ApplicationEvent.h"
#include "AutSim/Log.h"

namespace AutSim
{
	Application::Application()
	{
	}

	Application::~Application()
	{
	}

	void Application::Run()
	{	
		WindowResizeEvent e(1280, 720);
		AUT_TRACE(e);

		while (true);
	}
}