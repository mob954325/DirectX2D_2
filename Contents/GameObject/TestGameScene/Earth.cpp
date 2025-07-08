#include "Earth.h"
#include "Scene/SceneManager.h"
#include "Utils/GameTime.h"

void Earth::Start()
{
	bitmapRenderer = AddComponent<BitmapRenderer>();
	bitmapRenderer->CreateBitmapResource(L"../Resource/Earth.png");

	transform->SetScale(0.5f, 0.5f);
	transform->SetPosition(0.0f, 1000.0f);
	transform->SetIsUnityCoords(true);
	bitmapRenderer->SetRenderAnchor(-bitmapRenderer->GetResource().get()->GetBitmap()->GetSize().width / 2, bitmapRenderer->GetResource().get()->GetBitmap()->GetSize().height / 2);
}

void Earth::Update()
{
	float rotation_earth = transform->GetRotation();
	transform->SetRotation(rotation_earth + baseRotateSpeed * earthRotateRatio * Singleton<GameTime>::GetInstance().GetDeltaTime());
}

void Earth::OnDestroy()
{
}
