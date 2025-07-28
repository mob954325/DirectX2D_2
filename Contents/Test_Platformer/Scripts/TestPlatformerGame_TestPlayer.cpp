#include "TestPlatformerGame_TestPlayer.h"
#include "Components/Base/GameObject.h"

void Test_PlatformerGame::TestPlatformerGame_TestPlayer::OnCreate()
{
	owner->SetRenderLayer(EngineData::RenderLayer::Player); // 오브젝트의 랜더 레이어 설정

	// animation Renderer 초기화
	anim = owner->AddComponent<AnimationRenderer>();
	anim->CreateBitmapResource(L"../Resource/Test_Platformer/Idle.png"); // 리소스 파일 생성
	anim->SetSpriteSheet(L"../Resource/Test_Platformer/json/Idle_sprites.json");	// 스프라이트 시트 json 추가
	anim->SetAnimationClip(L"../Resource/Test_Platformer/json/Idle_Right_anim.json"); // 애니메이션 클립 json 추가
	anim->SetOrderInLayer(5);	// 랜더 순서 설정
	anim->Play();

	// input 초기화
	input = owner->AddComponent<InputSystem>();

	// statComponent 초기화
	hpStat = owner->AddComponent<StatComponent>();
	hp = 10;
	hpStat->SetValue(hp); // int 값 설정
	
	// eventDelegate에 functor 추가
	onHit.Add(hpStat->GetSetValueFunctor());

	// hp Text 위치 초기화
	// hpText = owner->AddComponent<TextRenderer>();
	hpText->SetViewportPosition(0.5f, 0.0f);
}

void Test_PlatformerGame::TestPlatformerGame_TestPlayer::OnStart()
{

}

void Test_PlatformerGame::TestPlatformerGame_TestPlayer::OnFixedUpdate()
{

}

void Test_PlatformerGame::TestPlatformerGame_TestPlayer::OnUpdate()
{
	if (input->IsKeyDown('W'))
	{
		owner->GetTransform().Translate({ 0.0f, 1.0f });
	}
	if (input->IsKeyDown('A'))
	{
		owner->GetTransform().Translate({ -1.0f, 0.0f });
	}
	if (input->IsKeyDown('S'))
	{
		owner->GetTransform().Translate({ 0.0f, -1.0f });
	}
	if (input->IsKeyDown('D'))
	{
		owner->GetTransform().Translate({ 1.0f, 0.0f });
	}

	if (input->IsKeyDown('H'))
	{
		hp--;
		onHit.Invoke(hp);
	}
}

void Test_PlatformerGame::TestPlatformerGame_TestPlayer::OnDestroy()
{

}

void Test_PlatformerGame::TestPlatformerGame_TestPlayer::HanldeHpText()
{
	std::wstring str = std::to_wstring(hp);
	hpText->SetText(str);
}