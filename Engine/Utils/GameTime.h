#pragma once
#include <iostream>
#include <windows.h>
#include "Utils/Singleton.h"

class GameTime : public Singleton<GameTime>
{
public:
	void InitTime();
	void UpdateTime();
	float GetDeltaTime();
	float GetElapsedTime();

private:
	LARGE_INTEGER freq = {}, curr = {}, prev = {}, start = {}, end = {};
	float deltaTime{};
	float timeElapsed{};
};
