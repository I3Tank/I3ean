#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace I3ean {

	class I3EAN_API Log
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
#define I3_CORE_TRACE(...)	::I3ean::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define I3_CORE_INFO(...)	::I3ean::Log::GetCoreLogger()->info(__VA_ARGS__)
#define I3_CORE_WARN(...)	::I3ean::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define I3_CORE_ERROR(...)	::I3ean::Log::GetCoreLogger()->error(__VA_ARGS__)
#define I3_CORE_FATAL(...)	::I3ean::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define I3_TRACE(...)	::I3ean::Log::GetClientLogger()->trace(__VA_ARGS__)
#define I3_INFO(...)	::I3ean::Log::GetClientLogger()->info(__VA_ARGS__)
#define I3_WARN(...)	::I3ean::Log::GetClientLogger()->warn(__VA_ARGS__)
#define I3_ERROR(...)	::I3ean::Log::GetClientLogger()->error(__VA_ARGS__)
#define I3_FATAL(...)	::I3ean::Log::GetClientLogger()->fatal(__VA_ARGS__)