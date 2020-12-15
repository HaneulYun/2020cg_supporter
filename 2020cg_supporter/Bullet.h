#pragma once

class Bullet : public Component
{
private /*�� ������ private ������ �����ϼ���.*/:
	float speed = 100;

	bool turnActive = false;

	Transform* transform = nullptr;
public  /*�� ������ public ������ �����ϼ���.*/:

protected:
	friend class GameObject;
	Bullet() = default;
	Bullet(Bullet&) = default;

public:
	~Bullet() {}

	void Start(/*�ʱ�ȭ �ڵ带 �ۼ��ϼ���.*/)
	{
		transform = gameObject->GetComponent<Transform>();
	}

	void Update(/*������Ʈ �ڵ带 �ۼ��ϼ���.*/)
	{
		if (turnActive)
		{
			gameObject->SetActive(false);
			gameObject->GetComponent<MeshFilter>()->mesh = nullptr;

			transform->position = glm::vec3(10000, 10000, 10000);
		}

		transform->position += transform->Forward() * speed * Time::deltaTime;

		if (glm::distance(glm::vec3(1.0f), transform->position) > 1000) turnActive = true;
	}

	void OnCollision(GameObject* _rhs)
	{
		turnActive = true;
	}

	// �ʿ��� ��� �Լ��� ���� �� ���� �ϼŵ� �˴ϴ�.
};