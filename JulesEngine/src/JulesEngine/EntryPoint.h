#pragma once
#include "JulesEngine.h"

#ifdef JE_PLATFORM_WINDOWS

extern JulesEngine::Application* JulesEngine::CreateApplication();

int main(int argc, char** argv)
{
    printf("Jules Engine\n");
    auto app = JulesEngine::CreateApplication();
    app->Run();
    delete app;
}

#endif