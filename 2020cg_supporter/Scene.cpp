#include "pch.h"
#include "Scene.h"

void Scene::Update()
{
	for (auto gameObject : gameObjects)
		gameObject->Update();
}

void Scene::Render()
{
	// ∞ÌπŒ¡ﬂ
}
