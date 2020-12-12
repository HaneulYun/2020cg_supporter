#pragma once

class Controller : public Component
{
private /*�� ������ private ������ �����ϼ���.*/:

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
			transnform->position -= transnform->right * 0.1f;
		if (Input::GetKey(KeyCode::D))
			transnform->position += transnform->right * 0.1f;

		if (Input::GetKey(KeyCode::W))
			transnform->position -= transnform->backword * 0.1f;
		if (Input::GetKey(KeyCode::S))
			transnform->position += transnform->backword * 0.1f;
	}

	// �ʿ��� ��� �Լ��� ���� �� ���� �ϼŵ� �˴ϴ�.
};
