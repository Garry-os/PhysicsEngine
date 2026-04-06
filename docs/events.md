# Input events
## Overview
Similar to the polling system, it provides access to the keyboard and mouse. <br>
Although, one different is that you don't constantly check for the input's state. <br>
Instead, there will be an event function that will be called if an input occurs. <br>

When checking events, everything must be put into the `OnEvent()` function.

## Handling events
Everytime an input occurs, `OnEvent()` will be called with the event passed in as a parameter. <br>
When checking events, check the event's type. <br>

Example:
```cpp
if (event.GetEventType() == Engine::EventType::KeyPressed)
{
    // Handle key press
    // Get the event type
    auto& keyEvent = static_cast<Engine::KeyPressedEvent&>(event);

    // Print the key code
    LOG("KeyCode: %d\n", keyEvent.GetKeyCode());
}
```
Other events are also handled similarly.

## API functions
TODO: Explain

For knowing the API functions, you can look into the sandbox's example `OnEvent()` function.


