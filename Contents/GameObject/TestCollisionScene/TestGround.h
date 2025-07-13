#pragma once
#include "Components/Base/GameObject.h"
#include "Components/Collision/AABBCollider.h"
#include "Components/Rendering/BoxComponent.h"
#include "Components/Logic/InputSystem.h"

class TestGround : public GameObject
{
public:
	void Start();
	void Update();
	void OnDestroy();

private:
	AABBCollider* aabb;
	BoxComponent* box;

	InputSystem* inputSystem;
};

