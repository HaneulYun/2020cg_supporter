#pragma once

class Time : public Singleton<Time>
{
private:
	std::chrono::system_clock::time_point mCurTime;
	std::chrono::system_clock::time_point mPreTime;

	void CalDeltaTime();
	void SetCurTime();
	void SetPreTime();
public:
	static float deltaTime;

public:
	void Update();

	float GetDeltaTime();
};
