#pragma once

class Gravity : public Component
{
private /*�� ������ private ������ �����ϼ���.*/:
	Transform* transform = nullptr;

	float velocity = 0;
	float accel = 0.25f;

public  /*�� ������ public ������ �����ϼ���.*/:

protected:
	friend class GameObject;
	Gravity() = default;
	Gravity(Gravity&) = default;

public:
	~Gravity() {}

	void Start(/*�ʱ�ȭ �ڵ带 �ۼ��ϼ���.*/)
	{
		transform = gameObject->GetComponent<Transform>();
	}

	void Update(/*������Ʈ �ڵ带 �ۼ��ϼ���.*/)
	{
		if (transform->position.y > 2)
		{
			velocity += accel;
			transform->position.y -= velocity * Time::deltaTime;
		}
		else 
		{
			transform->position.y = 2;
			velocity = 0;

			auto controller = gameObject->GetComponent<Controller>();
			if (controller)
			{
				controller->isJump = false;
			}
		}
	}

	// �ʿ��� ��� �Լ��� ���� �� ���� �ϼŵ� �˴ϴ�.
};