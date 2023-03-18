#pragma once

#include "JulesEngine/Layer.h"

namespace JulesEngine
{
    class JULESENGINE_API  ImGuiLayer : public Layer
    {
    public:
        ImGuiLayer();
        ~ImGuiLayer();

        void OnAttach();
        void OnDetach();
        void OnUpdate();
        void OnEvent(Event& event);

    private:
        float m_Time = 0.0f;
    };
}
