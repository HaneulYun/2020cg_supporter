#pragma once

class Gravity : public Component
{
private /*이 영역에 private 변수를 선언하세요.*/:
	Transform* transform = nullptr;

	float velocity = 0;
	float accel = 0.5f;

	float ground = 2;

public  /*이 영역에 public 변수를 선언하세요.*/:

protected:
	friend class GameObject;
	Gravity() = default;
	Gravity(Gravity&) = default;

public:
	~Gravity() {}

	void Start(/*초기화 코드를 작성하세요.*/)
	{
		transform = gameObject->GetComponent<Transform>();
	}

	void Update(/*업데이트 코드를 작성하세요.*/)
	{
		if (transform->position.y > ground)
		{
			velocity += accel;
			transform->position.y -= velocity * Time::deltaTime;
		}
		else 
		{
			transform->position.y = ground;
			velocity = 0;

			auto controller = gameObject->GetComponent<Controller>();
			if (controller)
			{
				controller->isJump = false;
			}
		}
	}

	// 필요한 경우 함수를 선언 및 정의 하셔도 됩니다.
};