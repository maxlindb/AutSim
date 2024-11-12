#pragma once

#include "Core.h"

namespace AutSim
{
	class AUTSIM_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in CLIENT
	Application* CreateApplication();
}


