#pragma once
#include "Core/ScriptSystem.h"
#include "Core/RenderSystem.h"
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
	~SceneManager();

	void Update();
	void ChangeScene(int sceneIndex);
	void AddScene(Scene* pScene);
	Scene* GetCurrentScene();

	Camera* GetMainCamera();
	void AddCamera(Camera* pCamera);
private:
	std::map<int, Scene*> scenes; // sceneIndex, Scene
	std::vector<Camera*> cameras; // 카메라 참조만해서 사용 -> 원본은 현재 씬에 존재

	Scene* currentScene = nullptr;
	int currentSceneIndex = -1;
	int sceneCount = 0;
};