#include "TestPlayer.h"
#include "Utility/Singleton.h"
#include "Utility/GameTime.h"

void TestPlayer::Start()
{
	playerMainCam = AddComponent<Camera>();
	playerMainCam->AttachGameObjectToCamera(this->transform);

	idleBitmap = AddComponent<BitmapRenderer>();
	idleBitmap->CreateBitMap(L"../Resource/Idle_Down.png");

	idleBitmap->SetOffSet(idleBitmap->GetBitmap()->GetSize().width / 2 * -1, idleBitmap->GetBitmap()->GetSize().height / 2 * -1);
	transform->SetIsUnityCoords(true);
	transform->SetScale(1.0f, 1.0f);

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

	D2D1_VECTOR_2F inputVec = { 0,0 };

	if (input->IsKeyDown(VK_RIGHT))
	{
		D2D1_VECTOR_2F position = transform->GetPosition();
		transform->SetPosition(position.x + speed, position.y);
	}
	if (input->IsKeyDown(VK_LEFT))
	{
		D2D1_VECTOR_2F position = transform->GetPosition();
		transform->SetPosition(position.x - speed, position.y);
	}
	if (input->IsKeyDown(VK_UP))
	{
		D2D1_VECTOR_2F position = transform->GetPosition();
		transform->SetPosition(position.x, position.y + speed);
	}
	if (input->IsKeyDown(VK_DOWN))
	{
		D2D1_VECTOR_2F position = transform->GetPosition();
		transform->SetPosition(position.x, position.y - speed);
	}
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

	transform->SetPosition(positionVec.x + moveVec.x, positionVec.y + moveVec.y);
}