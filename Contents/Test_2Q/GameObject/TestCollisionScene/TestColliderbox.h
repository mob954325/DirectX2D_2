#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/Collision/AABBCollider.h"
#include "Components/Rendering/BoxComponent.h"
#include "Components/Physics/Rigidbody2D.h"
#include "Components/Rendering/TextRenderer.h"

class TestColliderbox : public MonoBehavior
{
public:
	void OnStart() override;
	void OnUpdate() override;
	void OnDestroy() override;

private:
	BoxComponent* box;
	AABBCollider* aabb;
	Rigidbody2D* rigid;
	TextRenderer* text;
};

