#include "FreeCamera.h"
#include "Scene/SceneManager.h"

void FreeCamera::Start()
{
	camera = AddComponent<Camera>();
	camera->SetIsMainCamera(true);
	camera->AttachGameObjectToCamera(this->transform);
	Singleton<SceneManager>::GetInstance().AddCamera(camera);

	inputSystem = AddComponent<InputSystem>();
}

void FreeCamera::Update()
{
	// Input
	if (inputSystem->IsKeyDown('D'))
	{
		D2D1_VECTOR_2F position = transform->GetPosition();
		transform->SetPosition(position.x + cameraMoveSpeed, position.y);
	}
	if (inputSystem->IsKeyDown('A'))
	{
		D2D1_VECTOR_2F position = transform->GetPosition();
		transform->SetPosition(position.x - cameraMoveSpeed, position.y);
	}
	if (inputSystem->IsKeyDown('W'))
	{
		D2D1_VECTOR_2F position = transform->GetPosition();
		transform->SetPosition(position.x, position.y + cameraMoveSpeed);
	}
	if (inputSystem->IsKeyDown('S'))
	{
		D2D1_VECTOR_2F position = transform->GetPosition();
		transform->SetPosition(position.x, position.y - cameraMoveSpeed);
	}
}

void FreeCamera::OnDestroy()
{
}
