#include "MenuObj.h"
#include "Components/Base/GameObject.h"
#include "Utils/Singleton.h"
#include "Scene/SceneManager.h"

void Test_PlatformerGame::MenuObj::OnCreate()
{
	owner->GetTransform().SetUnityCoords(false);

	// BitmapRenderer 컴포넌트 설정
	backGround = owner->AddComponent<BitmapRenderer>();
	backGround->CreateBitmapResource(L"../Resource/Test_Platformer/background.png"); // 배경 이미지 자원 만들기 요청
	backGround->SetOrderInLayer(-1);

	// TextRenderer 컴포넌트 설정
	menuText = owner->AddComponent<TextRenderer>();
	menuText->SetViewportPosition(0.5f, 0.5f);	// viewport 기준 위치 설정
	menuText->SetColor(D2D1::ColorF::DarkBlue);
	menuText->SetText(L"한글 한글, English English");

	input = owner->AddComponent<InputSystem>();
}

void Test_PlatformerGame::MenuObj::OnStart()
{
}

void Test_PlatformerGame::MenuObj::OnFixedUpdate()
{
}

void Test_PlatformerGame::MenuObj::OnUpdate()
{
	if (input->IsKeyPressed('P'))
	{
		Singleton<SceneManager>::GetInstance().LoadScene(1);
	}
}

void Test_PlatformerGame::MenuObj::OnDestroy()
{
}
