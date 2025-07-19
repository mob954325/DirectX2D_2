﻿#include "pch.h"
#include "GameObject.h"
#include "Transform.h"
#include "Utils/Singleton.h"
#include "Components/Camera/CameraManager.h"
#include "Components/Camera/Camera.h"
#include "math.h"

void Transform::SetOffset(float x, float y)
{
	offsetX = x; offsetY = y;

	normalRenderMatrix = D2D1::Matrix3x2F::Scale(1.0f, 1.0) * D2D1::Matrix3x2F::Translation(offsetX, -offsetY);
	unityRenderMatrix = D2D1::Matrix3x2F::Scale(1.0f, -1.0f) * D2D1::Matrix3x2F::Translation(offsetX, offsetY);
}

void Transform::CalculateFinalMatrix()
{
	Camera* pCam = Singleton<CameraManager>::GetInstance().GetActiveCamera();
	D2D1_MATRIX_3X2_F mainCamInvertMatrix = pCam ? pCam->GetInvertMatrix() : D2D1::Matrix3x2F::Identity();

	if (IsDirty())
	{		
		// 최종 변환 값 계산
		if (owner->transform->IsUnityCoords())
		{
			finalMatrix =
				unityRenderMatrix *					// Render Matrix
				owner->transform->ToWorldMatrix() *	// m_transform world matrix 
				mainCamInvertMatrix *				// MainCamera invert matrix
				unityCoordMatrix;					// unity coord Matrix
		}
		else
		{
			finalMatrix =
				normalRenderMatrix *				// Render Matrix
				owner->transform->ToWorldMatrix() *	// m_transform world matrix 
				mainCamInvertMatrix;				// MainCamera invert matrix	
		}
	}
}

D2D1_MATRIX_3X2_F Transform::GetFinalMatrix() const
{
	return finalMatrix;
}

bool Transform::IsDirty()
{
	Camera* pCam = Singleton<CameraManager>::GetInstance().GetActiveCamera();
	if (pCam != nullptr)
	{
		if (parent != nullptr)
		{
			return dirty || parent->IsDirty() || pCam->GetTransform().IsDirty();		
		}
		else
		{
			return dirty || pCam->GetTransform().IsDirty();
		}
	}
	else
	{
		if (parent != nullptr)
		{
			return dirty || parent->IsDirty();
		}
		else
		{
			return dirty;
		}
	}
}

void Transform::Translate(const Vector2& delta)
{
	float x = position.x + delta.x;
	float y = position.y + delta.y;

	position = { x, y };
	dirty = true;
}

void Transform::SetTransformToMatrix(D2D1_MATRIX_3X2_F matrix)
{
}

/// <summary>
/// 로컬 매트릭스 반환
/// </summary>
D2D1_MATRIX_3X2_F Transform::ToLocalMatrix()
{
	if (dirty)
	{
		cachedMatrix = 
			D2D1::Matrix3x2F::Scale(scale.x, scale.y) *
			D2D1::Matrix3x2F::Rotation(rotation) *
			D2D1::Matrix3x2F::Translation(position.x, position.y);
	}

	return cachedMatrix;
}

/// <summary>
/// 현재 로컬 좌표의 역행렬
/// </summary>
D2D1_MATRIX_3X2_F Transform::ToLocalInvertMatrix()
{
	D2D1_MATRIX_3X2_F resultMatrix = ToLocalMatrix();
	BOOL isSuccess = D2D1InvertMatrix(&resultMatrix);

	if (isSuccess)
	{
		return resultMatrix;
	}
	else
	{
		return D2D1::IdentityMatrix();
	}
}

/// <summary>
/// 월드 매트릭스 반환
/// </summary>
D2D1_MATRIX_3X2_F Transform::ToWorldMatrix()
{
	if (parent == nullptr)
		return ToLocalMatrix();
	else
		return ToLocalMatrix() * parent->ToWorldMatrix();
}

/// <summary>
/// 현재 월드 좌표의 역행렬
/// </summary>
D2D1_MATRIX_3X2_F Transform::ToWorldInvertMatrix()
{
	D2D1_MATRIX_3X2_F resultMatrix = ToWorldMatrix();
	BOOL isSuccess = D2D1InvertMatrix(&resultMatrix);

	if (isSuccess)
	{
		return resultMatrix;
	}
	else
	{
		return D2D1::IdentityMatrix();
	}
}

/// <summary>
/// 모든 값을 초기화 ( scale은 (1,1) , 나머지 다 0으로 초기화 )
/// </summary>
void Transform::Reset()
{
	SetPosition(0.0f, 0.0f);
	SetRotation(0.0f);
	SetScale(1.0f, 1.0f);
}

void Transform::OnStart()
{
	unityCoordMatrix = D2D1::Matrix3x2F::Scale(1.0f, -1.0f) * D2D1::Matrix3x2F::Translation((FLOAT)(EngineData::SceenWidth / 2), (FLOAT)(EngineData::SceenHeight / 2));
}

void Transform::OnEnd()
{
	if (dirty) dirty = false;
}

void Transform::SetPosition(float x, float y)
{
	if ((abs(position.x - x) > FLT_EPSILON) || (abs(position.y - y) > FLT_EPSILON))
	{
		position.x = x; 
		position.y = y;
		dirty = true; 
	}
}

void Transform::SetRotation(float rotValue)
{
	if (abs(rotation - rotValue) > FLT_EPSILON)
	{
		rotation = rotValue;
		dirty = true; 
	}
}

void Transform::SetScale(float scaleX, float scaleY)
{
	if ((abs(scale.x - scaleX) > FLT_EPSILON) || (abs(scale.y - scaleY) > FLT_EPSILON))
	{
		scale.x = scaleX; 
		scale.y = scaleY;
		dirty = true;
	}
}
