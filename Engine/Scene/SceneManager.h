#pragma once
#include "Systems/ScriptSystem.h"
#include "Systems/RenderSystem.h"
#include "Utils/Singleton.h"
#include "Scene/Scene.h"
#include "Components/Camera/Camera.h"
#include <map>
#include <vector>

/// <summary>
/// 모든 씬 관리 클래스
/// </summary>
/// <remarks>
/// 카메라 관리함수, Screen 크기값 포함됨
/// </remarks>
class SceneManager : public Singleton<SceneManager>
{
public:
	friend class Singleton<SceneManager>;

	void Init();
	void Update();
	void LoadScene(int sceneIndex);
	void CheckSceneLoad();
	void AddScene(Scene* pScene);
	Scene* GetCurrentScene();

private:
	SceneManager() = default;
	~SceneManager();

	std::map<int, Scene*> scenes; // sceneIndex, Scene

	Scene* currentScene = nullptr;
	int currentSceneIndex = -1;
	int targetSceneIndex = -1; // 변경할 목표 씬 인덱스
	int sceneCount = 0;
};