#include "Earth.h"
#include "Scene/SceneManager.h"
#include "Utils/GameTime.h"
#include "Components/Base/GameObject.h"

using namespace Test_2QApp;

void Earth::OnStart()
{
	bitmapRenderer = owner->AddComponent<BitmapRenderer>();
	bitmapRenderer->CreateBitmapResource(L"../Resource/Earth.png");

	owner->GetTransform().SetScale(0.5f, 0.5f);
	owner->GetTransform().SetPosition(0.0f, 1000.0f);
	owner->GetTransform().SetIsUnityCoords(true);
	owner->GetTransform().SetOffset(-bitmapRenderer->GetResource().get()->GetBitmap()->GetSize().width / 2, bitmapRenderer->GetResource().get()->GetBitmap()->GetSize().height / 2);
}

void Earth::OnUpdate()
{
	float rotation_earth = owner->GetTransform().GetRotation();
	owner->GetTransform().SetRotation(rotation_earth + baseRotateSpeed * earthRotateRatio * Singleton<GameTime>::GetInstance().GetDeltaTime());
}

void Earth::OnDestroy()
{
}
