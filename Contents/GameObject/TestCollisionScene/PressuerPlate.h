#pragma once
#include "Components/Base/GameObject.h"
#include "Components/Collision/AABBCollider.h"
#include "Components/Physics/Rigidbody2D.h"

class PressuerPlate : public GameObject
{
public:
	void Start() override;
	void Update() override;
	void OnDestroy() override;

	void OnTriggerEnter(GameObject* collider) override;
	void OnTriggerStay(GameObject* collider) override;
	void OnTriggerExit(GameObject* collider) override;
private:

	BoxComponent* box{};
	AABBCollider* aabb{};
};

