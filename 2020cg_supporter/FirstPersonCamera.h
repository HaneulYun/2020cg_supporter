#pragma once

class FirstPersonCamera : public Component
{
private /*�� ������ private ������ �����ϼ���.*/:
	float yaw = -90;
	float pitch = 0;

	float sensitivity = 0.05f;

public  /*�� ������ public ������ �����ϼ���.*/:
	glm::vec3 direction;

protected:
	friend class GameObject;
	FirstPersonCamera() = default;
	FirstPersonCamera(FirstPersonCamera&) = default;

public:
	~FirstPersonCamera() {}

	void Start(/*�ʱ�ȭ �ڵ带 �ۼ��ϼ���.*/)
	{

	}

	void Update(/*������Ʈ �ڵ带 �ۼ��ϼ���.*/)
	{
		auto offset = Input::Instance()->mouseOffset;

		offset *= sensitivity;

		yaw += offset.x;
		pitch += offset.y;

		if (pitch > 89.0f)
			pitch = 89.0f;
		if (pitch < -89.0f)
			pitch = -89.0f;

		direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
		direction.y = sin(glm::radians(pitch));
		direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
		glm::vec3 cameraFront = glm::normalize(direction);

		auto transform = gameObject->GetComponent<Transform>();

		transform->backword = -cameraFront;
		transform->right = glm::normalize(glm::cross(glm::vec3{ 0, 1, 0 }, transform->backword));
		transform->up = glm::cross(transform->backword, transform->right);
	}

	// �ʿ��� ��� �Լ��� ���� �� ���� �ϼŵ� �˴ϴ�.
};