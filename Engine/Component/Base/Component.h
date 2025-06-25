#pragma once
class GameObject;

#include "pch.h"

/// <summary>
/// 모든 컴포넌트 클래스가 상속 받을 클래스
/// </summary>
class Component
{
public:
	Component() = default;
	virtual ~Component() = default;

	virtual void OnCreate() {};
	virtual void OnStart() {};
	virtual void OnEnd() {};
	virtual void OnDestroy() {};

	/// <summary>
	/// 해당 Component를 가지고 있는 게임 오브젝트
	/// </summary>
	GameObject* owner = nullptr;
};