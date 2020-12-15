#pragma once

class Robot : public Component
{
private /*이 영역에 private 변수를 선언하세요.*/:
	bool isHit = false;

	Renderer* renderer = nullptr;
	Material* normalMa = new Material();
	Material* hitMa = new Material();
	Transform* transform;
	Transform tempTrans;

	float RobotTime = 0;
public  /*이 영역에 public 변수를 선언하세요.*/:

protected:
	friend class GameObject;
	Robot() = default;
	Robot(Robot&) = default;

public:
	~Robot() {}

	void Start(/*초기화 코드를 작성하세요.*/)
	{
		renderer = gameObject->GetComponent<Renderer>();
		transform = gameObject->GetComponent<Transform>();

		normalMa->LoadDiffuseMap("Models/Robot_Base_Color.dds");
		normalMa->LoadNormalMap("Models/Robot_Normal.dds");

		hitMa->LoadDiffuseMap("Models/Robothit_Base_Color.dds");
		hitMa->LoadNormalMap("Models/Robot_Normal.dds");

		renderer->material = normalMa;
	}

	void Update(/*업데이트 코드를 작성하세요.*/)	
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

	// 필요한 경우 함수를 선언 및 정의 하셔도 됩니다.
};
