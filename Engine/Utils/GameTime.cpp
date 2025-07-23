#include "pch.h"
#include "GameTime.h"

void GameTime::InitTime()
{
    QueryPerformanceFrequency(&freq); // QPC ���ļ�(�ʴ� Tick ��) ��������
    QueryPerformanceCounter(&start);
    QueryPerformanceCounter(&prev);

    deltaTime = 0;
    timeElapsed = 0;
}

void GameTime::UpdateTime()
{
    QueryPerformanceCounter(&curr);
    deltaTime = static_cast<float>(curr.QuadPart - prev.QuadPart) / freq.QuadPart;
    prev = curr;
}

float GameTime::GetDeltaTime()
{
    return deltaTime;
}

float GameTime::GetFixedDeltaTime()
{
    return 1.0f / 60.0f; // 0.016s, 60FPS �����ð� ��ȯ
}

float GameTime::GetElapsedTime()
{
    QueryPerformanceCounter(&end);
    return static_cast<float>(end.QuadPart - start.QuadPart) / freq.QuadPart;
}