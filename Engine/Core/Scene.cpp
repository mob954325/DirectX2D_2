#include "Scene.h"

void Scene::OnEnter()
{
	OnEnterImpl();

	for (GameObject* obj : gameObjects)
	{
		obj->Start();
	}
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
	DestroyGameObjects();

	for (GameObject* obj : gameObjects)
	{
		obj->Update();
	}

	UpdateImpl();
}

void Scene::AddGameObject(GameObject* gameObject)
{
	// 게임오브젝트 중복 적용 방지
	for (GameObject* obj : gameObjects)
	{
		if (obj == gameObject)
		{
			// 이미 등록된 게임 오브젝트
			return;
		}
	}

	gameObjects.push_back(gameObject);
}

void Scene::RemoveObject(GameObject* gameObject)
{
	std::vector<GameObject*>::iterator it = gameObjects.begin();

	for (; it != gameObjects.end(); it++)
	{
		if (*it == gameObject) // 제거할 오브젝트 찾음
		{
			destroyList.push_back(*it);
		}
	}
}

void Scene::DestroyGameObjects()
{
	std::vector<GameObject*>::iterator it = destroyList.begin();

	for (; it != destroyList.end();)
	{
		GameObject* targetObject = *it;

		it = destroyList.erase(it);
		targetObject->OnDestroy();
		delete targetObject;
	}

	destroyList.clear();
}
