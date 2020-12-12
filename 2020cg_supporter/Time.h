#pragma once

class Time : public Singleton<Time>
{
private:
	long long oldTime{ 0 };
	long long curTime{ 0 };

public:
	static float deltaTime;

public:
	void Update();
};
