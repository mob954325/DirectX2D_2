#include "TestColliderboxGenerator.h"
#include "GameObject/TestCollisionScene/TestColliderbox.h"
#include "Scene/SceneManager.h"

void TestColliderboxGenerator::Start()
{
	input = AddComponent<InputSystem>();
	text = AddComponent<TextRenderer>();

	text->SetViewportPosition(0.5f, 0.0f);
	text->SetText(L"[ Box Generator 명령어 ]\n\nO : 박스 생성 \n P : 박스 제거");
}

void TestColliderboxGenerator::Update()
{
	if (input->IsKeyPressed('O'))
	{
		GameObject* obj = new TestColliderbox();
		objects.push_back(obj);

		std::string name = "box";
		std::string index = std::to_string((int)objects.size());
		std::string finalName = name + index;

		obj->SetName(finalName);
		obj->transform->SetPosition(0, 400);
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
