#pragma once

class Controller : public Component
{
private /*이 영역에 private 변수를 선언하세요.*/:
	float speed = 10.0f;

	glm::vec3 velocity = glm::vec3();
	float jumpTimer = 0.0f;	
	float jumpForce = 10.0f;

	Transform* transform = nullptr;

public  /*이 영역에 public 변수를 선언하세요.*/:
	bool isJump = false;
protected:
	friend class GameObject;
	Controller() = default;
	Controller(Controller&) = default;

public:
	~Controller() {}

	void Start(/*초기화 코드를 작성하세요.*/)
	{
		transform = gameObject->GetComponent<Transform>();
	}

	void Update(/*업데이트 코드를 작성하세요.*/)
	{
		if (Input::GetKey(KeyCode::A))
			transform->position -= transform->right * speed * Time::deltaTime;
		if (Input::GetKey(KeyCode::D))
			transform->position += transform->right * speed * Time::deltaTime;

		if (Input::GetKey(KeyCode::W))
			transform->position -= glm::normalize(glm::vec3(transform->backword.x, 0, transform->backword.z)) * speed * Time::deltaTime;
		if (Input::GetKey(KeyCode::S))
			transform->position += glm::normalize(glm::vec3(transform->backword.x, 0, transform->backword.z)) * speed * Time::deltaTime;

		if (Input::GetKey(KeyCode::SPACE) && !isJump)
			isJump = true;

		if (isJump)
			Jump();
	}

	void Jump()
	{
		velocity = glm::vec3(0, 1, 0) * jumpForce;

		transform->position += velocity * Time::deltaTime;
	}

	// 필요한 경우 함수를 선언 및 정의 하셔도 됩니다.
};
