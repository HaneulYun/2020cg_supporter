#include "pch.h"
#include "Input.h"

glm::vec2 Input::mousePosition;
glm::vec2 Input::mouseOffset;

bool Input::keys[512];
bool Input::keyUp[512];
bool Input::keyDown[512];
bool Input::mouses[5];
bool Input::mouseUp[3];
bool Input::mouseDown[3];

bool Input::firstMove = true;

void Input::Update()
{
	for (auto& ref : keyDown)
		ref = false;
	for (auto& ref : mouseDown)
		ref = false;

	mouseOffset.x = mousePosition.x - WIDDOW_WIDTH * 0.5f;
	mouseOffset.y = WINDOW_HEIGHT * 0.5f - mousePosition.y;
	
	if (mousePosition.x != WIDDOW_WIDTH * 0.5f || mousePosition.y != WINDOW_HEIGHT * 0.5f) 
		glutWarpPointer(WIDDOW_WIDTH * 0.5f, WINDOW_HEIGHT * 0.5f);

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

bool Input::GetMouseButton(MouseCode button)
{
	return mouses[(int)button];
}

bool Input::GetMouseButtonUp(MouseCode button)
{
	return mouseUp[(int)button];
}

bool Input::GetMouseButtonDown(MouseCode button)
{
	return mouseDown[(int)button];
}
