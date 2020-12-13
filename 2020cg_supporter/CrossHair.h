#pragma once

class CrossHair : public Component
{
private /*이 영역에 private 변수를 선언하세요.*/:
	Camera* camera;

	Mesh* vertiMesh;
	Mesh* HoriMesh;

	Transform* verti;
	Transform* Hori;

public  /*이 영역에 public 변수를 선언하세요.*/:

protected:
	friend class GameObject;
	CrossHair() = default;
	CrossHair(CrossHair&) = default;

public:
	~CrossHair() {}

	void Start(/*초기화 코드를 작성하세요.*/)
	{
		camera = gameObject->GetComponent<Camera>();
		
		vertiMesh = new Mesh();
		vertiMesh->vertices =
		{
			{0.0, 0.1, 0.0 },
			{0.0, -0.1, 0.0},
			{0.0, 0.1, 0.0}
		};

		HoriMesh = new Mesh();
		HoriMesh->vertices =
		{
			{0.1, 0.0, 0.0 },
			{-0.1, -0.0, 0.0},
			{0.1, -0.0, 0.0}
		};

		auto shader = gameObject->GetComponent<Renderer>()->shader;

		auto vertiob = gameObject->scene->CreateEmpty();
		verti = vertiob->AddComponent<Transform>();
		verti->locatToWorldMatrix = camera->view;
		vertiob->AddComponent<MeshFilter>()->mesh = vertiMesh;
		vertiob->AddComponent<Renderer>()->shader = shader;
		vertiob->GetComponent<Renderer>()->material = nullptr;

		auto Horiob = gameObject->scene->CreateEmpty();
		Hori = Horiob->AddComponent<Transform>();
		Hori->locatToWorldMatrix = camera->view;
		Horiob->AddComponent<MeshFilter>()->mesh = HoriMesh;
		Horiob->AddComponent<Renderer>()->shader = shader;
		Horiob->GetComponent<Renderer>()->material = nullptr;
	}

	void Update(/*업데이트 코드를 작성하세요.*/)
	{
		verti->locatToWorldMatrix = camera->view;
		Hori->locatToWorldMatrix = camera->view;
	}

	// 필요한 경우 함수를 선언 및 정의 하셔도 됩니다.
};