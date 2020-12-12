#include "pch.h"
#include "Scene.h"

void Scene::update()
{
	for (auto gameObject : gameObjects)
		gameObject->update();
}

void Scene::render()
{
	// ∞ÌπŒ¡ﬂ
}
