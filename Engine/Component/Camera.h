#pragma once
#include "Base/Component.h"
#include "Base/Transform.h"

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
	void OnDestroy() override;

	bool IsMainCamera();
	void SetIsMainCamera(bool value);
	void SetTransform(Transform* pTransform);
	Transform* GetTransform();

private:
	bool isMainCamera = false;
	bool isLocalTransform = false;	  // 참조한 트랜스폼이 아닌 직접 만든 트랜스폼인지 확인하는 변수
	Transform* gameObjectTransform{}; // 이걸 부착한 게임 오브젝트의 트랜스폼을 참조
};

