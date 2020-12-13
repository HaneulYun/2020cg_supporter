#pragma once

class BulletGenerator : public Component
{
private /*이 영역에 private 변수를 선언하세요.*/:
	Mesh* mesh = nullptr;
	Transform* transform = nullptr;

public  /*이 영역에 public 변수를 선언하세요.*/:

protected:
	friend class GameObject;
	BulletGenerator() = default;
	BulletGenerator(BulletGenerator&) = default;

public:
	~BulletGenerator() {}

	void Start(/*초기화 코드를 작성하세요.*/)
	{
		transform = gameObject->GetComponent<Transform>();

		mesh = new Mesh();
		mesh->ReadObj("Models/box.obj");
		mesh->Init();
	}

	void Update(/*업데이트 코드를 작성하세요.*/)
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

	// 필요한 경우 함수를 선언 및 정의 하셔도 됩니다.
};