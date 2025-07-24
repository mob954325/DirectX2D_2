#include "Sun.h"
#include "Utils/GameTime.h"
#include "Components/Base/GameObject.h"

using namespace Test_2QApp;

void Sun::OnStart()
{
	bitmapRenderer = owner->AddComponent<BitmapRenderer>();
	bitmapRenderer->CreateBitmapResource(L"../Resource/Sun.png");

	owner->GetTransform().SetScale(0.1f, 0.1f);
	owner->GetTransform().SetUnityCoords(true);
	owner->GetTransform().SetOffset(-512, 512);

	aabbCollision = owner->AddComponent<AABBCollider>();
	aabbCollision->SetSize(120, 120, 1);

	box = owner->AddComponent<BoxComponent>();
	box->SetIsShow(true);
	box->SetWidth(2.0f);
	Vector2 posVec = owner->GetTransform().GetPosition();
	box->SetRect(
		{
			-60 * 0.5f,
			-60 * 0.5f,
			60 * 0.5f,
			60 * 0.5f
		}
	);
}

void Sun::OnUpdate()
{
	int a = 0;

	//float rotation_sun = transform->GetRotation();
	//transform->SetRotation(rotation_sun + baseRotateSpeed * sunRotateRatio * Singleton<GameTime>::GetInstance().GetDeltaTime());	
}

void Sun::OnDestroy()
{
	
}