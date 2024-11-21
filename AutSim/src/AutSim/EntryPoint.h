#pragma once

#ifdef AUT_PLATFORM_WINDOWS

extern AutSim::Application* AutSim::CreateApplication();

int main(int argc, char** argv)
{
	printf("AutSim engine startup\n");
	AutSim::Log::Init();
	AutSim::Log::GetCoreLogger()->warn("Initialized Log!");
	AutSim::Log::GetClientLogger()->info("Hello");

	auto app = AutSim::CreateApplication();
	app->Run();
	delete app;
}

#endif


