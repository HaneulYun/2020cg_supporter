#pragma once

class Component
{
public:
	class GameObject* gameObject;

public:
	virtual void Start() {};
	virtual void Update() {};
};
