#pragma once
#include "Components/Base/GameObject.h"
#include "Components/Collision/AABBCollider.h"
#include "Components/Rendering/BoxComponent.h"

class TestWall : public GameObject
{
public:
	void Start() override;
	void Update() override;
	void OnDestroy() override;

private:
	BoxComponent* box;
	AABBCollider* aabb;
};

