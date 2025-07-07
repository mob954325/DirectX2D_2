#include "SunGeneratorObject.h"
#include "Sun.h"
#include "Utils/Singleton.h"
#include "Scene/SceneManager.h"
#include <random>

#include "Utils/DebugUtility.h"

// NOTE : 0630 리소스 매니저 확인을 위한 게임오브젝트 추가
void SunGeneratorObject::Start()
{
	bitmapRenderer = AddComponent<BitmapRenderer>();
	input = AddComponent<InputSystem>();

	DebugUtility::Print(L"SunGeneratorObject Create");
	Singleton<DebugUtility>::GetInstance().PrintMemoryUsage();

	textRenderer = AddComponent<TextRenderer>();
	textRenderer->SetPosition(2, 600);
	textRenderer->SetText(L"태양 개수 : " + std::to_wstring(objects.size()));
}

void SunGeneratorObject::Update()
{
	if (input->IsKeyDown('O'))
	{
		GameObject* obj = new Sun();
		objects.push_back(obj);
		
		std::string name = "Sun";
		std::string index = std::to_string((int)objects.size());
		std::string finalName = name + index;
		
		obj->SetName(finalName);

		int randX = rand() % 1000;
		int randY = rand() % 600;
		obj->transform->SetPosition((float)randX, (float)randY);
		Singleton<SceneManager>::GetInstance().GetCurrentScene()->AddGameObject(obj);
		Singleton<DebugUtility>::GetInstance().PrintMemoryUsage();

		textRenderer->SetText(L"태양 개수 : " + std::to_wstring(objects.size()));
	}

	if (input->IsKeyDown('P'))
	{
		// remove
		if (!objects.empty())
		{
			auto it = --objects.end();
			(*it)->MarkForRemoval();
			objects.erase(it);

			textRenderer->SetText(L"태양 개수 : " + std::to_wstring(objects.size()));
		}
	}
}

void SunGeneratorObject::OnDestroy()
{
}
