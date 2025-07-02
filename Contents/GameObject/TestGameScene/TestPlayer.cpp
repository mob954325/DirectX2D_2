#include "TestPlayer.h"
#include "Utils/Singleton.h"
#include "Utils/GameTime.h"
#include "Scene/SceneManager.h"

#include <string>
#include <iostream>

void TestPlayer::Start()
{
	renderLayer = EngineData::RenderLayer::Player;

	playerMainCam = AddComponent<Camera>();
	playerMainCam->AttachGameObjectToCamera(this->transform);
	Singleton<SceneManager>::GetInstance().AddCamera(playerMainCam);

	idleBitmap = AddComponent<AnimationRenderer>();	
	idleBitmap->CreateBitmapResource(L"../Resource/ken.png");
	idleBitmap->SetSpriteSheet(L"../Resource/Json/ken_sprites.json");
	idleBitmap->SetAnimationClip(L"../Resource/Json/Attack_Front_anim.json");
	idleBitmap->Play();
	
	transform->SetIsUnityCoords(true);
	transform->SetScale(1.0f, 1.0f);

	input = AddComponent<InputSystem>();

	hpComp = AddComponent<StatComponent>();
	hpComp->ChangeStat(maxHp);
	OnHitAction += hpComp->GetValueFunctionObject();
	
	text = AddComponent<TextRenderer>();
	text->SetPosition(700, 20);

	// Text 초기화
	std::wstring hpText = L"Hp : ";
	hpText += std::to_wstring(hpComp->GetValue());
	text->SetText(hpText);

	box = AddComponent<BoxComponent>();
	box->SetIsShow(true);
	box->SetWidth(2.0f);
	D2D1_SIZE_F size = idleBitmap->GetResource().get()->GetBitmap()->GetSize();
	D2D1_RECT_F rect // NOTE: 임시 값 조정 
	{
		-48 / 2,
		-64 / 2,
		48 / 2,
		64 / 2,
	};

	box->SetRect(rect);

	animFramText = AddComponent<TextRenderer>();
	animFramText->SetViewportPosition(0.8f, 0.1f);
}

void TestPlayer::Update()
{
	animFramText->SetText(L"현재 애니메이션 프레임 : " + std::to_wstring(idleBitmap->GetFrame()));

	if (input->IsKeyPressed('M')) // IGameObjectQuery로 게임 오브젝트 찾기 테스트
	{
		GameObject* sun = query->FindByName("Sun");
	}

	HandleCameraInput();
	HandleHitInput();
	HandleMoveInput();
	HandlePlayerCameraInput();
	HandleAnimationInput();
}

void TestPlayer::OnDestroy()
{
}

void TestPlayer::HandleMoveInput()
{
	if (input == nullptr) return;

	D2D1_VECTOR_2F position = transform->GetPosition();
	D2D1_VECTOR_2F moveVec = { 0,0 };

	if (input->IsKeyDown(VK_RIGHT))
	{
		moveVec.x += speed;
	}
	if (input->IsKeyDown(VK_LEFT))
	{
		moveVec.x -= speed;
	}
	if (input->IsKeyDown(VK_UP))
	{
		moveVec.y += speed;
	}
	if (input->IsKeyDown(VK_DOWN))
	{
		moveVec.y -= speed;
	}

	transform->SetPosition(position.x + moveVec.x, position.y + moveVec.y);
}

void TestPlayer::HandlePlayerCameraInput()
{
	if (input == nullptr) return;

	D2D1_VECTOR_2F inputVec = { 0,0 };

	if (input->IsKeyDown('K'))	inputVec.y -= 1.0f;
	if (input->IsKeyDown('I'))	inputVec.y += 1.0f;
	if (input->IsKeyDown('J'))	inputVec.x -= 1.0f;
	if (input->IsKeyDown('L')) inputVec.x += 1.0f;

	D2D1_VECTOR_2F positionVec = { playerMainCam->GetTransform().GetPosition().x, playerMainCam->GetTransform().GetPosition().y};

	float deltaTime = Singleton<GameTime>::GetInstance().GetDeltaTime();
	D2D1_VECTOR_2F moveVec = { deltaTime * inputVec.x * speed, deltaTime * inputVec.y * speed };
}

void TestPlayer::HandleHitInput()
{
	// 체력 이벤트 인풋
	if (input->IsKeyPressed('H'))
	{
		int dmg = 1;
		OnHit(dmg);
	}
	else if (input->IsKeyPressed('J'))
	{
		hpComp->ChangeStat(maxHp);

		std::wstring hpText = L"Hp : ";
		hpText += std::to_wstring(hpComp->GetValue());
		text->SetText(hpText);
	}
}

void TestPlayer::HandleCameraInput()
{
	// 카메라 설정 인풋
	if (input->IsKeyPressed('Y'))
	{
		playerMainCam->SetIsMainCamera(true);
	}
	else if (input->IsKeyPressed('U'))
	{
		playerMainCam->SetIsMainCamera(false);
	}
}

void TestPlayer::HandleAnimationInput()
{
	if (input->IsKeyPressed('1'))
	{
		idleBitmap->SetAnimationClip(L"../Resource/Json/Attack_Front_anim.json");
	}
	if (input->IsKeyPressed('2'))
	{
		idleBitmap->SetAnimationClip(L"../Resource/Json/Attack_Up_anim.json");
	}
	if (input->IsKeyPressed('3'))
	{
		idleBitmap->SetAnimationClip(L"../Resource/Json/Idle_Right_anim.json");
	}
}

void TestPlayer::OnHit(int dmg)
{
	int currentHp = hpComp->GetValue();

	if (currentHp <= 0) return;

	OnHitAction.Invoke(currentHp - dmg);

	std::wstring hpText = L"Hp : ";
	hpText += std::to_wstring(hpComp->GetValue());
	text->SetText(hpText);
}