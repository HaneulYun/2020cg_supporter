#pragma once

class GameObject
{
private:
	deque<Component*> components;

public:
	void Start();
	void Update();
};
