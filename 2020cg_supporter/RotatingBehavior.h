#pragma once

class RotatingBehavior : public Component
{
private /*이 영역에 private 변수를 선언하세요.*/:

public  /*이 영역에 public 변수를 선언하세요.*/:

protected:
	friend class GameObject;
	RotatingBehavior() = default;
	RotatingBehavior(RotatingBehavior&) = default;

public:
	~RotatingBehavior() {}

	void Start(/*초기화 코드를 작성하세요.*/)
	{
	}

	void Update(/*업데이트 코드를 작성하세요.*/)
	{
		gameObject->GetComponent<Transform>()->locatToWorldMatrix = glm::rotate(gameObject->GetComponent<Transform>()->locatToWorldMatrix, 0.005f, glm::vec3{ 0, 1, 0 });
	}

	// 필요한 경우 함수를 선언 및 정의 하셔도 됩니다.
};