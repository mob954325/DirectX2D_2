#include "Earth.h"
#include "Utility/SceneManager.h"
#include "Utility/GameTime.h"

void Earth::Start()
{
	bitmapRenderer = AddComponent<BitmapRenderer>();
	bitmapRenderer->CreateBitMap(L"../Resource/Earth.png");

	transform->SetScale(0.5f, 0.5f);
	transform->SetPosition(0.0f, 1000.0f);
	transform->SetIsUnityCoords(true);
	bitmapRenderer->SetOffSet(bitmapRenderer->GetBitmap()->GetSize().width / 2 * -1, bitmapRenderer->GetBitmap()->GetSize().height / 2 * -1);
}

void Earth::Update()
{
	float rotation_earth = transform->GetRotation();
	transform->SetRotation(rotation_earth + baseRotateSpeed * earthRotateRatio * Singleton<GameTime>::GetInstance().GetDeltaTime());
}

void Earth::OnDestory()
{
}
