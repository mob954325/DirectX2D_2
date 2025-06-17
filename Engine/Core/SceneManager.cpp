#include "SceneManager.h"
#include "SystemManager.h"

void SceneManager::Update()
{
	if (currentScene != nullptr)
	{
		currentScene->Update();
	}
}

void SceneManager::ChangeScene(int sceneIndex)
{
	if (sceneIndex < 0 || sceneIndex >= sceneCount)
	{
		// sceneIndex를 키로 가지는 Scene*이 scenes에 존재하지 않음 
		return;
	}

	// 현재 씬 종료
	if (currentScene != nullptr)
	{
		currentScene->OnExit();
		Singleton<SystemManager>::GetInstance().ClearAllSystem();
	}

	// 씬 교체
	std::map<int, Scene*>::iterator it = scenes.find(sceneIndex);

	int nextSceneIndex = it->first;
	Scene* nextScene = it->second;

	currentScene = nextScene;
	currentSceneIndex = nextSceneIndex;

	currentScene->OnEnter();
}

void SceneManager::AddScene(Scene* pScene)
{
	scenes.emplace(sceneCount, pScene);
	sceneCount++;
}

Scene* SceneManager::GetCurrentScene()
{
	return currentScene;
}