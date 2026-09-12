#pragma once

#include <memory>
#include <spdlog/spdlog.h>
#include <spdlog/sinks/stdout_color_sinks.h>
#include "Core.h"

namespace Ic
{
	class IC_API Log
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

#define IC_CORE_ERROR(...)    ::Ic::Log::GetCoreLogger()->error(__VA_ARGS__)
#define IC_CORE_WARN(...)     ::Ic::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define IC_CORE_INFO(...)     ::Ic::Log::GetCoreLogger()->info(__VA_ARGS__)
#define IC_CORE_TRACE(...)    ::Ic::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define IC_CORE_FATAL(...)    ::Ic::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define IC_ERROR(...)         ::Ic::Log::GetClientLogger()->error(__VA_ARGS__)
#define IC_WARN(...)          ::Ic::Log::GetClientLogger()->warn(__VA_ARGS__)
#define IC_INFO(...)          ::Ic::Log::GetClientLogger()->info(__VA_ARGS__)
#define IC_TRACE(...)         ::Ic::Log::GetClientLogger()->trace(__VA_ARGS__)
#define IC_FATAL(...)         ::Ic::Log::GetClientLogger()->fatal(__VA_ARGS__)