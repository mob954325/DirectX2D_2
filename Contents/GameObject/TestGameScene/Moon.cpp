#include "Moon.h"

void Moon::Start()
{
	bitmapRenderer = AddComponent<BitmapRenderer>();
	bitmapRenderer->CreateBitmapResource(L"../Resource/Moon.png");

	SetName("Moon");
	transform->SetScale(0.5f, 0.5f);
	transform->SetPosition(0.0f, 1000.0f);
	transform->SetIsUnityCoords(true);
	transform->SetRenderAnchor(-bitmapRenderer->GetResource().get()->GetBitmap()->GetSize().width / 2, bitmapRenderer->GetResource().get()->GetBitmap()->GetSize().height / 2);
}

void Moon::Update()
{
	
}

void Moon::OnDestroy()
{
}