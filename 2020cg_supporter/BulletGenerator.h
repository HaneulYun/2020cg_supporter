#pragma once

class BulletGenerator : public Component
{
private /*�� ������ private ������ �����ϼ���.*/:
	Mesh* mesh = nullptr;
	Transform* createloca = nullptr;
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
		createloca = gameObject->GetParent()->GetComponent<Transform>();
		transform = gameObject->GetComponent<Transform>();

		mesh = new Mesh();
		mesh->ReadObj("Models/bullet.obj");
		mesh->Init();

		material2->LoadDiffuseMap("Models/Bullet_Base_Coler.dds");
	}

	void Update(/*������Ʈ �ڵ带 �ۼ��ϼ���.*/)
	{
		if (!Input::Instance()->GetMouseButtonDown(MouseCode::Left))
		{
			transform->position = glm::vec3(0.5, -0.7, -0.3);
			return;
		}

		{
			auto bullet = gameObject->scene->CreateEmpty();
			bullet->tag = Tag::Bullet;
			auto bulletMat = bullet->AddComponent<Transform>()->locatToWorldMatrix = createloca->locatToWorldMatrix;

			auto trans = glm::translate(glm::mat4(1.0f), glm::vec3(0.2, -0.1, 0));

			bullet->GetComponent<Transform>()->locatToWorldMatrix *= trans;
			bullet->AddComponent<MeshFilter>()->mesh = mesh;
			bullet->AddComponent<Renderer>()->shader = gameObject->GetComponent<Renderer>()->shader;
			bullet->GetComponent<Renderer>()->material = material2;
			bullet->AddComponent<Bullet>();
			bullet->AddComponent<BoundingBox>();
			bullet->AddComponent<Collider<Bullet>>()->eventfunc = &Bullet::OnCollision;

			transform->position = glm::vec3(0.5, -0.7, -0.2);
		}
	}

	// �ʿ��� ��� �Լ��� ���� �� ���� �ϼŵ� �˴ϴ�.
};
