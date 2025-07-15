#include "TestWall.h"

void TestWall::Start()
{
	box = AddComponent<BoxComponent>();
	box->SetIsShow(true);
	box->SetWidth(2.0f);

	Vector2 posVec = transform->GetPosition();
	box->SetRect({-50 / 2, -1024 / 2, 50 / 2, 1024 / 2 });

	aabb = AddComponent<AABBCollider>();
	aabb->SetSize(50, 1024, 1);
	transform->SetPosition(200, 0);
}

void TestWall::Update()
{
}

void TestWall::OnDestroy()
{
}
