#include "TestGround.h"
#include "Datas/EngineData.h"
#include "Components/Base/GameObject.h"

using namespace Test_2QApp;

void TestGround::OnStart()
{
	owner->GetTransform().SetUnityCoords(true);

	box = owner->AddComponent<BoxComponent>();
	box->SetIsShow(true);
	box->SetWidth(2.0f);

	Vector2 posVec = owner->GetTransform().GetPosition();
	box->SetRect({ -1024 / 2, -50 / 2, 1024 / 2, 50 / 2 });
	
	aabb = owner->AddComponent<AABBCollider>();
	aabb->SetSize(1024, 50, 1);
}

void TestGround::OnUpdate()
{
}

void TestGround::OnDestroy()
{
}
