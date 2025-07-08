#include "Scene.h"

void Scene::OnEnter()
{
	isSceneChanging = false;
	OnEnterImpl();
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
	isSceneChanging = true;
}

void Scene::Update()
{
	AddCreatedObjects();
	if (isSceneChanging) return;

	UpdateActiveObjects();
	if (isSceneChanging) return;

	UpdateImpl();
	if (isSceneChanging) return;

	// CleanupDestroyedObjects();
}

void Scene::AddGameObject(GameObject* gameObject)
{
	objectsToAdd.push_back(gameObject);
	gameObject->SetQueryInterface(this);
}

void Scene::AddGameObject(GameObject* gameObject, const std::string& name)
{
	objectsToAdd.push_back(gameObject);
	gameObject->SetName(name);
	gameObject->SetQueryInterface(this);
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
			if (isSceneChanging) break;

			obj->Update();
		}
	}
}
