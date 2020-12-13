#pragma once

class Transform : public Component
{
public:
	union
	{
		glm::mat4 locatToWorldMatrix = glm::mat4(1.0f);
		glm::mat4 locatToParentMatrix;
		struct
		{
			glm::vec3 right;	float _00; 
			glm::vec3 up;		float _01; 
			glm::vec3 backword;	float _02; 
			glm::vec3 position;	float _03;
		};
	};

	glm::vec3 Forward()
	{
		return -backword;
	}

	glm::mat4 Scale(glm::vec3 vec)
	{
		return locatToWorldMatrix =  glm::scale(locatToWorldMatrix, vec);
	}
};
