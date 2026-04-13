#include <GLFW/glfw3.h>
#include <Engine/Engine.h>

int main()
{
    Engine::Logger::Init();

    // Create an application
	Engine::Application* app = Engine::CreateApp();

    app->Start();
    Engine::Window& window = app->GetWindow();

    float deltaTime = 0.0f; // Time between last frame and current frame
    float lastFrame = 0.0f; // Time of last frame

	float fixedDelta = 0.02f; // Fixed delta time (0.02 seconds)
	float accumulator = 0.0f; // Delta time accumulation
    while (!window.WindowShouldClose())
    {
        // Calculate the delta time
        float currentFrame = static_cast<float>(glfwGetTime());
        deltaTime = currentFrame - lastFrame;
        lastFrame = currentFrame;

		// Check if FixedUpdate() should be called
		accumulator += deltaTime;
		while (accumulator >= fixedDelta)
		{
			// Delta time is always 0.02 seconds
			app->FixedUpdate(fixedDelta);
			accumulator -= fixedDelta;
		}

        Engine::Renderer::Clear(0.0f, 0.0f, 0.0f);

        // Render...
        app->Update(deltaTime);

        window.SwapBuffers();
        window.PollEvents();
    }

    Engine::Renderer::Shutdown();
    delete app;
    return 0;
}



