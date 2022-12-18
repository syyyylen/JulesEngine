#pragma once

#ifdef JE_PLATFORM_WINDOWS
    #ifdef JE_BUILD_DLL
        #define JULESENGINE_API __declspec(dllexport)
    #else
        #define JULESENGINE_API __declspec(dllimport)
    #endif
#else
    #error JulesEngine only support Windows
#endif

#define BIT(x) (1<<x)