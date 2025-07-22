#include "Moon.h"
#include "Components/Base/GameObject.h"

void Moon::OnStart()
{
	bitmapRenderer = owner->AddComponent<BitmapRenderer>();
	bitmapRenderer->CreateBitmapResource(L"../Resource/Moon.png");

	SetName("Moon");
	owner->GetTransform().SetScale(0.5f, 0.5f);
	owner->GetTransform().SetPosition(0.0f, 1000.0f);
	owner->GetTransform().SetIsUnityCoords(true);
	owner->GetTransform().SetOffset(-bitmapRenderer->GetResource().get()->GetBitmap()->GetSize().width / 2, bitmapRenderer->GetResource().get()->GetBitmap()->GetSize().height / 2);
}

void Moon::OnUpdate()
{
	
}

void Moon::OnDestroy()
{
}