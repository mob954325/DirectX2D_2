#include "TestPlayer.h"
#include "Utility/Singleton.h"
#include "Utility/GameTime.h"
#include "Utility/SceneManager.h"

void TestPlayer::Start()
{
	playerMainCam = AddComponent<Camera>();
	playerMainCam->AttachGameObjectToCamera(this->transform);
	Singleton<SceneManager>::GetInstance().AddCamera(playerMainCam);

	idleBitmap = AddComponent<AnimationRenderer>();
	idleBitmap->CreateBitMap(L"../Resource/Idle_Down(48x64).png");

	idleBitmap->SetOffSet(24, 32);
	transform->SetIsUnityCoords(true);
	transform->SetScale(1.0f, 1.0f);

	idleBitmap->SetFrameCount(8, 1);
	idleBitmap->SetFrameSize(48, 64);
	idleBitmap->Play();

	input = AddComponent<InputSystem>();
}

void TestPlayer::Update()
{
	if (input->IsKeyPressed('Y'))
	{
		playerMainCam->SetIsMainCamera(true);
	}
	else if (input->IsKeyPressed('U'))
	{
		playerMainCam->SetIsMainCamera(false);
	}

	Move();
	CamMove();
}

void TestPlayer::OnDestroy()
{
}

void TestPlayer::Move()
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

void TestPlayer::CamMove()
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

	//playerMainCam->SetPosition(positionVec.x + moveVec.x, positionVec.y + moveVec.y);
}