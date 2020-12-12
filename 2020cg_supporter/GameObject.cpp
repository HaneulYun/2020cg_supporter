#include "pch.h"
#include "GameObject.h"
;
void GameObject::Start()
{
	for (auto component : components)
		component->Start();
}

void GameObject::Update()
{
	for (auto component : components)
		component->Update();
}
