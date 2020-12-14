#pragma once

class Controller : public Component
{
private /*�� ������ private ������ �����ϼ���.*/:
	float speed = 10.0f;

	glm::vec3 velocity = glm::vec3();
	float jumpTimer = 0.0f;	
	float jumpForce = 10.0f;

	Transform* transform = nullptr;

public  /*�� ������ public ������ �����ϼ���.*/:
	bool isJump = false;
protected:
	friend class GameObject;
	Controller() = default;
	Controller(Controller&) = default;

public:
	~Controller() {}

	void Start(/*�ʱ�ȭ �ڵ带 �ۼ��ϼ���.*/)
	{
		transform = gameObject->GetComponent<Transform>();
	}

	void Update(/*������Ʈ �ڵ带 �ۼ��ϼ���.*/)
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

	// �ʿ��� ��� �Լ��� ���� �� ���� �ϼŵ� �˴ϴ�.
};
