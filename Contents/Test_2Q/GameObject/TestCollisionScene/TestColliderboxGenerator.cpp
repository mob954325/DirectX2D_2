#include "TestColliderboxGenerator.h"
#include "Scene/SceneManager.h"
#include "TestColliderbox.h"

using namespace Test_2QApp;

void TestColliderboxGenerator::OnStart()
{
	input = owner->AddComponent<InputSystem>();
	text = owner->AddComponent<TextRenderer>();

	text->SetViewportPosition(0.5f, 0.0f);
	text->SetText(L"[ Box Generator 명령어 ]\n\nO : 박스 생성 \n P : 박스 제거");
}

void TestColliderboxGenerator::OnUpdate()
{
	if (input->IsKeyPressed('O'))
	{
		GameObject* obj = new GameObject();
		obj->AddComponent<TestColliderbox>();
		objects.push_back(obj);

		std::string name = "box";
		std::string index = std::to_string((int)objects.size());
		std::string finalName = name + index;

		obj->SetName(finalName);
		obj->GetTransform().SetPosition(0, 400);
		Singleton<SceneManager>::GetInstance().GetCurrentScene()->AddGameObject(obj);
	}

	if (input->IsKeyPressed('P'))
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

void TestColliderboxGenerator::OnDestroy()
{
}
