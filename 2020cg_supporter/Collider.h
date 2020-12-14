#pragma once

using collisionFunction = void(*)(GameObject*);

class Collider : public Component
{
private /*�� ������ private ������ �����ϼ���.*/:
	Scene* scene = nullptr;
	BoundingBox* bb = nullptr;
	Transform* transform = nullptr;

	collisionFunction eventfunc = nullptr;
public  /*�� ������ public ������ �����ϼ���.*/:
	
protected:
	friend class GameObject;
	Collider() = default;
	Collider(Collider&) = default;

public:
	~Collider() {}

	void Start(/*�ʱ�ȭ �ڵ带 �ۼ��ϼ���.*/)
	{
		bb = gameObject->GetComponent<BoundingBox>();
		transform = gameObject->GetComponent<Transform>();
	}

	void Update(/*������Ʈ �ڵ带 �ۼ��ϼ���.*/)
	{
		if (eventfunc == nullptr)
			return;

		for (auto object : scene->GetObjects())
		{
			auto pos = transform->position;
			auto _bb = object->GetComponent<BoundingBox>();
			auto _pos = object->GetComponent<Transform>()->position;

			if (_bb == nullptr)
				return;

			if (bb->min.x + pos.x <= _bb->min.x + _pos.x && bb->max.x + pos.x >= _bb->max.x + _pos.x &&
				bb->min.y + pos.y <= _bb->min.y + _pos.y && bb->max.y + pos.y >= _bb->max.y + _pos.y &&
				bb->min.z + pos.z <= _bb->min.z + _pos.z && bb->max.z + pos.z >= _bb->max.z + _pos.y)
			{
				cout << (int)object->tag << "\n";
				eventfunc(object);
			}
		}
	}


	// �ʿ��� ��� �Լ��� ���� �� ���� �ϼŵ� �˴ϴ�.
};