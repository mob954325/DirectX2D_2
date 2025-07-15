#include "TestColliderbox.h"

void TestColliderbox::Start()
{
	box = AddComponent<BoxComponent>();
	box->SetIsShow(true);
	box->SetWidth(2.0f);

	Vector2 posVec = transform->GetPosition();
	box->SetRect({ -50 / 2, -50 / 2, 50 / 2, 50 / 2 });

	aabb = AddComponent<AABBCollider>();

	//int randX = rand() % 100;
	//int randY = rand() % 100;
	aabb->SetSize(50, 50, 1);

	rigid = AddComponent<Rigidbody2D>();
	rigid->SetGravity(true);
}

void TestColliderbox::Update()
{
}

void TestColliderbox::OnDestroy()
{
}
