#include "pch.h"
#include "GameObject.h"
;
void GameObject::Start()
{
	for (auto component : components)
		component->Start();

	auto renderer = GetComponent<Renderer>();
	auto meshFilter = GetComponent<MeshFilter>();

	Shader* shader = renderer ? renderer->shader : nullptr;
	Mesh* mesh = meshFilter ? meshFilter->mesh : nullptr;

	scene->renderSets[shader][mesh].push_back(this);

	isStarted = true;
}

void GameObject::Update()
{
	if (!isStarted)
		Start();
	for (auto component : components)
		component->Update();
}
