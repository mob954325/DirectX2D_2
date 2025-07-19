#include "FreeCamera.h"
#include "Scene/SceneManager.h"
#include "Components/Camera/CameraManager.h"

void FreeCamera::Start()
{
	camera = AddComponent<Camera>();
	Singleton<CameraManager>::GetInstance().Register(new CameraInfo(camera->GetPriority(), camera));

	inputSystem = AddComponent<InputSystem>();
}

void FreeCamera::Update()
{
	// Input
	if (inputSystem->IsKeyDown('D'))
	{
		Vector2 position = transform->GetPosition();
		transform->SetPosition(position.x + cameraMoveSpeed, position.y);
	}
	if (inputSystem->IsKeyDown('A'))
	{
		Vector2 position = transform->GetPosition();
		transform->SetPosition(position.x - cameraMoveSpeed, position.y);
	}
	if (inputSystem->IsKeyDown('W'))
	{
		Vector2 position = transform->GetPosition();
		transform->SetPosition(position.x, position.y + cameraMoveSpeed);
	}
	if (inputSystem->IsKeyDown('S'))
	{
		Vector2 position = transform->GetPosition();
		transform->SetPosition(position.x, position.y - cameraMoveSpeed);
	}
}

void FreeCamera::OnDestroy()
{
}
