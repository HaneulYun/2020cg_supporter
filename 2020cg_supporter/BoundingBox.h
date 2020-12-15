#pragma once

class BoundingBox : public Component
{
private /*�� ������ private ������ �����ϼ���.*/:
	bool isSetting = false;

public  /*�� ������ public ������ �����ϼ���.*/:
	glm::vec3 min;
	glm::vec3 max;

protected:
	friend class GameObject;
	BoundingBox() = default;
	BoundingBox(BoundingBox&) = default;

public:
	~BoundingBox() {}

	void Start(/*�ʱ�ȭ �ڵ带 �ۼ��ϼ���.*/)
	{
		if(isSetting) return;
		auto meshfilter = gameObject->GetComponent<MeshFilter>();

		if (meshfilter == nullptr) return;

		auto mesh = meshfilter->mesh;

		if (mesh == nullptr) return;

		SetBoundingBox(glm::vec3(mesh->width[0], mesh->height[0], mesh->depth[0]), glm::vec3(mesh->width[1], mesh->height[1], mesh->depth[1]));

		//cout << "Tag : " << (int)gameObject->tag << " Min x: " << min.x << " Max x: " << max.x;
		//cout << " Min y: " << min.y << " Max y: " << max.y << " Min z: " << min.z << " Max z: " << max.z << "\n";
	}

	void Update(/*������Ʈ �ڵ带 �ۼ��ϼ���.*/)
	{
	}

	void SetBoundingBox(glm::vec3 _min, glm::vec3 _max)
	{
		min = _min;
		max = _max;

		if (max.y - min.y <= 0.01f) min.y -= 0.01f;

		isSetting = true;
	}

	// �ʿ��� ��� �Լ��� ���� �� ���� �ϼŵ� �˴ϴ�.
};