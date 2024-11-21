#pragma once

#ifdef AUT_PLATFORM_WINDOWS

extern AutSim::Application* AutSim::CreateApplication();

int main(int argc, char** argv)
{
	printf("AutSim engine startup\n");
	AutSim::Log::Init();	
	AUT_CORE_WARN("Initialized Log!");	
	int a = 5;
	AUT_INFO("Hello! Var={0}", a);

	auto app = AutSim::CreateApplication();
	app->Run();
	delete app;
}

#endif


