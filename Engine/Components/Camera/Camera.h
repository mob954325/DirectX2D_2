#pragma once
#include "Components/Base/Component.h"
#include "Components/Base/Transform.h"

/// <summary>
/// 카메라 기능이 있는 컴포넌트
/// </summary>
/// <remarks>
/// 해당 컴포넌트를 사용할 때 부착한 오브젝트의 트랜스폼을 SetTransform 함수로 넘겨줘야함
/// 그렇지 않으면 내부적으로 기본 트랜스폼 생성해서 반환
/// 
/// 25 06 18 : SceneManager에 카메라 추가해야 카메라 적용됨
/// </remarks>
class Camera : public Component
{
public:
	void OnStart() override;	// 임시
	void OnDestroy() override;

	bool IsMainCamera();
	void SetIsMainCamera(bool value);
	void AttachGameObjectToCamera(Transform* pTransform);
	D2D1_MATRIX_3X2_F GetMatrix() const;
	D2D1_MATRIX_3X2_F GetInvertMatrix() const;

	Transform& GetTransform() const;
private:
	bool isMainCamera = false;
	bool isLocalTransform = false;	  // 참조한 트랜스폼이 아닌 직접 만든 트랜스폼인지 확인하는 변수
	Transform* gameObjectTransform{}; // 이걸 부착한 게임 오브젝트의 트랜스폼을 참조
	Transform* localTransform{};	  // 카메라가 가지고 있는 Transform
};

