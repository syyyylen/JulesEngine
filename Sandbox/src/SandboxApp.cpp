#include <JulesEngine.h>

class ExampleLayer : public JulesEngine::Layer
{
public:
    ExampleLayer() : Layer("Example")
    {
        
    }

    void OnUpdate() override
    {
        if(JulesEngine::Input::IsKeyPressed(JE_KEY_TAB))
            JE_INFO("Tab key pressed");
    }

    void OnEvent(JulesEngine::Event& event) override
    {
        //JE_INFO("Example Layer : OnEvent");
    }
};

class Sandbox : public JulesEngine::Application
{
public :
    Sandbox()
    {
        PushLayer(new ExampleLayer());
        PushOverlay(new JulesEngine::ImGuiLayer());
    }
    ~Sandbox(){}
};

JulesEngine::Application* JulesEngine::CreateApplication()
{
    return new Sandbox();
}
