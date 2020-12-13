#pragma once

class BulletGenerator : public Component
{
private /*�� ������ private ������ �����ϼ���.*/:
	Mesh* mesh = nullptr;
	Transform* transform = nullptr;

public  /*�� ������ public ������ �����ϼ���.*/:

protected:
	friend class GameObject;
	BulletGenerator() = default;
	BulletGenerator(BulletGenerator&) = default;

public:
	~BulletGenerator() {}

	void Start(/*�ʱ�ȭ �ڵ带 �ۼ��ϼ���.*/)
	{
		transform = gameObject->GetComponent<Transform>();

		mesh = new Mesh();
		mesh->ReadObj("Models/box.obj");
		mesh->Init();
	}

	void Update(/*������Ʈ �ڵ带 �ۼ��ϼ���.*/)
	{
		if (!Input::Instance()->GetMouseButtonDown(MouseCode::Left))
			return;

		{
			auto bullet = gameObject->scene->CreateEmpty();
			auto bulletMat = bullet->AddComponent<Transform>()->locatToWorldMatrix = transform->locatToWorldMatrix;

			auto trans = glm::translate(glm::mat4(1.0f), glm::vec3(0, -1, 0));
			auto scale = glm::scale(glm::mat4(1.0f), glm::vec3(0.1, 0.1, 0.1));

			bullet->GetComponent<Transform>()->locatToWorldMatrix *= scale * trans;
			bullet->AddComponent<MeshFilter>()->mesh = mesh;
			bullet->AddComponent<Renderer>()->shader = gameObject->GetComponent<Renderer>()->shader;
			bullet->GetComponent<Renderer>()->material = nullptr;
			bullet->AddComponent<Bullet>();
		}
	}

	// �ʿ��� ��� �Լ��� ���� �� ���� �ϼŵ� �˴ϴ�.
};
