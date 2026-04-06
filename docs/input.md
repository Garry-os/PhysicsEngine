# User input
## Overview
The input system provide access to the user's keyboard and mouse.
Types of input:
- Keyboard
- Mouse

The input is generally handled during the Update() loop.
There are two types of input:
- Polling (Constantly checking state)
- Event

**NOTE:** This document is only about input polling, for learning about the events,
go to `docs/events.md`.

## API functions
### IsKeyPressed()
Check the keyboard state if a key has been pressed. <br>
Parameter: Keycode <br>
The keycode can be used as `ENGINE_KEY_[KEY]`.

Example:
```cpp
if (Engine::Input::IsKeyPressed(ENGINE_KEY_A))
{
    // Handle key press here
}
```

### IsMouseButtonPressed()
Check the mouse state if a mouse button has been pressed (e.g left-click). <br>
Parameter: Mouse code. <br>
The mouse code can be used as `ENGINE_MOUSE_BUTTON_[BUTTON]`

Example:
```cpp
if (Engine::Input::IsMouseButtonPressed(ENGINE_MOUSE_BUTTON_LEFT))
{
    // Handle left click here
}
```

### GetMouseX()
Get the mouse's X coordinate. <br>
Parameter: **None** <br>
Returns the X coordinate.

### GetMouseY()
Get the mouse's Y coordinate. <br>
Parameter: **None** <br>
Returns the Y coordinate.

