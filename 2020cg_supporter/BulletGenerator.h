#pragma once

class BulletGenerator : public Component
{
private /*�� ������ private ������ �����ϼ���.*/:
	Mesh* mesh = nullptr;
	Transform* transform = nullptr;
	Material* material2 = new Material();

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
		mesh->ReadObj("Models/bullet.obj");
		mesh->Init();

		material2->LoadDiffuseMap("Models/Bullet_Base_Coler.dds");
	}

	void Update(/*������Ʈ �ڵ带 �ۼ��ϼ���.*/)
	{
		if (!Input::Instance()->GetMouseButtonDown(MouseCode::Left))
			return;

		{
			auto bullet = gameObject->scene->CreateEmpty();
			auto bulletMat = bullet->AddComponent<Transform>()->locatToWorldMatrix = transform->locatToWorldMatrix;

			auto trans = glm::translate(glm::mat4(1.0f), glm::vec3(0, -0.3, 0));

			bullet->GetComponent<Transform>()->locatToWorldMatrix *= trans;
			bullet->AddComponent<MeshFilter>()->mesh = mesh;
			bullet->AddComponent<Renderer>()->shader = gameObject->GetComponent<Renderer>()->shader;
			bullet->GetComponent<Renderer>()->material = material2;
			bullet->AddComponent<Bullet>();
		}
	}

	// �ʿ��� ��� �Լ��� ���� �� ���� �ϼŵ� �˴ϴ�.
};
