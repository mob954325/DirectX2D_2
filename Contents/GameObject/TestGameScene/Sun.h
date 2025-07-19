#pragma once
#include "Components/Base/GameObject.h"
#include "Components/Rendering/BitmapRenderer.h"
#include "Components/Collision/AABBCollider.h"
#include "Components/Rendering/BoxComponent.h"

class Sun : public GameObject
{
public:
	void Start() override;
	void Update() override;
	void OnDestroy() override;

protected:
	BitmapRenderer* bitmapRenderer {};
	AABBCollider* aabbCollision{};
	BoxComponent* box{};

	float baseRotateSpeed = 360.0f;	
	float sunRotateRatio = 0.1f;
};

