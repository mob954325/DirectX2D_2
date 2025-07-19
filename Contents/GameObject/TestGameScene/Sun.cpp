#include "Sun.h"
#include "Utils/GameTime.h"
void Sun::Start()
{
	bitmapRenderer = AddComponent<BitmapRenderer>();
	bitmapRenderer->CreateBitmapResource(L"../Resource/Sun.png");

	transform->SetScale(0.1f, 0.1f);
	transform->SetIsUnityCoords(true);
	transform->SetOffset(-512, 512);

	aabbCollision = AddComponent<AABBCollider>();
	aabbCollision->SetSize(120, 120, 1);

	box = AddComponent<BoxComponent>();
	box->SetIsShow(true);
	box->SetWidth(2.0f);
	Vector2 posVec = transform->GetPosition();
	box->SetRect(
		{
			-60 * 0.5f,
			-60 * 0.5f,
			60 * 0.5f,
			60 * 0.5f
		}
	);
}

void Sun::Update()
{
	int a = 0;

	//float rotation_sun = transform->GetRotation();
	//transform->SetRotation(rotation_sun + baseRotateSpeed * sunRotateRatio * Singleton<GameTime>::GetInstance().GetDeltaTime());	
}

void Sun::OnDestroy()
{
	
}