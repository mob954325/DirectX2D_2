#include "Sun.h"
#include "Utility/GameTime.h"
void Sun::Start()
{
	bitmapRenderer = AddComponent<BitmapRenderer>();
	bitmapRenderer->CreateBitMap(L"../Resource/Sun.png");

	transform->SetScale(0.1f, 0.1f);
	transform->SetIsUnityCoords(true);
	bitmapRenderer->SetOffSet(bitmapRenderer->GetBitmap()->GetSize().width / 2 * -1, bitmapRenderer->GetBitmap()->GetSize().height / 2 * -1);
}

void Sun::Update()
{
	float rotation_sun = transform->GetRotation();
	transform->SetRotation(rotation_sun + baseRotateSpeed * sunRotateRatio * Singleton<GameTime>::GetInstance().GetDeltaTime());
}

void Sun::OnDestory()
{
	
}