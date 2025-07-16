#include "TestColliderbox.h"

void TestColliderbox::Start()
{
	box = AddComponent<BoxComponent>();
	box->SetIsShow(true);
	box->SetWidth(2.0f);

	aabb = AddComponent<AABBCollider>();

	int min = 1;
	int max = 100;
	float randX = rand() % (max - min + 1) + min;
	float randY = rand() % (max - min + 1) + min;
	aabb->SetSize(randX, randY, 1);

	box->SetRect({ -randX / 2, -randY / 2, randX / 2, randY / 2 });

	rigid = AddComponent<Rigidbody2D>();
	rigid->SetGravity(true);
	rigid->SetPhysicsType(PhysicsType::Dynamic);

	float randMass = rand() % 3;
	rigid->SetMass(randMass);
}

void TestColliderbox::Update()
{
}

void TestColliderbox::OnDestroy()
{
}
