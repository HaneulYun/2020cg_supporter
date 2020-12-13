#pragma once

class Camera : public Component
{
private:
	float Near{ 0.3 };
	float Far{ 1000 };
	float FOV{ 60 };

	float yaw = -90;
	float pitch = 0;

	float sensitivity = 0.05f;

	void LookAround();
public:
	glm::mat4 proj;
	glm::mat4 view;
	
	glm::vec3 direction;

	void Start();
	void Update();
};
