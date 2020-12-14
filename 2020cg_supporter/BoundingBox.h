#pragma once

class BoundingBox : public Component
{
private /*이 영역에 private 변수를 선언하세요.*/:

public  /*이 영역에 public 변수를 선언하세요.*/:
	glm::vec3 min;
	glm::vec3 max;

protected:
	friend class GameObject;
	BoundingBox() = default;
	BoundingBox(BoundingBox&) = default;

public:
	~BoundingBox() {}

	void Start(/*초기화 코드를 작성하세요.*/)
	{
		auto mesh = gameObject->GetComponent<Mesh>();

		if (mesh == nullptr) return;

		SetBoundingBox(glm::vec3(mesh->width[0], mesh->height[0], mesh->depth[0]), glm::vec3(mesh->width[1], mesh->height[1], mesh->depth[1]));
	}

	void Update(/*업데이트 코드를 작성하세요.*/)
	{
	}

	void SetBoundingBox(glm::vec3 _min, glm::vec3 _max)
	{
		min = _min;
		max = _max;

		if (max.y - min.y <= 0.1) min.y -= 0.1;
	}

	// 필요한 경우 함수를 선언 및 정의 하셔도 됩니다.
};