#pragma once
#include "Components/Base/Component.h"
#include "Components/Collision/ICollider.h"

struct Bounds
{
	// vector3 center;	// bounding box의 중앙
	// vector3 extents;	// bounding box의 범위 -> 항상 bounds 크기의 절반 값
};

class CollisionComponent : public Component
{
public:
	virtual void FixedUpdate(const std::vector<CollisionComponent>& others) = 0;

	void SetTrigger(bool value);
	bool IsTrigger();

	ICollider* collider = nullptr; // 인터페이스 주입하기

protected:
	ColliderType type;

private:
	bool isTrigger = false;
};