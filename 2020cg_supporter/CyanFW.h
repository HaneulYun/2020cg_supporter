#pragma once

class CyanFW
{
private:
	static Scene* scene;
	static Graphics* graphics;

public:
	int Run(int, char**);

	static void Update();
};
