#pragma once

class Scene
{
private:
	deque<GameObject*> gameObjects;

public:
	void Update();
};
