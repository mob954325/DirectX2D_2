#include "TestRigidbodyObject.h"
#include "Math/Vector2.h"
#include "Datas/EngineData.h"
#include "Scene/SceneManager.h"
#include "Utils/GameTime.h"


void TestRigidbodyObject::Start()
{
	sprite = AddComponent<BitmapRenderer>();
	sprite->CreateBitmapResource(L"../Resource/man.png");

	input = AddComponent<InputSystem>();

	rigid = AddComponent<Rigidbody2D>();
	rigid->SetGravity(true);
	rigid->SetPhysicsType(PhysicsType::Kinematic);

	transform->SetPosition(0, 400.0f);
	transform->SetIsUnityCoords(true);
	transform->SetOffset(-44.5f, 138/2);

	aabb = AddComponent<AABBCollider>();
	aabb->SetSize(89, 138, 1);

	box = AddComponent<BoxComponent>();
	box->SetIsShow(true);
	box->SetWidth(2.0f);
	box->SetRect(
		{
			0,
			0,
			89,
			138,
		}
	);

	playerPosText = AddComponent<TextRenderer>();
	playerPosText->SetViewportPosition(0.5f, 0.9f);
}

void TestRigidbodyObject::Update()
{
	HandleMoveInput();

	if (input->IsKeyPressed('1'))
	{
		Singleton<SceneManager>::GetInstance().LoadScene(0);
	}
	else if (input->IsKeyPressed('2'))
	{
		Singleton<SceneManager>::GetInstance().LoadScene(1);
	}

	// 리셋 포지션
	if (input->IsKeyPressed('R'))
	{
		transform->SetPosition(0, 400.0f);
	}

	// 타입 변경
	if (input->IsKeyPressed('T'))
	{
		rigid->SetPhysicsType(PhysicsType::Dynamic);
	}
	if (input->IsKeyPressed('Y'))
	{
		rigid->SetPhysicsType(PhysicsType::Kinematic);
	}
	if (input->IsKeyPressed('U'))
	{
		rigid->SetPhysicsType(PhysicsType::Static);
	}

	// 좌표 출력
	std::wstring str = L"x : ";
	str += std::to_wstring(transform->GetPosition().x);
	str += L" y : ";
	str += std::to_wstring(transform->GetPosition().y);
	playerPosText->SetText(str);
}

void TestRigidbodyObject::OnDestroy()
{
}

void TestRigidbodyObject::HandleMoveInput()
{
	if (input == nullptr) return;

	if (rigid->GetPhysicsType() == PhysicsType::Dynamic)
	{
		Vector2 vec{ 0,0 };
		if (input->IsKeyDown(VK_RIGHT))
		{
			vec += Vector2::Right();
		}
		if (input->IsKeyDown(VK_LEFT))
		{
			vec += Vector2::Left();
		}
		if (input->IsKeyPressed(VK_UP)) // jump
		{
			vec += Vector2::Up() * 50.0f;
		}
		if (input->IsKeyDown(VK_DOWN))
		{
			vec += Vector2::Down();
		}

		vec = vec * physicSpeed;
		rigid->ApplyForce(vec);
	}
	else
	{
		Vector2 vec{ 0,0 };
		if (input->IsKeyDown(VK_RIGHT))
		{
			vec += Vector2::Right();
		}
		if (input->IsKeyDown(VK_LEFT))
		{
			vec += Vector2::Left();
		}
		if (input->IsKeyDown(VK_UP))
		{
			vec += Vector2::Up();
		}
		if (input->IsKeyDown(VK_DOWN))
		{
			vec += Vector2::Down();
		}

		vec = vec * normalSpeed;
		rigid->SetVelocity(vec);
	}
}
