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
	if (!isActive) return;

	if (!isStarted)
		Start();
	for (auto component : components)
		component->Update();
}

void GameObject::SetActive(bool _rhs)
{
	isActive = false;
}

bool GameObject::GetActive()
{
	return isActive;
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

GameObject* GameObject::GetParent()
{
	return parent;
}

glm::mat4 GameObject::GetMatrix()
{
	auto transform = GetComponent<Transform>();
	if (!transform) return glm::mat4(1.0f);
	if (parent)
		return parent->GetMatrix() * transform->locatToParentMatrix;
	return transform->locatToParentMatrix;
}
