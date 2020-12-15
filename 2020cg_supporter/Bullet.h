#pragma once

class Bullet : public Component
{
private /*이 영역에 private 변수를 선언하세요.*/:
	float speed = 100;

	bool turnActive = false;

	Transform* transform = nullptr;
public  /*이 영역에 public 변수를 선언하세요.*/:

protected:
	friend class GameObject;
	Bullet() = default;
	Bullet(Bullet&) = default;

public:
	~Bullet() {}

	void Start(/*초기화 코드를 작성하세요.*/)
	{
		transform = gameObject->GetComponent<Transform>();
	}

	void Update(/*업데이트 코드를 작성하세요.*/)
	{
		if (turnActive)
		{
			gameObject->SetActive(false);
			gameObject->GetComponent<MeshFilter>()->mesh = nullptr;

			transform->position = glm::vec3(10000, 10000, 10000);
		}

		transform->position += transform->Forward() * speed * Time::deltaTime;

		if (glm::distance(glm::vec3(1.0f), transform->position) > 1000) turnActive = true;
	}

	void OnCollision(GameObject* _rhs)
	{
		turnActive = true;
	}

	// 필요한 경우 함수를 선언 및 정의 하셔도 됩니다.
};