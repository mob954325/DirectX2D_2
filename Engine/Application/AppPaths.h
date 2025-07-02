#pragma once
#include "pch.h"
#include "Utils/Singleton.h"

/// <summary>
/// 각종 경로 저장용 싱글톤
/// </summary>
class AppPaths : public Singleton<AppPaths>
{
private:
	std::wstring ModulePath{};
	std::wstring WorkingPath{};

public:
	// Application::Initialize에서 초기화
	void InitPaths();
	const std::wstring GetModulePath() { return ModulePath; }
	const std::wstring GetWorkingPath() { return WorkingPath; }
};