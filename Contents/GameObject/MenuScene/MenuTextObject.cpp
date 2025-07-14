#include "MenuTextObject.h"
#include "Scene/SceneManager.h"

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
	if (inputSystem->IsKeyPressed('2'))
	{
		Singleton<SceneManager>::GetInstance().LoadScene(1);
	}
	else if (inputSystem->IsKeyPressed('3'))
	{
		Singleton<SceneManager>::GetInstance().LoadScene(2);
	}
}

void MenuTextObject::OnDestroy()
{
	
}
