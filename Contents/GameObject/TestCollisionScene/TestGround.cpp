#include "TestGround.h"
#include "Datas/EngineData.h"

void TestGround::Start()
{
	//renderLayer = EngineData::RenderLayer::GameObject; // NOTE: 왜 이게 없으면 rigidbody가 존재할 때 같이 떨어질까?
	box = AddComponent<BoxComponent>();
	box->SetIsShow(true);
	box->SetWidth(2.0f);

	D2D1_VECTOR_2F posVec = transform->GetPosition();
	box->SetRect({ -1024 / 2, -50 / 2, 1024 / 2, 50 / 2 });

	aabb = AddComponent<AABBCollider>();
	//aabb->SetSize(1024, 50, 1);
}

void TestGround::Update()
{
	std::cout << " - transform : " << transform->GetPosition().x << " " << transform->GetPosition().y << std::endl;
}

void TestGround::OnDestroy()
{
}
