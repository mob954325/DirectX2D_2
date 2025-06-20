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
	D2D1_MATRIX_3X2_F transformMatrix = localTransform->ToWorldMatrix();
	D2D1_MATRIX_3X2_F attachedObjectMatrix = gameObjectTransform->ToWorldMatrix();
	D2D1_MATRIX_3X2_F resultMatrix = transformMatrix * attachedObjectMatrix;

	return resultMatrix;
}

D2D1_MATRIX_3X2_F Camera::GetInvertMatrix() const
{
	D2D1_MATRIX_3X2_F transformMatrix = localTransform->ToWorldMatrix();
	D2D1_MATRIX_3X2_F attachedObjectMatrix = gameObjectTransform->ToWorldMatrix();
	D2D1_MATRIX_3X2_F resultMatrix = transformMatrix * attachedObjectMatrix;
	D2D1InvertMatrix(&resultMatrix);

	return resultMatrix;
}

Transform& Camera::GetTransform() const
{
	return *localTransform;
}