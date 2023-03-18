#include <JulesEngine.h>

class ExampleLayer : public JulesEngine::Layer
{
public:
    ExampleLayer() : Layer("Example")
    {
        
    }

    void OnUpdate() override
    {
        //JE_INFO("Example Layer : Update");
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
