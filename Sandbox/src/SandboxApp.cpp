#include <JulesEngine.h>
#include <iostream>


class Sandbox : public JulesEngine::Application
{
public :
    Sandbox(){}
    ~Sandbox(){}
};

JulesEngine::Application* JulesEngine::CreateApplication()
{
    std::cout << "Creating Application" << std::endl;
    
    return new Sandbox();
}
