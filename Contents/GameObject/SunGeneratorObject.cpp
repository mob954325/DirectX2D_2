#include "SunGeneratorObject.h"
#include "Sun.h"
#include "Utility/Singleton.h"
#include "Utility/SceneManager.h"
#include <random>

#include "Utility/DebugUtility.h"

// NOTE : 0630 리소스 매니저 확인을 위한 게임오브젝트 추가
void SunGeneratorObject::Start()
{
	bitmapRenderer = AddComponent<BitmapRenderer>();
	input = AddComponent<InputSystem>();

	DebugUtility::Print(L"SunGeneratorObject Create");
	Singleton<DebugUtility>::GetInstance().PrintMemoryUsage();
}

void SunGeneratorObject::Update()
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

void SunGeneratorObject::OnDestroy()
{
}
