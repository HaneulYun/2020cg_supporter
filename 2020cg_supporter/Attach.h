#pragma once

class Attach : public Component
{
private /*�� ������ private ������ �����ϼ���.*/:

public  /*�� ������ public ������ �����ϼ���.*/:
	GameObject* target = nullptr;

protected:
	friend class GameObject;
	Attach() = default;
	Attach(Attach&) = default;

public:
	~Attach() {}

	void Start(/*�ʱ�ȭ �ڵ带 �ۼ��ϼ���.*/)
	{

	}

	void Update(/*������Ʈ �ڵ带 �ۼ��ϼ���.*/)
	{
		auto transform = gameObject->GetComponent<Transform>();
		auto targetTransform = target->GetComponent<Transform>();
	}

	// �ʿ��� ��� �Լ��� ���� �� ���� �ϼŵ� �˴ϴ�.
};