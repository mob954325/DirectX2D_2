#pragma once
#include "GameObject.h"

/// <summary>
/// Unity의 MonoBehavior 역할
/// </summary>
class BaseScript
{
public:
	virtual ~BaseScript() = default;

	virtual void OnStart() {}		// 처음 활성화될 때 (Init용)
	virtual void OnUpdate() {}		// 매 프레임 실행
	// virtual void OnFixedUpdate() {} // 물리 업데이트 (고정 시간)
	virtual void OnDestroy() {}		// 삭제 시 호출

	GameObject* owner{};
};