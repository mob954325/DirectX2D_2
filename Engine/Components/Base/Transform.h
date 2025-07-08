#pragma once
#include "pch.h"
#include "Component.h"
 
// 기본 좌표 [ normal setting ]
//       (0,0) +----------+ (width, 0)
//             |          |
//             |          |
//             |  screen  |
//             |          |
// (0, height) +----------+ (width, height)
//
// 유니티 좌표 [ UnityCoord Setting ]
// (-width / 2, height / 2)  +----------+ (width / 2, height / 2) 
//                           |          |
//                           |  Center  |
//                           |  (0, 0)  |
//                           |          |
// (-width / 2, -height / 2) +----------+ (width / 2, -height / 2) 

class Transform : public Component 
{
protected:
	Transform* parent = nullptr;

	D2D1_VECTOR_2F position;
	float rotation;
	D2D1_VECTOR_2F scale;
	D2D1_MATRIX_3X2_F cachedMatrix = D2D1::Matrix3x2F::Identity();

	bool dirty = true;	// 행렬 반복 연산 제거용 플래그 변수 ( true : transform 값이 갱신됨 )
	bool isUnityCoords = true;

public:
	// 생성자
	Transform()
		: position({ 0.0f, 0.0f }), rotation(0.0f), scale({1.0f, 1.0f}) { }

	void OnEnd() override;

	// get, set
	D2D1_VECTOR_2F GetPosition() const { return position; }
	void SetPosition(float x, float y) { dirty = true; position.x = x; position.y = y; }

	float GetRotation() const { return rotation; }
	void SetRotation(float rotValue) { dirty = true; rotation = rotValue; }

	D2D1_VECTOR_2F GetScale() const { return scale; }
	void SetScale(float scaleX, float scaleY) { dirty = true; scale.x = scaleX; scale.y = scaleY; }

	Transform* GetParent() const { return parent; }
	void SetParent(Transform* t) { parent = t; }

	bool IsUnityCoords() { return isUnityCoords; }
	void SetIsUnityCoords(bool value) { isUnityCoords = value; }

	bool IsDirty();

	/// <summary>
	/// 매트릭스로 transform 값 설정
	/// </summary>
	void SetTransformToMatrix(D2D1_MATRIX_3X2_F matrix);

	/// <summary>
	/// 로컬 매트릭스 반환
	/// </summary>
	D2D1_MATRIX_3X2_F ToLocalMatrix();

	/// <summary>
	/// 현재 로컬 좌표의 역행렬
	/// </summary>
	D2D1_MATRIX_3X2_F ToLocalInvertMatrix();

	/// <summary>
	/// 월드 매트릭스 반환
	/// </summary>
	D2D1_MATRIX_3X2_F ToWorldMatrix();

	/// <summary>
	/// 현재 월드 좌표의 역행렬
	/// </summary>
	D2D1_MATRIX_3X2_F ToWorldInvertMatrix();

	/// <summary>
	/// 모든 값을 초기화 ( scale은 (1,1) , 나머지 다 0으로 초기화 )
	/// </summary>
	void Reset();
};