#include "TestWall.h"
#include "Components/Base/GameObject.h"

void TestWall::OnStart()
{
	box = owner->AddComponent<BoxComponent>();
	box->SetIsShow(true);
	box->SetWidth(2.0f);

	Vector2 posVec = owner->GetTransform().GetPosition();
	box->SetRect({-50 / 2, -1024 / 2, 50 / 2, 1024 / 2 });

	aabb = owner->AddComponent<AABBCollider>();
	aabb->SetSize(50, 1024, 1);
}

void TestWall::OnUpdate()
{
}

void TestWall::OnDestroy()
{
}
