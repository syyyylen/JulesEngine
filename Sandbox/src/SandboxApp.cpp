#include <JulesEngine.h>

class Sandbox : public JulesEngine::Application
{
public :
    Sandbox(){}
    ~Sandbox(){}
};

JulesEngine::Application* JulesEngine::CreateApplication()
{
    return new Sandbox();
}
