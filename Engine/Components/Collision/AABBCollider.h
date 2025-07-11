#pragma once
#include "Components/Collision/CollisionComponent.h"
#include "Components/Rendering/BoxComponent.h"

/// <summary>
/// owner의 transform의 값을 기준으로 AABB 충돌 판정 컴포넌트
/// </summary>
class AABB : public CollisionComponent, ICollider
{
public:
	void FixedUpdate(const std::vector<CollisionComponent>& others) override;

	ColliderType GetColliderType() override;
	Vector2 GetCenter() const override;

	// 충돌 확인용 인터페이스
	bool CheckCollision(ICollider* other) const override;

	void OnCreate() override;
	void SetSize(float width, float height, float size);

private:
	BoxComponent* box; // 디버깅용

	float width = 0; 
	float height = 0;
	float size = 1.0f;
};