#pragma once

class Log : public Component
{
private /*�� ������ private ������ �����ϼ���.*/:
	Transform* transform;
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

	}

	// �ʿ��� ��� �Լ��� ���� �� ���� �ϼŵ� �˴ϴ�.
};