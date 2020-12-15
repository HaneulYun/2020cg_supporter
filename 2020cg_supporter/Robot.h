#pragma once

class Robot : public Component
{
private /*�� ������ private ������ �����ϼ���.*/:
	bool isHit = false;

	Renderer* renderer = nullptr;
	Material* normalMa = new Material();
	Material* hitMa = new Material();
	Transform* transform;
	Transform tempTrans;

	float RobotTime = 0;
public  /*�� ������ public ������ �����ϼ���.*/:

protected:
	friend class GameObject;
	Robot() = default;
	Robot(Robot&) = default;

public:
	~Robot() {}

	void Start(/*�ʱ�ȭ �ڵ带 �ۼ��ϼ���.*/)
	{
		renderer = gameObject->GetComponent<Renderer>();
		transform = gameObject->GetComponent<Transform>();

		normalMa->LoadDiffuseMap("Models/Robot_Base_Color.dds");
		normalMa->LoadNormalMap("Models/Robot_Normal.dds");

		hitMa->LoadDiffuseMap("Models/Robothit_Base_Color.dds");
		hitMa->LoadNormalMap("Models/Robot_Normal.dds");

		renderer->material = normalMa;
	}

	void Update(/*������Ʈ �ڵ带 �ۼ��ϼ���.*/)	
	{
		if (isHit)
		{
			RobotTime += Time::deltaTime;
			transform->Scale(1.0f + 0.01f);

			if (RobotTime < 0.05f) return;

			*transform = tempTrans;

			renderer->material = normalMa;
			isHit = false;
			RobotTime = 0;
		}
	}

	void OnCollision(GameObject* _rhs)
	{
		if (_rhs->tag != Tag::Bullet) return;

		if (RobotTime)
			*transform = tempTrans;
		tempTrans = *transform;
		renderer->material = hitMa;
		isHit = true;
	}

	// �ʿ��� ��� �Լ��� ���� �� ���� �ϼŵ� �˴ϴ�.
};
