#pragma once

class Controller : public Component
{
private /*�� ������ private ������ �����ϼ���.*/:
	float speed = 10.0f;

public  /*�� ������ public ������ �����ϼ���.*/:

protected:
	friend class GameObject;
	Controller() = default;
	Controller(Controller&) = default;

public:
	~Controller() {}

	void Start(/*�ʱ�ȭ �ڵ带 �ۼ��ϼ���.*/)
	{
	}

	void Update(/*������Ʈ �ڵ带 �ۼ��ϼ���.*/)
	{
		auto transnform = gameObject->GetComponent<Transform>();

		if (Input::GetKey(KeyCode::A))
			transnform->position -= transnform->right * speed * Time::deltaTime;
		if (Input::GetKey(KeyCode::D))
			transnform->position += transnform->right * speed * Time::deltaTime;

		if (Input::GetKey(KeyCode::W))
			transnform->position -= transnform->backword * speed * Time::deltaTime;
		if (Input::GetKey(KeyCode::S))
			transnform->position += transnform->backword * speed * Time::deltaTime;
	}

	// �ʿ��� ��� �Լ��� ���� �� ���� �ϼŵ� �˴ϴ�.
};
