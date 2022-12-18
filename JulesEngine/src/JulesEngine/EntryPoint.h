#pragma once
#include "JulesEngine.h"
#include "Log.h"

#ifdef JE_PLATFORM_WINDOWS

extern JulesEngine::Application* JulesEngine::CreateApplication();

int main(int argc, char** argv)
{
    //TODO move this into a proper place 
    JulesEngine::Log::Init();
    JE_CORE_WARN("Initialized Core Logger");
    JE_INFO("Initialized Client Logger");
    
    auto app = JulesEngine::CreateApplication();
    app->Run();
    delete app;
}

#endif