#pragma once

class Log : public Component
{
private /*이 영역에 private 변수를 선언하세요.*/:
	Transform* transform = nullptr;
public  /*이 영역에 public 변수를 선언하세요.*/:

protected:
	friend class GameObject;
	Log() = default;
	Log(Log&) = default;

public:
	~Log() {}

	void Start(/*초기화 코드를 작성하세요.*/)
	{
		transform = gameObject->GetComponent<Transform>();
	}

	void Update(/*업데이트 코드를 작성하세요.*/)
	{
		cout << "x : " << transform->position.x << " y : " << transform->position.y << " z : " << transform->position.z << "\n";
	}

	// 필요한 경우 함수를 선언 및 정의 하셔도 됩니다.
};