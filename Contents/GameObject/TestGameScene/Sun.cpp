#include "Sun.h"
#include "Utils/GameTime.h"
void Sun::Start()
{
	bitmapRenderer = AddComponent<BitmapRenderer>();
	bitmapRenderer->CreateBitmapResource(L"../Resource/Sun.png");

	SetName("Sun");
	transform->SetScale(0.1f, 0.1f);
	transform->SetIsUnityCoords(true);
	transform->SetOffset(-512, 512);
}

void Sun::Update()
{
	float rotation_sun = transform->GetRotation();
	transform->SetRotation(rotation_sun + baseRotateSpeed * sunRotateRatio * Singleton<GameTime>::GetInstance().GetDeltaTime());
	
//	std::cout << "sun : " << (transform->IsDirty() ? "true" : "false") << std::endl;
}

void Sun::OnDestroy()
{
	
}