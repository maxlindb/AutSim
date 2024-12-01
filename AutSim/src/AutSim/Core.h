#pragma once

#ifdef AUT_PLATFORM_WINDOWS
	#ifdef AUT_BUILD_DLL
		#define AUTSIM_API __declspec(dllexport)
	#else
		#define AUTSIM_API __declspec(dllimport)
	#endif
#else
	#error AutSim only supports Windows right now!
#endif

#define BIT(x) (1 << x)