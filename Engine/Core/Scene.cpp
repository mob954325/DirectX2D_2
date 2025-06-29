#include "Scene.h"

void Scene::OnEnter()
{
	OnEnterImpl();
}

void Scene::OnExit()
{
	OnExitImpl();

	for (GameObject* obj : gameObjects)
	{
		obj->OnDestroy();		
		delete obj;
	}

	gameObjects.clear();
}

void Scene::Update()
{
	AddCreatedObjects();

	for (GameObject* obj : gameObjects)
	{
		if(!obj->GetEarlyCreatedFlag())obj->Update();
	}

	UpdateImpl();

	DestroyGameObjects();
}

void Scene::AddGameObject(GameObject* gameObject)
{
	pendingObjects.push_back(gameObject);
}

void Scene::FindRemoveObject()
{
	std::vector<GameObject*>::iterator it = gameObjects.begin();

	for (; it != gameObjects.end(); it++)
	{
		if ((*it)->GetRemoveFlag()) // 제거할 오브젝트 찾음
		{
			destroyList.push_back(*it);
		}
	}
}

void Scene::DestroyGameObjects()
{
	FindRemoveObject();

	for (GameObject* targetObject : destroyList)
	{
		auto it = std::find(gameObjects.begin(), gameObjects.end(), targetObject);
		if (it != gameObjects.end())
		{
			GameObject* obj = *it;
			obj->OnDestroy();
			gameObjects.erase(it); // 먼저 erase
			delete obj;            // 그 다음 delete
		}
	}
	destroyList.clear();
}

void Scene::AddCreatedObjects()
{
	for (GameObject* obj : pendingObjects)
	{
		gameObjects.push_back(obj);
		obj->SetEarlyCreatedFalse();
		obj->Start();
	}

	pendingObjects.clear();
}
