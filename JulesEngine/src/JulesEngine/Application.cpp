
#include <iostream>

#include "Application.h"

#include "Events/MouseEvent.h"
#include "JulesEngine/Events/ApplicationEvent.h"
#include "JulesEngine/Log.h"

namespace JulesEngine
{

    Application::Application()
    {
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        WindowResizeEvent e(1280, 720);
        JE_WARN(e);

        MouseMovedEvent me(83.4f, 14.4f);
        JE_WARN(me);
        
        while (true);
    }
    
}

