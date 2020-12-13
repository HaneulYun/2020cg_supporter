#pragma once

enum class KeyCode
{
	Alpha0 = '0', Alpha1, Alpha2, Alpha3, Alpha4, Alpha5, Alpha6, Alpha7, Alpha8, Alpha9,
	A = 'A', B, C, D, E, F, G, H, I, J, K, L, M, N, O, P, Q, R, S, T, U, V, W, X, Y, Z,
	UpArrow = 273, DownArrow, RightArrow, LeftArrow,
};

class Input : public Singleton<Input>
{
public:
	static glm::vec2 mousePosition;
	static glm::vec2 mouseOffset;

	static bool keys[512];
	static bool keyUp[512];
	static bool keyDown[512];
	static bool mouses[5];
	static bool mouseUp[3];
	static bool mouseDown[3];

	static const int WIDDOW_WIDTH = 1280;
	static const int WINDOW_HEIGHT = 720;
public:
	Input() {};
	~Input() {};

	static void Update();
	static bool GetKey(KeyCode key);
	static bool GetKeyUp(KeyCode key);
	static bool GetKeyDown(KeyCode key);
	static bool GetMouseButton(int button);
	static bool GetMouseButtonUp(int button);
	static bool GetMouseButtonDown(int button);

private:
	static bool firstMove;
};
