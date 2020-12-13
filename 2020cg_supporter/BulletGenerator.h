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
			bullet->AddComponent<Transform>()->locatToWorldMatrix = transform->locatToWorldMatrix;
			bullet->GetComponent<Transform>()->position.y -= 1;
			bullet->AddComponent<MeshFilter>()->mesh = mesh;
			bullet->AddComponent<Renderer>()->shader = gameObject->GetComponent<Renderer>()->shader;
			bullet->GetComponent<Renderer>()->material = nullptr;
			bullet->AddComponent<Bullet>();
		}
	}

	// �ʿ��� ��� �Լ��� ���� �� ���� �ϼŵ� �˴ϴ�.
};