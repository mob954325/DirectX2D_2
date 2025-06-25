#include "MenuTextObject.h"
#include "Utility/SceneManager.h"

void MenuTextObject::Start()
{
	textRenderer = AddComponent<TextRenderer>();
	textRenderer->SetText(L"여기는 메인 메뉴 씬\n Z로 GameScene 이동");
	textRenderer->SetPosition(20, 20);

	inputSystem = AddComponent<InputSystem>();

	box = AddComponent<BoxComponent>();
	box->SetIsShow(true);
	box->SetRect({ 0, 0, 200, 200 });
}

void MenuTextObject::Update()
{
	if (inputSystem->IsKeyPressed('Z'))
	{
		Singleton<SceneManager>::GetInstance().ChangeScene(1);
	}
}

void MenuTextObject::OnDestroy()
{
	
}
