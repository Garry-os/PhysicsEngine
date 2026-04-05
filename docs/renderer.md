# Renderer
## Overview
The engine have a 2D renderer using OpenGL.

## Rendering flow
The rendering flow in the game loop include:
- BeginScene(camera)
- Draw calls
- EndScene()

All draw calls are place between BeginScene() and EndScene()

Example:
```cpp
Engine::Renderer2D::BeginScene(m_Camera);

Engine::Renderer2D::DrawCircle({50.0f}, 25.0f, {1.0f, 0.0f, 0.0f, 1.0f});
Engine::Renderer2D::DrawQuad({100.0f}, {50.0f}, {1.0f, 1.0f, 0.0f, 1.0f});
Engine::Renderer2D::DrawQuad({400.0f}, {150.0f}, m_Texture);

Engine::Renderer2D::EndScene();
```

## Coordination system
- Origin (0, 0) is at the left-top of the screen.
- +X will move to the right.
- +Y will move down.

## Camera
The renderer uses a camera to control:
- position
- projection

All objects are drawn in world space and transform by the camera.

## API functions
### DrawTriangle()
Draw a triangle at a specific position with a size and color.
Parameter:
- Position (Vector2)
- Size (Vector2)
- RGBA Color (Vector4)

### DrawQuad()
Draw a quad at a specific position with a size and color.
NOTE: There are two variants DrawQuad(), the other one will be listed below.
Parameter:
- Position (Vector2)
- Size (Vector2)
- RGBA Color (Vector4)

### DrawQuad()
Draw a quad at a specific position with a size and with a **texture**.
Parameter:
- Position (Vector2)
- Size (Vector2)
- Texture

A texture can be created via Texture.Load(path).
Example:
```cpp
Engine::Texture texture;
texture.load("Assets/Textures/OpenGL.png");
```

### DrawCircle()
Draw a circle at a specific position with a size and color.
Parameter:
- Position (Vector2)
- Radius (float)
- Color (Vector4)

