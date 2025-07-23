#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/Collision/AABBCollider.h"
#include "Components/Rendering/BoxComponent.h"

class TestWall : public MonoBehavior
{
public:
	void OnStart() override;
	void OnUpdate() override;
	void OnDestroy() override;

private:
	BoxComponent* box;
	AABBCollider* aabb;
};

