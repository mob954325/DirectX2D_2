#include "GameTextObject.h"
#include "Utility/SceneManager.h"

void GameTextObject::Start()
{
	textRenderer = AddComponent<TextRenderer>();
	textRenderer->SetText(L"여기는 게임 씬\n X로 MenuScene 이동");
	textRenderer->SetPosition(20, 20);

	textRenderer2 = AddComponent<TextRenderer>();
	textRenderer2->SetText(L"WASD : 카메라 이동\n\n Y : 메인카메라를 플레이어 카메라로 변경 \n\n U : 메인카메라를 프리 카메라로 변경");
	textRenderer2->SetPosition(20, 80);
	inputSystem = AddComponent<InputSystem>();	
}

void GameTextObject::Update()
{
	if (inputSystem->IsKeyPressed('X'))
	{
		Singleton<SceneManager>::GetInstance().ChangeScene(0);
	}
}

void GameTextObject::OnDestroy()
{
}
