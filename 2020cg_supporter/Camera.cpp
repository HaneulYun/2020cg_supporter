#include "pch.h"
#include "Camera.h"

void Camera::Start()
{
	proj = glm::perspective(glm::radians(FOV), (float)500 / (float)500, Near, Far);
	//glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 100.0f); // 월드 좌표로 표현
}

void Camera::Update()
{
	auto transform = gameObject->GetComponent<Transform>();
	if (transform)
		view = glm::lookAt(transform->position, transform->position + transform->Forward(), glm::vec3(0, 1, 0));
}
