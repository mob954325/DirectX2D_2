#include "Camera.h"

void Camera::OnDestroy()
{
	if (isLocalTransform)
	{
		// 해당 객체에서 만든 트랜스폼 메모리 해제
		delete gameObjectTransform;
	}
}

bool Camera::IsMainCamera()
{
	return isMainCamera;
}

void Camera::SetIsMainCamera(bool value)
{
	isMainCamera = value;
}

void Camera::SetTransform(Transform* pTransform)
{
	gameObjectTransform = pTransform;
}

Transform* Camera::GetTransform()
{
	if (gameObjectTransform == nullptr)
	{
		Transform* pt = new Transform();
		gameObjectTransform = pt;

		isLocalTransform = true;
	}

	return gameObjectTransform;
}
