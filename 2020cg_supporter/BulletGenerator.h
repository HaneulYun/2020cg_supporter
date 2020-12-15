#pragma once

class BulletGenerator : public Component
{
private /*이 영역에 private 변수를 선언하세요.*/:
	Mesh* mesh = nullptr;
	Transform* createloca = nullptr;
	Transform* transform = nullptr;
	Material* material2 = new Material();

public  /*이 영역에 public 변수를 선언하세요.*/:

protected:
	friend class GameObject;
	BulletGenerator() = default;
	BulletGenerator(BulletGenerator&) = default;

public:
	~BulletGenerator() {}

	void Start(/*초기화 코드를 작성하세요.*/)
	{
		createloca = gameObject->GetParent()->GetComponent<Transform>();
		transform = gameObject->GetComponent<Transform>();

		mesh = new Mesh();
		mesh->ReadObj("Models/bullet.obj");
		mesh->Init();

		material2->LoadDiffuseMap("Models/Bullet_Base_Coler.dds");
	}

	void Update(/*업데이트 코드를 작성하세요.*/)
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

	// 필요한 경우 함수를 선언 및 정의 하셔도 됩니다.
};
