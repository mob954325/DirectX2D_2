#pragma once
#include "Components/Base/GameObject.h"
#include "Components/Rendering/AnimationRenderer.h"
#include "Components/Camera/Camera.h"
#include "Components/Logic/InputSystem.h"
#include "Components/Logic/StatComponent.h"
#include "Components/Rendering/TextRenderer.h"
#include "Components/Rendering/BoxComponent.h"
#include "Components/Logic/FSMInstance.h"
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

	float speed = 5.0f;
};

