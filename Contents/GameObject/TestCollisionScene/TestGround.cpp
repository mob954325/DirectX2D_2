#include "TestGround.h"
#include "Scene/SceneManager.h"

void TestGround::Start()
{
	aabb = AddComponent<AABBCollider>();
	aabb->SetSize(1024, 50, 1);

	box = AddComponent<BoxComponent>();
	box->SetIsShow(true);
	box->SetRect({ -1024 / 2, -50 / 2, 1024 / 2, 50 / 2});
	box->SetWidth(2.0f);
	inputSystem = AddComponent<InputSystem>();
}

void TestGround::Update()
{
	if (inputSystem->IsKeyPressed('X'))
	{
		Singleton<SceneManager>::GetInstance().ChangeScene(0);
	}

	if (inputSystem->IsKeyPressed('Z'))
	{
		Singleton<SceneManager>::GetInstance().ChangeScene(1);
	}
}

void TestGround::OnDestroy()
{
}
