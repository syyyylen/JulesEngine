#include "jepch.h"

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
        if(e.IsInCategory(EventCategoryApplication))
        {
            JE_WARN(e);
        }

        MouseMovedEvent me(83.4f, 14.4f);
        if(me.GetEventType() == EventType::MouseMoved)
        {
            JE_WARN(me);
        }
        
        while (true);
    }
    
}

