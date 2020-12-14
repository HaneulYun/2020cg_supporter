#pragma once

class Gravity : public Component
{
private /*�� ������ private ������ �����ϼ���.*/:
	Transform* transform = nullptr;

	float velocity = 0;
	float accel = 0.5f;

	float ground = 2;

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

	// �ʿ��� ��� �Լ��� ���� �� ���� �ϼŵ� �˴ϴ�.
};