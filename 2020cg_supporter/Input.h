#pragma once

enum class KeyCode
{
	Alpha0 = '0', Alpha1, Alpha2, Alpha3, Alpha4, Alpha5, Alpha6, Alpha7, Alpha8, Alpha9,
	A = 'A', B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
	UpArrow = 273, DownArrow, RightArrow, LeftArrow,
};

enum class MouseCode
{
	Left = 0, WheelButton, Right, WheelUp, WheelDown
};

class Input : public Singleton<Input>
{
public:
	static glm::vec2 mousePosition;
	static bool keys[512];
	static bool keyUp[512];
	static bool keyDown[512];
	static bool mouses[3];
	static bool mouseUp[3];
	static bool mouseDown[3];

public:
	Input() {};
	~Input() {};

	static void Update();
	static bool GetKey(KeyCode key);
	static bool GetKeyUp(KeyCode key);
	static bool GetKeyDown(KeyCode key);
	static bool GetMouseButton(MouseCode button);
	static bool GetMouseButtonUp(MouseCode button);
	static bool GetMouseButtonDown(MouseCode button);

private:
	static bool firstMove;
};
