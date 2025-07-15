#include "GameTextObject.h"
#include "Scene/SceneManager.h"

#include "Utils/Singleton.h"
#include "Datas/EngineData.h"
#include "Utils/DebugUtility.h"

void GameTextObject::Start()
{
	renderLayer = EngineData::RenderLayer::UI;

	textRenderer = AddComponent<TextRenderer>();
	textRenderer->SetText(L"여기는 게임 씬\n X로 MenuScene 이동");
	textRenderer->SetPosition(2, 20);

	textRenderer2 = AddComponent<TextRenderer>();
	textRenderer2->SetText(L"WASD : 카메라 이동\n\n Y : 메인카메라를 플레이어 카메라로 변경 \n\n U : 메인카메라를 프리 카메라로 변경\n\n H : 플레이어 체력 감소 \n\n J: 플레이어 체력 초기화 \n\n O : 태양 추가\n\n P : 태양 제거 \n\n 1, 2, 3 : 애니메이션 실행 \n\n N : 공격 실행");
	textRenderer2->SetPosition(2, 80);
	inputSystem = AddComponent<InputSystem>();	

	textRenderer3 = AddComponent<TextRenderer>(); // 중앙 확인옹 텍스트
	textRenderer3->SetText(L"^");
	
	textRenderer4 = AddComponent<TextRenderer>();
	textRenderer4->SetText(L"Fps" + std::to_wstring(Singleton<DebugUtility>::GetInstance().GetFPSCount()));
	textRenderer4->SetViewportPosition(0.8f, 0.0f);

	D2D1_SIZE_U size = { EngineData::SceenWidth, EngineData::SceenHeight };
	textRenderer3->SetPosition((float)(size.width / 2), (float)(size.height / 2));
}

void GameTextObject::Update()
{
	textRenderer4->SetText(L"Fps" + std::to_wstring(Singleton<DebugUtility>::GetInstance().GetFPSCount())); // 씬 이동 시 터짐

	if (inputSystem->IsKeyPressed('3'))
	{
		Singleton<SceneManager>::GetInstance().LoadScene(2);
	}
	else if (inputSystem->IsKeyPressed('1'))
	{
		Singleton<SceneManager>::GetInstance().LoadScene(0);
	}
}

void GameTextObject::OnDestroy()
{
}
