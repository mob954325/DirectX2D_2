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

private:

	void HandleMoveInput();

	BitmapRenderer* sprite;
	InputSystem* input;
	Rigidbody2D* rigid;
	TextRenderer* playerPosText{};

	BoxComponent* box;
	AABBCollider* aabb;

	float speed = 5000.0f;
};

