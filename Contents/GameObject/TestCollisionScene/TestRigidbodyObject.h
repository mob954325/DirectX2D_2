#pragma once
#include "Components/Base/GameObject.h"
#include "Components/Rendering/BitmapRenderer.h"
#include "Components/Logic/InputSystem.h"
#include "Components/Rendering/BoxComponent.h"
#include "Components/Rendering/TextRenderer.h"
#include "Components/Collision/AABBCollider.h"
#include "Components/Physics/Rigidbody2D.h"

class TestRigidbodyObject : public GameObject
{
public:
	void Start() override;
	void Update() override;
	void OnDestroy() override;

	void OnColliderEnter(GameObject* collider) override;
	void OnColliderStay(GameObject* collider) override;
	void OnColliderExit(GameObject* collider) override;
	void OnTriggerEnter(GameObject* collider) override;
	void OnTriggerStay(GameObject* collider) override;
	void OnTriggerExit(GameObject* collider) override;

private:

	void HandleMoveInput();

	BitmapRenderer* sprite;
	InputSystem* input;
	Rigidbody2D* rigid;
	TextRenderer* playerPosText{};
	TextRenderer* GuideText{};
	TextRenderer* showTypeText{};

	BoxComponent* box{};
	AABBCollider* aabb{};

	float physicSpeed = 30000;
	float normalSpeed = 1000;
};

