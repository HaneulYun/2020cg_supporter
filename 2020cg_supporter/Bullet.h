#pragma once

class Bullet : public Component
{
private /*�� ������ private ������ �����ϼ���.*/:
	float speed = 100;

public  /*�� ������ public ������ �����ϼ���.*/:

protected:
	friend class GameObject;
	Bullet() = default;
	Bullet(Bullet&) = default;

public:
	~Bullet() {}

	void Start(/*�ʱ�ȭ �ڵ带 �ۼ��ϼ���.*/)
	{
	}

	void Update(/*������Ʈ �ڵ带 �ۼ��ϼ���.*/)
	{
		auto transnform = gameObject->GetComponent<Transform>();

		transnform->position -= transnform->backword * speed * Time::deltaTime;
	}

	// �ʿ��� ��� �Լ��� ���� �� ���� �ϼŵ� �˴ϴ�.
};