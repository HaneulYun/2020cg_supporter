#pragma once

class CrossHair : public Component
{
private /*�� ������ private ������ �����ϼ���.*/:
	Camera* camera;
	Mesh* vertiMesh;
	Mesh* HoriMesh;

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
		vertiMesh->vertices 

		HoriMesh = new Mesh();
	}

	void Update(/*������Ʈ �ڵ带 �ۼ��ϼ���.*/)
	{

	}

	// �ʿ��� ��� �Լ��� ���� �� ���� �ϼŵ� �˴ϴ�.
};