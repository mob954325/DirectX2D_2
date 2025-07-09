#include "SceneManager.h"
#include "Systems/ScriptSystem.h"
#include "Systems/RenderSystem.h"
#include "Systems/TransformSystem.h"
#include "Components/Camera/CameraManager.h"

SceneManager::~SceneManager()
{
	cameras.clear();
}

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
		cameras.clear();
		Singleton<ScriptSystem>::GetInstance().ClearAll();
		Singleton<RenderSystem>::GetInstance().ClearAll();
		Singleton<TransformSystem>::GetInstance().ClearAll();
		Singleton<CameraManager>::GetInstance().ClearAll();
	}

	// 씬 교체
	std::map<int, Scene*>::iterator it = scenes.find(sceneIndex);

	int nextSceneIndex = it->first;
	Scene* nextScene = it->second;

	currentScene = nextScene;
	currentSceneIndex = nextSceneIndex;

	Singleton<RenderSystem>::GetInstance().InitializeRenderLayers();
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

/// <summary>
/// 메인 카메라 반환 함수 ( 만약 isMainCamera가 여러개 카메라에 true로 되어있으면 가장 먼저 찾은 카메라 반환, 없으면 nullptr 반환 )
/// </summary>
/// <returns></returns>
Camera* SceneManager::GetMainCamera()
{
	for (Camera* cam : cameras)
	{
		if (cam->IsMainCamera())
		{
			return cam; // note : 볼 카메라 분리하기 
		}
	}

	return nullptr;
}

void SceneManager::AddCamera(Camera* pCamera)
{
	cameras.push_back(pCamera);
}