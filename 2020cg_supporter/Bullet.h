#pragma once

class Bullet : public Component
{
private /*이 영역에 private 변수를 선언하세요.*/:
	float speed = 100;

public  /*이 영역에 public 변수를 선언하세요.*/:

protected:
	friend class GameObject;
	Bullet() = default;
	Bullet(Bullet&) = default;

public:
	~Bullet() {}

	void Start(/*초기화 코드를 작성하세요.*/)
	{
	}

	void Update(/*업데이트 코드를 작성하세요.*/)
	{
		auto transnform = gameObject->GetComponent<Transform>();

		transnform->position -= transnform->backword * speed * Time::deltaTime;
	}

	// 필요한 경우 함수를 선언 및 정의 하셔도 됩니다.
};