#pragma once
#include "Components/Base/GameObject.h"
#include "Components/Collision/AABBCollider.h"
#include "Components/Rendering/BoxComponent.h"
#include "Components/Physics/Rigidbody2D.h"
#include "Components/Rendering/TextRenderer.h"

class TestColliderbox : public GameObject
{
public:
	void Start() override;
	void Update() override;
	void OnDestroy() override;

private:
	BoxComponent* box;
	AABBCollider* aabb;
	Rigidbody2D* rigid;
	TextRenderer* text;
};

