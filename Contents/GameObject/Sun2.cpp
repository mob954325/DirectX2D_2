#include "Sun2.h"
#include "Sun.h"
#include "Utility/Singleton.h"
#include "Utility/SceneManager.h"
#include <random>


void Sun2::Start()
{
	bitmapRenderer = AddComponent<BitmapRenderer>();
	bitmapRenderer->CreateBitmapResource(L"../Resource/Sun.png");

	transform->SetScale(0.1f, 0.1f);
	transform->SetIsUnityCoords(true);
	bitmapRenderer->SetOffSet(-512, 512);

	float randX = rand() % 1000;
	float randY = rand() % 600;
	transform->SetPosition(randX, randY);

	input = AddComponent<InputSystem>();
}

void Sun2::Update()
{
	if (input->IsKeyDown('O'))
	{
		GameObject* obj = new Sun();
		objects.push_back(obj);

		float randX = rand() % 1000;
		float randY = rand() % 600;
		obj->transform->SetPosition(randX, randY);
		Singleton<SceneManager>::GetInstance().GetCurrentScene()->AddGameObject(obj);
	}

	if (input->IsKeyDown('P'))
	{
		// remove
		if (!objects.empty())
		{
			auto it = --objects.end();
			(*it)->SetDestroy();
			objects.erase(it);
		}
	}
}

void Sun2::OnDestroy()
{
}
