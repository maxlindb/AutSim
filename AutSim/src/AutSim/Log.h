#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"


namespace AutSim {

	class AUTSIM_API Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;

	};
}

// Core log macros
#define AUT_CORE_TRACE(...)    ::AutSim::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define AUT_CORE_INFO(...)     ::AutSim::Log::GetCoreLogger()->info(__VA_ARGS__)
#define AUT_CORE_WARN(...)     ::AutSim::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define AUT_CORE_ERROR(...)    ::AutSim::Log::GetCoreLogger()->error(__VA_ARGS__)
#define AUT_CORE_FATAL(...)    ::AutSim::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define AUT_TRACE(...)    ::AutSim::Log::GetClientLogger()->trace(__VA_ARGS__)
#define AUT_INFO(...)     ::AutSim::Log::GetClientLogger()->info(__VA_ARGS__)
#define AUT_WARN(...)     ::AutSim::Log::GetClientLogger()->warn(__VA_ARGS__)
#define AUT_ERROR(...)    ::AutSim::Log::GetClientLogger()->error(__VA_ARGS__)
#define AUT_FATAL(...)    ::AutSim::Log::GetClientLogger()->fatal(__VA_ARGS__)
