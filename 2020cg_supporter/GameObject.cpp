#include "pch.h"
#include "GameObject.h"
;
void GameObject::Start()
{
	for (auto component : components)
		component->Start();
	for (auto child : children)
		child->Start();

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
	for (auto child : children)
		child->Update();
}

GameObject* GameObject::AddChild(GameObject* child)
{
	if (!child)
		child = new GameObject();
	child->scene = scene;
	child->parent = this;
	children.push_back(child);
	return child;
}

glm::mat4 GameObject::GetMatrix()
{
	auto transform = GetComponent<Transform>();
	if (!transform) return glm::mat4(1.0f);
	if (parent)
		return transform->locatToParentMatrix * parent->GetMatrix();
	return transform->locatToParentMatrix;
}
