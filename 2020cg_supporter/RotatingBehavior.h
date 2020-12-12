#pragma once

class RotatingBehavior : public Component
{
private /*�� ������ private ������ �����ϼ���.*/:

public  /*�� ������ public ������ �����ϼ���.*/:

protected:
	friend class GameObject;
	RotatingBehavior() = default;
	RotatingBehavior(RotatingBehavior&) = default;

public:
	~RotatingBehavior() {}

	void Start(/*�ʱ�ȭ �ڵ带 �ۼ��ϼ���.*/)
	{
	}

	void Update(/*������Ʈ �ڵ带 �ۼ��ϼ���.*/)
	{
		gameObject->GetComponent<Transform>()->locatToWorldMatrix = glm::rotate(gameObject->GetComponent<Transform>()->locatToWorldMatrix, 0.005f, glm::vec3{ 0, 1, 0 });
	}

	// �ʿ��� ��� �Լ��� ���� �� ���� �ϼŵ� �˴ϴ�.
};