#pragma once

class CyanFW
{
private:
	static Scene* scene;
	static Graphics* graphics;

public:
	int Run(int, char**);

	static void Update();

	static void MouseInput(int button, int state, int x, int y)
	{
		Input::mousePosition = glm::vec2(x, y);
		switch (state)
		{
		case GLUT_DOWN:
			Input::mouses[button] = true;
			Input::mouseDown[button] = true;
			break;
		case GLUT_UP:
			Input::mouses[button] = false;
			Input::mouseUp[button] = true;
			break;
		default:
			break;
		}
	}

	static void PassiveMouseInput(int x, int y)
	{
		Input::mousePosition = glm::vec2(x, y);
	}

	static void KeyInput(unsigned char key, int x, int y)
	{
		Input::keys[('a' <= key && key <= 'z') ? key - ('a' - 'A') : key] = true;
		Input::keyDown[('a' <= key && key <= 'z') ? key - ('a' - 'A') : key] = true;
	}

	static void KeyUpInput(unsigned char key, int x, int y)
	{
		Input::keys[('a' <= key && key <= 'z') ? key - ('a' - 'A') : key] = false;
		Input::keyUp[('a' <= key && key <= 'z') ? key - ('a' - 'A') : key] = true;
	}

	static void SpecialKeyInput(int key, int x, int y)
	{
		switch (key)
		{
		case GLUT_KEY_LEFT:
			Input::keys[int(KeyCode::LeftArrow)] = true;
			Input::keyDown[int(KeyCode::LeftArrow)] = true;
			break;
		case GLUT_KEY_RIGHT:
			Input::keys[int(KeyCode::RightArrow)] = true;
			Input::keyDown[int(KeyCode::RightArrow)] = true;
			break;
		case GLUT_KEY_UP:
			Input::keys[int(KeyCode::UpArrow)] = true;
			Input::keyDown[int(KeyCode::UpArrow)] = true;
			break;
		case GLUT_KEY_DOWN:
			Input::keys[int(KeyCode::DownArrow)] = true;
			Input::keyDown[int(KeyCode::DownArrow)] = true;
			break;
		default:
			break;
		}
	}

	static void SpecialKeyUpInput(int key, int x, int y)
	{
		switch (key)
		{
		case GLUT_KEY_LEFT:
			Input::keys[int(KeyCode::LeftArrow)] = false;
			Input::keyUp[int(KeyCode::LeftArrow)] = true;
			break;
		case GLUT_KEY_RIGHT:
			Input::keys[int(KeyCode::RightArrow)] = false;
			Input::keyUp[int(KeyCode::RightArrow)] = true;
			break;
		case GLUT_KEY_UP:
			Input::keys[int(KeyCode::UpArrow)] = false;
			Input::keyUp[int(KeyCode::UpArrow)] = true;
			break;
		case GLUT_KEY_DOWN:
			Input::keys[int(KeyCode::DownArrow)] = false;
			Input::keyUp[int(KeyCode::DownArrow)] = true;
			break;
		default:
			break;
		}
	}
};
