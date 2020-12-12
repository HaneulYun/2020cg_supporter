#pragma once

class Controller : public Component
{
private /*이 영역에 private 변수를 선언하세요.*/:

public  /*이 영역에 public 변수를 선언하세요.*/:

protected:
	friend class GameObject;
	Controller() = default;
	Controller(Controller&) = default;

public:
	~Controller() {}

	void Start(/*초기화 코드를 작성하세요.*/)
	{
	}

	void Update(/*업데이트 코드를 작성하세요.*/)
	{
		auto transnform = gameObject->GetComponent<Transform>();

		if (Input::GetKey(KeyCode::A))
			transnform->position -= transnform->right * 0.1f;
		if (Input::GetKey(KeyCode::D))
			transnform->position += transnform->right * 0.1f;

		if (Input::GetKey(KeyCode::W))
			transnform->position -= transnform->backword * 0.1f;
		if (Input::GetKey(KeyCode::S))
			transnform->position += transnform->backword * 0.1f;
	}

	// 필요한 경우 함수를 선언 및 정의 하셔도 됩니다.
};
