#include "TestColliderbox.h"
#include "Components/Base/GameObject.h"

void TestColliderbox::OnStart()
{
	box = owner->AddComponent<BoxComponent>();
	box->SetIsShow(true);
	box->SetWidth(2.0f);

	aabb = owner->AddComponent<AABBCollider>();

	int min = 1;
	int max = 100;
	float randX = rand() % (max - min + 1) + min;
	float randY = rand() % (max - min + 1) + min;
	aabb->SetSize(randX, randY, 1);

	box->SetRect({ -randX / 2, -randY / 2, randX / 2, randY / 2 });

	rigid = owner->AddComponent<Rigidbody2D>();
	rigid->SetGravity(true);
	rigid->SetPhysicsType(PhysicsType::Dynamic);
	rigid->SetMass(0.3);
	rigid->Setfriction(1);

	text = owner->AddComponent<TextRenderer>();
	text->SetText(L"상자");
	text->SetWorldObject(true);
}

void TestColliderbox::OnUpdate()
{
}

void TestColliderbox::OnDestroy()
{
}
