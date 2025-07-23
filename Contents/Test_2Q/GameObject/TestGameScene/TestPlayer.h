#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/Rendering/AnimationRenderer.h"
#include "Components/Camera/Camera.h"
#include "Components/Logic/InputSystem.h"
#include "Components/Logic/StatComponent.h"
#include "Components/Rendering/TextRenderer.h"
#include "Components/Rendering/BoxComponent.h"
#include "Components/Logic/FSMInstance.h"
#include "Components/Collision/AABBCollider.h"
#include "Components/Physics/Rigidbody2D.h"

#include "Utils/EventDelegate.h"

class IdleState;
class MoveState;
class DeadState;
class HitState;
class AttackState;

class TestPlayer : public MonoBehavior
{
private:
	void HandleMoveInput();
	void HandlePlayerCameraInput();
	void HandleHitInput();
	void HandleCameraInput();
	void HandleAnimationInput();

	void OnHit(int dmg);

	Camera* playerMainCam{};
	AnimationRenderer* idleBitmap{};
	InputSystem* input{};
	StatComponent* hpComp{};
	BoxComponent* box{};

	TextRenderer* hpText{};
	TextRenderer* animFramText{};
	TextRenderer* playerPosText{};

	EventDelegate<int> OnHitAction; // 피격시 호출되는 델리게이트

	FSMInstance* fsmInstance{};
	AnimatorController ac{};

	IdleState* idleState;
	MoveState* moveState;
	HitState* hitState;
	DeadState* deadState;
	AttackState* attackState;

	AABBCollider* aabbCollider;
	Rigidbody2D* rigid;

	float speed = 2.0f;
	float camSpeed = 5.0f;
	int maxHp = 3;

public:
	void OnStart() override;
	void OnUpdate() override;
	void OnDestroy() override;

	AnimationRenderer* GetRenderer() { return idleBitmap; }
};

#pragma region States
class IdleState : public IStateBehaviorBase
{
public:
	TestPlayer* player;

	void OnStateEnter() override;
	void OnStateUpdate() override;
	void OnStateExit() override;
};

class MoveState : public IStateBehaviorBase
{
public:
	TestPlayer* player;

	void OnStateEnter() override;
	void OnStateUpdate() override;
	void OnStateExit() override;
};

class HitState : public IStateBehaviorBase
{
public:
	TestPlayer* player;

	void OnStateEnter() override;
	void OnStateUpdate() override;
	void OnStateExit() override;
};

class DeadState : public IStateBehaviorBase
{
public:
	TestPlayer* player;

	void OnStateEnter() override;
	void OnStateUpdate() override;
	void OnStateExit() override;
};

class AttackState : public IStateBehaviorBase
{
public:
	TestPlayer* player;

	void OnStateEnter() override;
	void OnStateUpdate() override;
	void OnStateExit() override;
};
#pragma endregion

