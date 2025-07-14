#include "TestRigidbodyObject.h"
#include "Math/Vector2.h"

void TestRigidbodyObject::Start()
{
	sprite = AddComponent<BitmapRenderer>();
	sprite->CreateBitmapResource(L"../Resource/man.png");

	input = AddComponent<InputSystem>();

	rigid = AddComponent<Rigidbody2D>();
	transform->SetPosition(0, 400.0f);
	transform->SetIsUnityCoords(true);
}

void TestRigidbodyObject::Update()
{
	if (transform->GetPosition().y < 0.0f)
	{
		//rigid->SetGravity(false);
		std::cout << "reached 0.0  coord" << std::endl;
	}
	else
	{
		//rigid->SetGravity(true);
		std::cout << "^^ not reached 0.0  coord" << std::endl;
	}

	HandleMoveInput();
}

void TestRigidbodyObject::OnDestroy()
{
}

void TestRigidbodyObject::HandleMoveInput()
{
	if (input == nullptr) return;

	Vector2 vec{0,0};
	if (input->IsKeyDown(VK_RIGHT))
	{
		vec = Vector2::Right();
	}
	if (input->IsKeyDown(VK_LEFT))
	{
		vec = Vector2::Left();
	}
	if (input->IsKeyDown(VK_UP))
	{
		vec = Vector2::Up();
	}
	if (input->IsKeyDown(VK_DOWN))
	{
		vec = Vector2::Down();
	}

	vec = vec * speed * 1000;
	rigid->ApplyForce(vec);
}
