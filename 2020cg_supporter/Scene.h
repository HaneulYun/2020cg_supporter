#pragma once

class Scene
{
private:
	deque<GameObject*> gameObjects;

public:
	Camera* camera;
	map<class Shader*, map<class Mesh*, deque<GameObject*>>> renderSets;

public:
	virtual void BuildObject() = 0;
	void Update();

	GameObject* CreateEmpty();
	GameObject* AddGameObject(GameObject*);
};
