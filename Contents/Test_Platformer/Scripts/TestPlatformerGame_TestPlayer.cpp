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
}

void Test_PlatformerGame::TestPlatformerGame_TestPlayer::OnStart()
{

}

void Test_PlatformerGame::TestPlatformerGame_TestPlayer::OnFixedUpdate()
{

}

void Test_PlatformerGame::TestPlatformerGame_TestPlayer::OnUpdate()
{

}

void Test_PlatformerGame::TestPlatformerGame_TestPlayer::OnDestroy()
{

}