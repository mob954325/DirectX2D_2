#include "Camera.h"

void Camera::OnStart()
{
	localTransform = new Transform();
}

void Camera::OnDestroy()
{
	if (isLocalTransform)
	{
		// 해당 객체에서 만든 트랜스폼 메모리 해제
		delete localTransform;
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

void Camera::AttachGameObjectToCamera(Transform* pTransform)
{
	gameObjectTransform = pTransform;
}

D2D1_MATRIX_3X2_F Camera::GetMatrix() const
{
	D2D1_MATRIX_3X2_F attached = gameObjectTransform->ToWorldMatrix();
	D2D1_MATRIX_3X2_F local = localTransform->ToWorldMatrix();
	D2D1_MATRIX_3X2_F resultMatrix = attached * local;

	return resultMatrix;
}

D2D1_MATRIX_3X2_F Camera::GetInvertMatrix() const
{
	D2D1_MATRIX_3X2_F matrix = GetMatrix();
	D2D1InvertMatrix(&matrix);

	return matrix;
}

Transform& Camera::GetTransform() const
{
	return *localTransform;
}