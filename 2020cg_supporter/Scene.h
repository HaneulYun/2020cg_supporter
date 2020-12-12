#pragma once

class Scene
{
private:
	deque<GameObject*> gameObjects;

public:
	Camera* camera;
	map<GLuint, map<class Mesh*, deque<GameObject*>>> renderSets;

public:
	void Update();
};
