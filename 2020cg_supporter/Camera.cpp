#include "pch.h"
#include "Camera.h"

void Camera::Start()
{
	proj = glm::perspective(glm::radians(FOV), (float)500 / (float)500, Near, Far);
	//glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 100.0f); // ���� ��ǥ�� ǥ��
}

void Camera::Update()
{
	auto transform = gameObject->GetComponent<Transform>();

	if (transform)
		view = glm::lookAt(glm::vec3{ transform->position.x, transform->position.y + 1, transform->position.z + 3 },
			glm::vec3{ transform->position.x, transform->position.y + 1, transform->position.z + 3 } + transform->Forward(),
			glm::vec3(0, 1, 0));
}