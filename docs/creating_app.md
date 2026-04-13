# Project creation

## Creating a project
To create an application or project using this game engine. First, you need to make your project directory inside `projects/`. <br>

Then, creating a Makefile with:
```makefile
APP_NAME += Sandbox ## Edit your project name here!
include ../common.mk
```

**NOTE:** Remember to change `APP_NAME` to your wanted name.

## Making an app
First, you need to define your game's class in a header file. <br>
This class must inherits from `Engine::Application`, and implement functions such as `Start()`, `Update()`, `FixedUpdate()` and `OnEvent()`. <br>

### Application functions
The function `Start()` is called during the engine's initialization. <br>
The `Update()` function is the application's core, it is basically a game loop. <br> <br>
If you're building a physics simulation, it is handy to use `FixedUpdate()` as it runs every 0.02 seconds, making it stable for physics applications. <br> <br>
The `OnEvent()` function is also useful for handling events without polling, see more in `docs/events.md`.


Example:
```cpp
// SandboxApp.h
#pragma once
#include <Engine/Engine.h>

class SandboxApp : public Engine::Application
{
public:
    SandboxApp() = default;
    ~SandboxApp() = default;

    // Main functions
    void Start() override;
    void Update(float deltaTime) override;
    void OnEvent(Engine::Event& event) override;

private:
    // Define your variables here
    Engine::Texture m_Texture;
    Engine::Camera m_Camera;
};
```
And in the main cpp file, you must implement all the functions.
Example:
```cpp
#include "SandboxApp.h"

void SandboxApp::Start()
{
    // When the engine start
    // You should really get the camera
    // Learn more about the camera in docs/renderer.md
    m_Camera = Application::Get().GetCamera();
}

void SandboxApp::Update(float deltaTime)
{
    // Game loop code
    // Get camera's position
    Engine::Math::Vector2 cameraPos = m_Camera.GetPosition();
    // Check input
    if (Engine::Input::IsKeyPressed(ENGINE_KEY_A))
    {
        // Handle key press
    }

    // Remember to update the camera's position if you modified it
    m_Camera.SetPosition(cameraPos);

    // Render here
    Engine::Renderer2D::BeginScene(m_Camera);

    // Draw some stuff
    Engine::Renderer2D::DrawQuad({100.0f}, {50.0f}, {1.0f, 1.0f, 0.0f, 1.0f});

    Engine::Renderer2D::EndScene();
}

// Called every 0.02 seconds
// Useful for physics applications
// deltaTime is a fixed 0.02f
void SandboxApp::FixedUpdate(float deltaTime)
{
    // Handle physics
}

void SandboxApp::OnEvent(Engine::Event& event)
{
    // Handle events like keypresses
    // Learn more about events in docs/events.md
    if (event.GetEventType() == Engine::EventType::KeyPressed)
    {
        auto& keyEvent = static_cast<Engine::KeyPressedEvent&>(event);
        LOG("Key code: %d\n", keyEvent.GetKeyCode());
    }
}

```
The examples above includes many usages of the engine's API. <br>
You can see more in the `projects/Sandbox/` example.
