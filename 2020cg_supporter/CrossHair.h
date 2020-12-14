#pragma once

class CrossHair : public Component
{
private /*�� ������ private ������ �����ϼ���.*/:
	Camera* camera = nullptr;

	Mesh* vertiMesh = nullptr;
	Mesh* HoriMesh = nullptr;

	Transform* verti = nullptr;
	Transform* Hori = nullptr;

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
			{0.0, -0.1, 0.0}
		};
		vertiMesh->uvs =
		{
			{1.0, 1.0},
			{1.0, 1.0}
		};
		vertiMesh->Init();

		HoriMesh = new Mesh();
		HoriMesh->vertices =
		{
			{0.1, 0.0, 0.0 },
			{-0.1, 0.0, 0.0}
		};
		HoriMesh->uvs =
		{
			{1.0, 1.0},
			{1.0, 1.0}
		};
		HoriMesh->Init();

		Material* material1 = new Material();
		{
			material1->LoadDiffuseMap("Models/rifle_Base_Color.dds");
			material1->LoadNormalMap("Models/rifle_005005005_Normal.dds");
		}

		auto shader = gameObject->GetComponent<Renderer>()->shader;

		auto vertiob = gameObject->scene->CreateEmpty();
		verti = vertiob->AddComponent<Transform>();
		verti->locatToWorldMatrix = camera->view;
		vertiob->AddComponent<MeshFilter>()->mesh = vertiMesh;
		vertiob->AddComponent<Renderer>()->shader = shader;
		vertiob->GetComponent<Renderer>()->material = material1;

		auto Horiob = gameObject->scene->CreateEmpty();
		Hori = Horiob->AddComponent<Transform>();
		Hori->locatToWorldMatrix = camera->view;
		Horiob->AddComponent<MeshFilter>()->mesh = HoriMesh;
		Horiob->AddComponent<Renderer>()->shader = shader;
		Horiob->GetComponent<Renderer>()->material = material1;
	}

	void Update(/*������Ʈ �ڵ带 �ۼ��ϼ���.*/)
	{
		verti->locatToWorldMatrix = camera->view;
		Hori->locatToWorldMatrix = camera->view;
	}

	// �ʿ��� ��� �Լ��� ���� �� ���� �ϼŵ� �˴ϴ�.
};
