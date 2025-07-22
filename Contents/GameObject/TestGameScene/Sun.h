#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/Rendering/BitmapRenderer.h"
#include "Components/Collision/AABBCollider.h"
#include "Components/Rendering/BoxComponent.h"

class Sun : public MonoBehavior
{
public:
	void OnStart() override;
	void OnUpdate() override;
	void OnDestroy() override;

protected:
	BitmapRenderer* bitmapRenderer {};
	AABBCollider* aabbCollision{};
	BoxComponent* box{};

	float baseRotateSpeed = 360.0f;	
	float sunRotateRatio = 0.1f;
};

