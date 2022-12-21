#include "jepch.h"

#include "Application.h"

#include <GL/gl.h>

#include "Events/MouseEvent.h"
#include "JulesEngine/Events/ApplicationEvent.h"
#include "JulesEngine/Log.h"

namespace JulesEngine
{

    Application::Application()
    {
        m_Window = std::unique_ptr<Window>(Window::Create());
    }

    Application::~Application()
    {
    }

    void Application::Run()
    {
        while (m_Running)
        {
            m_Window->OnUpdate();
        }
    }
    
}

