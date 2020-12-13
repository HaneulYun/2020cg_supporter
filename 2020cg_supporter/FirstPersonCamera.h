#pragma once

class FirstPersonCamera : public Component
{
private /*이 영역에 private 변수를 선언하세요.*/:
	float yaw = -90;
	float pitch = 0;

	float sensitivity = 0.05f;

public  /*이 영역에 public 변수를 선언하세요.*/:
	glm::vec3 direction;

protected:
	friend class GameObject;
	FirstPersonCamera() = default;
	FirstPersonCamera(FirstPersonCamera&) = default;

public:
	~FirstPersonCamera() {}

	void Start(/*초기화 코드를 작성하세요.*/)
	{

	}

	void Update(/*업데이트 코드를 작성하세요.*/)
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

	// 필요한 경우 함수를 선언 및 정의 하셔도 됩니다.
};