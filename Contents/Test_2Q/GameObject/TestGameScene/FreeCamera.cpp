#include "FreeCamera.h"
#include "Scene/SceneManager.h"
#include "Components/Camera/CameraManager.h"

using namespace Test_2QApp;

void FreeCamera::OnStart()
{
	camera = owner->AddComponent<Camera>();
	Singleton<CameraManager>::GetInstance().Register(new CameraInfo(camera->GetPriority(), camera));

	inputSystem = owner->AddComponent<InputSystem>();
}

void FreeCamera::OnUpdate()
{
	// Input
	if (inputSystem->IsKeyDown('D'))
	{
		Vector2 position = owner->GetTransform().GetPosition();
		owner->GetTransform().SetPosition(position.x + cameraMoveSpeed, position.y);
	}
	if (inputSystem->IsKeyDown('A'))
	{
		Vector2 position = owner->GetTransform().GetPosition();
		owner->GetTransform().SetPosition(position.x - cameraMoveSpeed, position.y);
	}
	if (inputSystem->IsKeyDown('W'))
	{
		Vector2 position = owner->GetTransform().GetPosition();
		owner->GetTransform().SetPosition(position.x, position.y + cameraMoveSpeed);
	}
	if (inputSystem->IsKeyDown('S'))
	{
		Vector2 position = owner->GetTransform().GetPosition();
		owner->GetTransform().SetPosition(position.x, position.y - cameraMoveSpeed);
	}
}

void FreeCamera::OnDestroy()
{
}
