#include "pch.h"
#include "Camera.h"


void Camera::Start()
{
	proj = glm::perspective(glm::radians(FOV), (float)500 / (float)500, Near, Far);
	//glm::ortho(-10.0f, 10.0f, -10.0f, 10.0f, 0.0f, 100.0f); // 월드 좌표로 표현
}

void Camera::Update()
{
	LookAround();

	direction.x = cos(glm::radians(yaw)) * cos(glm::radians(pitch));
	direction.y = sin(glm::radians(pitch));
	direction.z = sin(glm::radians(yaw)) * cos(glm::radians(pitch));
	glm::vec3 cameraFront = glm::normalize(direction);

	auto transform = gameObject->GetComponent<Transform>();

	transform->backword = -cameraFront;
	transform->right = glm::normalize(glm::cross(glm::vec3{ 0, 1, 0 }, transform->backword));
	transform->up = glm::cross(transform->backword, transform->right);

	if (transform)
		view = glm::lookAt(transform->position, transform->position + transform->Forward(), glm::vec3(0, 1, 0));
}

void Camera::LookAround()
{
	auto offset = Input::Instance()->mouseOffset;

	offset *= sensitivity;

	yaw += offset.x;
	pitch += offset.y;

	if (pitch > 89.0f)
		pitch = 89.0f;
	if (pitch < -89.0f)
		pitch = -89.0f;
}
