#include "Sun2.h"
#include "Sun.h"
#include "Utility/Singleton.h"
#include "Utility/SceneManager.h"
#include <random>

#include "Utility/DebugUtility.h"


void Sun2::Start()
{
	bitmapRenderer = AddComponent<BitmapRenderer>();
	input = AddComponent<InputSystem>();

	DebugUtility::Print(L"Sun2 Create");
	Singleton<DebugUtility>::GetInstance().PrintMemoryUsage();
}

void Sun2::Update()
{
	if (input->IsKeyDown('O'))
	{
		GameObject* obj = new Sun();
		objects.push_back(obj);

		int randX = rand() % 1000;
		int randY = rand() % 600;
		obj->transform->SetPosition((float)randX, (float)randY);
		Singleton<SceneManager>::GetInstance().GetCurrentScene()->AddGameObject(obj);

		Singleton<DebugUtility>::GetInstance().PrintMemoryUsage();
	}

	if (input->IsKeyDown('P'))
	{
		// remove
		if (!objects.empty())
		{
			auto it = --objects.end();
			(*it)->MarkForRemoval();
			objects.erase(it);
		}
	}
}

void Sun2::OnDestroy()
{
}
