#include "pch.h"
#include "Time.h"

float Time::deltaTime = 0.0f;

void Time::CalDeltaTime()
{
	deltaTime = std::chrono::duration<float>(mCurTime - mPreTime).count();

	cout << deltaTime << "\n ";
}

void Time::SetCurTime()
{
	mCurTime = std::chrono::system_clock::now();
}

void Time::SetPreTime()
{
	mPreTime = std::chrono::system_clock::now();
}

void Time::Update()
{
	SetCurTime();

	CalDeltaTime();

	SetPreTime();
}