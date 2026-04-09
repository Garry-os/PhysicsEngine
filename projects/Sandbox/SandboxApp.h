#pragma once
#include <Engine/Engine.h>

class SandboxApp : public Engine::Application
{
public:
    SandboxApp() = default;
    ~SandboxApp() = default;

    void Start() override;
    void Update(float deltaTime) override;
    void OnEvent(Engine::Event& event) override;

private:
    Engine::Texture m_Texture;
    Engine::Camera m_Camera;
};


