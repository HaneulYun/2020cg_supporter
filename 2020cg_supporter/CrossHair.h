#pragma once

class CrossHair : public Component
{
private /*이 영역에 private 변수를 선언하세요.*/:
	Camera* camera;
	Mesh* vertiMesh;
	Mesh* HoriMesh;

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
		vertiMesh->vertices 

		HoriMesh = new Mesh();
	}

	void Update(/*업데이트 코드를 작성하세요.*/)
	{

	}

	// 필요한 경우 함수를 선언 및 정의 하셔도 됩니다.
};