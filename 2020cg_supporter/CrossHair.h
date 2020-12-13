#pragma once

class CrossHair : public Component
{
private /*�� ������ private ������ �����ϼ���.*/:
	Camera* camera;

	Mesh* vertiMesh;
	Mesh* HoriMesh;

	Transform* verti;
	Transform* Hori;

public  /*�� ������ public ������ �����ϼ���.*/:

protected:
	friend class GameObject;
	CrossHair() = default;
	CrossHair(CrossHair&) = default;

public:
	~CrossHair() {}

	void Start(/*�ʱ�ȭ �ڵ带 �ۼ��ϼ���.*/)
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

	void Update(/*������Ʈ �ڵ带 �ۼ��ϼ���.*/)
	{
		verti->locatToWorldMatrix = camera->view;
		Hori->locatToWorldMatrix = camera->view;
	}

	// �ʿ��� ��� �Լ��� ���� �� ���� �ϼŵ� �˴ϴ�.
};