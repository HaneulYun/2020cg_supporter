#include "pch.h"
#include "Camera.h"

void Camera::Start()
{
	proj = glm::perspective(glm::radians(FOV), (float)Input::Instance()->WIDDOW_WIDTH / (float)Input::Instance()->WINDOW_HEIGHT, Near, Far);
	projmat = glm::ortho(0.0f, (float)Input::Instance()->WIDDOW_WIDTH, 0.0f, (float)Input::Instance()->WINDOW_HEIGHT, 0.1f, 100.0f);
}

void Camera::Update()
{
	auto transform = gameObject->GetComponent<Transform>();
	if (transform)
		view = glm::lookAt(transform->position, transform->position + transform->Forward(), glm::vec3(0, 1, 0));
}
