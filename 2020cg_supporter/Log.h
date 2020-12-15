#pragma once

class Log : public Component
{
private /*�� ������ private ������ �����ϼ���.*/:
	Transform* transform = nullptr;
public  /*�� ������ public ������ �����ϼ���.*/:

protected:
	friend class GameObject;
	Log() = default;
	Log(Log&) = default;

public:
	~Log() {}

	void Start(/*�ʱ�ȭ �ڵ带 �ۼ��ϼ���.*/)
	{
		transform = gameObject->GetComponent<Transform>();
	}

	void Update(/*������Ʈ �ڵ带 �ۼ��ϼ���.*/)
	{
		cout << "x : " << transform->position.x << " y : " << transform->position.y << " z : " << transform->position.z << "\n";
	}

	// �ʿ��� ��� �Լ��� ���� �� ���� �ϼŵ� �˴ϴ�.
};