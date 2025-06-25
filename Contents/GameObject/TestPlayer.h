#pragma once
#include "Component/Base/GameObject.h"
#include "Component/AnimationRenderer.h"
#include "Component/Camera.h"
#include "Component/InputSystem.h"
#include "Component/StatComponent.h"
#include "Component/TextRenderer.h"
#include "Component/BoxComponent.h"
#include "Utility/EventDelegate.h"

class TestPlayer : public GameObject
{
public:
	void Start() override;
	void Update() override;
	void OnDestroy() override;

private:

	void Move();
	void CamMove();
	void UpdateRectPosition();

	void OnHit(int dmg);

	Camera* playerMainCam{};
	AnimationRenderer* idleBitmap{};
	InputSystem* input{};
	StatComponent* hpComp{};
	TextRenderer* text{};
	BoxComponent* box{};

	EventDelegate<int> OnHitAction; // 피격시 호출되는 델리게이트

	float speed = 5.0f;
	int maxHp = 10;
};

