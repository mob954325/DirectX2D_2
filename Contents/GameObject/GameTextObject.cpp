#include "GameTextObject.h"
#include "Utility/SceneManager.h"

#include "Utility/Singleton.h"
#include "Core/EngineData.h"

void GameTextObject::Start()
{
	textRenderer = AddComponent<TextRenderer>();
	textRenderer->SetText(L"여기는 게임 씬\n X로 MenuScene 이동");
	textRenderer->SetPosition(20, 20);

	textRenderer2 = AddComponent<TextRenderer>();
	textRenderer2->SetText(L"WASD : 카메라 이동\n\n Y : 메인카메라를 플레이어 카메라로 변경 \n\n U : 메인카메라를 프리 카메라로 변경\n\n H : 플레이어 체력 감소 \n\n J: 플레이어 체력 초기화");
	textRenderer2->SetPosition(20, 80);
	inputSystem = AddComponent<InputSystem>();	

	textRenderer3 = AddComponent<TextRenderer>(); // 중앙 확인옹 텍스트
	textRenderer3->SetText(L"^");
	
	D2D1_SIZE_U size = { EngineData::SceenWidth, EngineData::SceenHeight };
	textRenderer3->SetPosition((float)(size.width / 2), (float)(size.height / 2));


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
