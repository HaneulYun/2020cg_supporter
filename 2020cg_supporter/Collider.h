#pragma once

template<class T>
class Collider : public Component
{
private /*이 영역에 private 변수를 선언하세요.*/:
	Scene* scene = nullptr;
	BoundingBox* bb = nullptr;
	Transform* transform = nullptr;
public  /*이 영역에 public 변수를 선언하세요.*/:
	void(T::*eventfunc)(GameObject*) = nullptr;

protected:
	friend class GameObject;
	Collider() = default;
	Collider(Collider&) = default;

public:
	~Collider() {}

	void Start(/*초기화 코드를 작성하세요.*/)
	{
		scene = gameObject->scene;
		bb = gameObject->GetComponent<BoundingBox>();
		transform = gameObject->GetComponent<Transform>();
	}

	void Update(/*업데이트 코드를 작성하세요.*/)
	{
		if (eventfunc == nullptr)
			return;

		for (auto object : scene->GetObjects())
		{
			if (gameObject->tag == object->tag) continue;

			auto pos = transform->position;
			auto _bb = object->GetComponent<BoundingBox>();
			auto _pos = object->GetComponent<Transform>()->position;

			if (_bb == nullptr)
				continue;

			if ((bb->min.x + pos.x <= _bb->max.x + _pos.x && bb->max.x + pos.x >= _bb->min.x + _pos.x) &&
				(bb->min.y + pos.y <= _bb->max.y + _pos.y && bb->max.y + pos.y >= _bb->min.y + _pos.y) &&
				(bb->min.z + pos.z <= _bb->max.z + _pos.z && bb->max.z + pos.z >= _bb->min.z + _pos.z))
			{
				//cout << (int)object->tag << "\n";
				(gameObject->GetComponent<T>()->*eventfunc)(object);
			}
		}
	}


	// 필요한 경우 함수를 선언 및 정의 하셔도 됩니다.
};