#include "Scene.h"
#include "Utils/Singleton.h"
#include "Systems/TransformSystem.h"

void Scene::OnEnter()
{
	state = SceneState::Enter;
	OnEnterImpl();

	state = SceneState::Playing;
}

void Scene::OnExit()
{
	OnExitImpl();

	for (GameObject* obj : activeObjects)
	{
		obj->OnDestroy();		
		delete obj;
		obj = nullptr;
	}

	activeObjects.clear();

	state = SceneState::Exit;
}

void Scene::Update()
{
	AddCreatedObjects();
	if (state == SceneState::ReadyToExit) return;

	UpdateActiveObjects();
	if (state == SceneState::ReadyToExit) return;

	UpdateImpl();
	if (state == SceneState::ReadyToExit) return;
}

void Scene::AddGameObject(GameObject* gameObject)
{
	objectsToAdd.push_back(gameObject);
	gameObject->SetQueryInterface(this);
	Singleton<TransformSystem>::GetInstance().Register(gameObject->transform); // NOTE: 0709추가 TransformSystem에 transform 추가
}

void Scene::AddGameObject(GameObject* gameObject, const std::string& name)
{
	objectsToAdd.push_back(gameObject);
	gameObject->SetName(name);
	gameObject->SetQueryInterface(this);
	Singleton<TransformSystem>::GetInstance().Register(gameObject->transform);
}

void Scene::FindRemoveObject()
{
	std::vector<GameObject*>::iterator it = activeObjects.begin();

	for (; it != activeObjects.end(); it++)
	{
		if ((*it)->IsMarkedForRemoval()) // 제거할 오브젝트 찾음
		{
			objectsToDestroy.push_back(*it);
		}
	}
}

GameObject* Scene::FindByName(const std::string& name) const 
{
	for (auto object : activeObjects)
	{
		if (name == object->GetName())
		{
			return object;
		}
	}

	return nullptr;
}

void Scene::CleanUpDestroyedObjects()
{
	FindRemoveObject();

	for (GameObject* targetObject : objectsToDestroy)
	{
		auto it = std::find(activeObjects.begin(), activeObjects.end(), targetObject);
		if (it != activeObjects.end())
		{
			GameObject* obj = *it;
			obj->OnDestroy();
			activeObjects.erase(it); // 먼저 erase
			delete obj;            // 그 다음 delete
		}
	}
	objectsToDestroy.clear();
}

void Scene::AddCreatedObjects()
{
	for (GameObject* obj : objectsToAdd)
	{
		activeObjects.push_back(obj);
		obj->SetEarlyCreated();
		obj->Start();
	}

	objectsToAdd.clear();
}

void Scene::UpdateActiveObjects()
{
	for (GameObject* obj : activeObjects)
	{
		if (!obj->IsEarlyCreated() && !obj->IsMarkedForRemoval())
		{
			// if (isSceneChanging) break;
			if (state == SceneState::ReadyToExit) break;

			obj->Update();
		}
	}
}
