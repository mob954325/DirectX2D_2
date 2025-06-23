#include "Moon.h"

void Moon::Start()
{
	bitmapRenderer = AddComponent<BitmapRenderer>();
	bitmapRenderer->CreateBitMap(L"../Resource/Moon.png");

	transform->SetScale(0.5f, 0.5f);
	transform->SetPosition(0.0f, 1000.0f);
	transform->SetIsUnityCoords(true);
	bitmapRenderer->SetOffSet(-bitmapRenderer->GetBitmap()->GetSize().width / 2, bitmapRenderer->GetBitmap()->GetSize().height / 2);
}

void Moon::Update()
{
}

void Moon::OnDestroy()
{
}