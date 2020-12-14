#pragma once

class Camera : public Component
{
private:
	float Near{ 0.3 };
	float Far{ 1000 };
	float FOV{ 60 };

public:
	glm::mat4 proj;
	glm::mat4 projmat;
	glm::mat4 view;

	void Start();
	void Update();

	glm::mat4 getProj();
};
