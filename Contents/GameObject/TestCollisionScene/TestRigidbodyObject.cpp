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
	rigid->SetMass(2);

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

	GuideText = AddComponent<TextRenderer>();
	GuideText->SetViewportPosition(0.2f, 0.2f);
	GuideText->SetText(L"-- key list --\n\nReset position : R\n\n-- Player physics type --\n\nDynamic : T\nKinematic : Y\nStatic : U");

	showTypeText = AddComponent<TextRenderer>();
	showTypeText->SetViewportPosition(0.2f, 0.5f);
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

	// type 출력
	PhysicsType type = rigid->GetPhysicsType();
	if (type == PhysicsType::Dynamic)
	{
		showTypeText->SetText(L"Physics : Dynamic");
	}
	else if (type == PhysicsType::Kinematic)
	{
		showTypeText->SetText(L"Physics : Kinematic");
	}
	else if (type == PhysicsType::Static)
	{
		showTypeText->SetText(L"Physics : Static");
	}
}

void TestRigidbodyObject::OnDestroy()
{
}

void TestRigidbodyObject::OnColliderEnter(GameObject* collider)
{
	// std::cout << " -- Enter -- " << std::endl;
}

void TestRigidbodyObject::OnColliderStay(GameObject* collider)
{
	// std::cout << " *** Stay *** " << std::endl;
}

void TestRigidbodyObject::OnColliderExit(GameObject* collider)
{
	// std::cout << " |||| Exit |||| " << std::endl;
}

void TestRigidbodyObject::OnTriggerEnter(GameObject* collider)
{
	// std::cout << " -- Enter -- " << std::endl;
}

void TestRigidbodyObject::OnTriggerStay(GameObject* collider)
{
	// std::cout << " *** Stay *** " << std::endl;
}

void TestRigidbodyObject::OnTriggerExit(GameObject* collider)
{
	// std::cout << " |||| Exit |||| " << std::endl;
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
			rigid->ApplyImpluse(Vector2::Up() * normalSpeed * 3);
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
