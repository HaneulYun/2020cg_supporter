#pragma once

class Scene
{
private:
	deque<GameObject*> gameObjects;

public:
	Camera* camera;
	map<class Shader*, map<class Mesh*, deque<GameObject*>>> renderSets;

public:
	void Update();
};
