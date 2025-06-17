#pragma once
#include "ScriptSystem.h"
#include "RenderSystem.h"
#include "Utility/Singleton.h"
#include "Scene.h"
#include <map>

class SceneManager : public Singleton<SceneManager>
{
public:
	void Update();
	void ChangeScene(int sceneIndex);
	void AddScene(Scene* pScene);

	Scene* GetCurrentScene();

private:
	std::map<int, Scene*> scenes; // sceneIndex, Scene

	Scene* currentScene = nullptr;
	int currentSceneIndex = -1;
	int sceneCount = 0;
};