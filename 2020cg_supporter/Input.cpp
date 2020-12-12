#include "pch.h"
#include "Input.h"

glm::vec2 Input::mousePosition;
bool Input::keys[512];
bool Input::keyUp[512];
bool Input::keyDown[512];
bool Input::mouses[3];
bool Input::mouseUp[3];
bool Input::mouseDown[3];

void Input::Update()
{
	for (auto& ref : keyDown)
		ref = false;
	for (auto& ref : mouseDown)
		ref = false;
}

bool Input::GetKey(KeyCode key)
{
	return keys[(int)key];
}

bool Input::GetKeyUp(KeyCode key)
{
	return keyUp[(int)key];
}

bool Input::GetKeyDown(KeyCode key)
{
	return keyDown[(int)key];
}

bool Input::GetMouseButton(int button)
{
	return mouses[button];
}

bool Input::GetMouseButtonUp(int button)
{
	return mouseUp[button];
}

bool Input::GetMouseButtonDown(int button)
{
	return mouseDown[button];
}
