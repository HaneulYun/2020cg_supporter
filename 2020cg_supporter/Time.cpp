#include "pch.h"
#include "Time.h"

float Time::deltaTime = 0.0f;

void Time::Update()
{
	curTime = GetTickCount64();

	deltaTime = (curTime - oldTime) * 0.001f;

	oldTime = curTime;
}
