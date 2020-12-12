#include "pch.h"
#include "Scene.h"

void Scene::Update()
{
	for (auto gameObject : gameObjects)
		gameObject->Update();
}

GameObject* Scene::CreateEmpty()
{
	return AddGameObject(new GameObject());
}

GameObject* Scene::AddGameObject(GameObject* gameObject)
{
	//gameObject->SetScene(this);
	gameObjects.push_back(gameObject);
	//creationQueue.push(gameObject);
	return gameObject;
}
