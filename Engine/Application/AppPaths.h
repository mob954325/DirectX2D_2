#pragma once
#include "pch.h"
#include "Utils/Singleton.h"

/// <summary>
/// 각종 경로 저장용 싱글톤
/// </summary>
class AppPaths : public Singleton<AppPaths>
{
public:
	AppPaths() {};
	//~AppPaths() {};

	// Application::Initialize에서 초기화
	void InitPaths();
private:
	std::wstring ModulePath {};
	std::wstring WorkingPath {};
};