#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace JulesEngine
{
    
class JULESENGINE_API Log
{
public:
    static void Init();

    inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
    inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

private :
    //Logger for the engine 
    static std::shared_ptr<spdlog::logger> s_CoreLogger;
    //Logger for the client
    static std::shared_ptr<spdlog::logger> s_ClientLogger;
};

}

//Core log macros
#define JE_CORE_FATAL(...) ::JulesEngine::Log::GetCoreLogger()->fatal(__VA_ARGS__)
#define JE_CORE_ERROR(...) ::JulesEngine::Log::GetCoreLogger()->error(__VA_ARGS__)
#define JE_CORE_WARN(...) ::JulesEngine::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define JE_CORE_INFO(...) ::JulesEngine::Log::GetCoreLogger()->info(__VA_ARGS__)
#define JE_CORE_TRACE(...) ::JulesEngine::Log::GetCoreLogger()->trace(__VA_ARGS__)

//Client log macros
#define JE_FATAL(...) ::JulesEngine::Log::GetClientLogger()->fatal(__VA_ARGS__)
#define JE_ERROR(...) ::JulesEngine::Log::GetClientLogger()->error(__VA_ARGS__)
#define JE_WARN(...) ::JulesEngine::Log::GetClientLogger()->warn(__VA_ARGS__)
#define JE_INFO(...) ::JulesEngine::Log::GetClientLogger()->info(__VA_ARGS__)
#define JE_TRACE(...) ::JulesEngine::Log::GetClientLogger()->trace(__VA_ARGS__)