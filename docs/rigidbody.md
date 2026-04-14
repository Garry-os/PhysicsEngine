# Rigidbody2D
## Overview
A rigid body is a physics object that have physics applied to it. It makes objects behave realisticly by using physics.

## Basic usage
### Initializing
When initializing a rigidbody, you will pass in the positions and the body's mass.
### Interactions
There are two main interactions:
- Apply a force.
- Update the body's positions.

When applying a force, you pass in the amount of forces in X, Y. <br>
The forces do **accumulate** up. <br>

When updating, you need to pass in the delta time from the **Update** loop. <br> <br>
**NOTE:** All force apply and updating to a rigidbody should be done in the `FixedUpdate()` loop, instead of the normal `Update()` loop. This is because the fixed update uses a fixed time interval, resulting in more stability.

### Examples
Down here is an example using the rigidbody2D to apply forces and updating it. It also initializes and renders the rigidbody.
```cpp
// Initializes the body
void SandboxApp::Start()
{
    // X, Y, mass
    m_Body = Engine::Rigidbody2D(300.0f, 200.0f, 50.0f);
}

// Do all physics stuff in this function
void SandboxApp::FixedUpdate(float deltaTime)
{
    // Apply a force
    m_Body.ApplyForce(250, 250);

    // Update the body
    m_Body.Update(deltaTime);
}

// Render the body
void SandboxApp::Update(float deltaTime)
{
    Engine::Renderer2D::BeginScene(m_Camera);

    // Renders the body
    Engine::Renderer2D::DrawCircle(m_Body.GetPos(), 25.0f, {1.0f, 0.0f, 0.0f, 1.0f});

    Engine::Renderer2D::EndScene();
}
```
