#pragma once

class GameObject
{
private:
	deque<Component*> components;

public:
	void Start();
	void Update();

	//template <typename T>
	//T* AddComponent(T* component);

	template <typename T>
	T* AddComponent();
	
	//template <typename T>
	//T* GetComponent();
};

template<typename T>
inline T* GameObject::AddComponent()
{
	Component* component = new T();
	component->gameObject = this;
	components.push_back(component);

	//if (typeid(Transform).name() == typeid(T).name())
	//	transform = dynamic_cast<Transform*>(component);
	//if (typeid(RectTransform).name() == typeid(T).name())
	//	transform = dynamic_cast<RectTransform*>(component);
	//if (typeid(MeshFilter).name() == typeid(T).name())
	//	meshFilter = component;
	//if (typeid(Renderer).name() == typeid(T).name())
	//	renderer = component;

	return dynamic_cast<T*>(component);
}
