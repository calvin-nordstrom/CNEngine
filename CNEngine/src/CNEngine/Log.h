#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace CNEngine {
	class CNENGINE_API Log {
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
#define CNE_CORE_TRACE(...) ::CNEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define CNE_CORE_INFO(...) ::CNEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define CNE_CORE_WARN(...) ::CNEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define CNE_CORE_ERROR(...) ::CNEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define CNE_CORE_FATAL(...) ::CNEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)

// Client log macros
#define CNE_TRACE(...) ::CNEngine::Log::GetClientLogger()->trace(__VA_ARGS__)
#define CNE_INFO(...) ::CNEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define CNE_WARN(...) ::CNEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define CNE_ERROR(...) ::CNEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define CNE_FATAL(...) ::CNEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)