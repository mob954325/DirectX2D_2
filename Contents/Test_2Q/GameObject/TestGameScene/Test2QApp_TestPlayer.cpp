﻿#include "Test2QApp_TestPlayer.h"
#include "Utils/Singleton.h"
#include "Utils/GameTime.h"
#include "Scene/SceneManager.h"
#include "Utils/DebugUtility.h"
#include "Resources/Loaders/AnimationControllerLoader.h"
#include "Components/Camera/CameraManager.h"

#include <string>
#include <iostream>

namespace Test_2QApp
{
	void Test2QApp_TestPlayer::OnStart()
	{
		owner->SetRenderLayer(EngineData::RenderLayer::Player);

		// Player camera init
		playerMainCam = owner->AddComponent<Camera>();
		Singleton<CameraManager>::GetInstance().Register(new CameraInfo(playerMainCam->GetPriority(), playerMainCam));
		playerMainCam->SetPriority(11);

		// animation renderer init
		idleBitmap = owner->AddComponent<AnimationRenderer>();
		idleBitmap->CreateBitmapResource(L"../Resource/ken.png");
		idleBitmap->SetSpriteSheet(L"../Resource/Json/ken_sprites.json");
		idleBitmap->SetAnimationClip(L"../Resource/Json/Dead_Normal_anim.json");
		idleBitmap->Play();
		idleBitmap->SetFlip(true);

		// set transform
		owner->GetTransform().SetUnityCoords(true);
		owner->GetTransform().SetScale(1.0f, 1.0f);

		// input init
		input = owner->AddComponent<InputSystem>();

		// statcomponent(hp) init
		hpComp = owner->AddComponent<StatComponent>();
		hpComp->ChangeStat(maxHp);
		OnHitAction += hpComp->GetValueFunctionObject();

		// text init
		hpText = owner->AddComponent<TextRenderer>();
		hpText->SetPosition(700, 20);

		std::wstring str = L"Hp : ";
		str += std::to_wstring(hpComp->GetValue());
		hpText->SetText(str);

		// box component init
		box = owner->AddComponent<BoxComponent>();
		box->SetIsShow(true);
		box->SetWidth(2.0f);
		D2D1_SIZE_F size = idleBitmap->GetResource().get()->GetBitmap()->GetSize();

		Vector2 posVec = owner->GetTransform().GetPosition();
		box->SetRect(
			{
				-60 * 0.5f,
				-60 * 0.5f,
				60 * 0.5f,
				60 * 0.5f
			}
		);

		// animFramText init
		animFramText = owner->AddComponent<TextRenderer>();
		animFramText->SetViewportPosition(0.8f, 0.1f);

		// animator init
		//animator = AddComponent<Animator>();
		//animator->SetAnimationController(L"../Resource/Json/TestPlayer_AnimController.json");

		AnimationControllerLoader::LoadAnimatorController(L"../Resource/Json/TestPlayer_AnimController.json", ac);
		fsmInstance = owner->AddComponent<FSMInstance>();
		fsmInstance->SetAnimationController(ac);

		// state 클래스들 초기화
		idleState = new IdleState();
		idleState->player = this;
		moveState = new MoveState();
		moveState->player = this;
		hitState = new HitState();
		hitState->player = this;
		deadState = new DeadState();
		deadState->player = this;
		attackState = new AttackState();
		attackState->player = this;

		fsmInstance->SetStateBehavior("Idle", idleState);
		fsmInstance->SetStateBehavior("Move", moveState);
		fsmInstance->SetStateBehavior("Hit", hitState);
		fsmInstance->SetStateBehavior("Dead", deadState);
		fsmInstance->SetStateBehavior("Attack", attackState);

		fsmInstance->OnStart();

		// player position text init
		playerPosText = owner->AddComponent<TextRenderer>();
		playerPosText->SetViewportPosition(0.5f, 0.9f);

		// player collider init
		aabbCollider = owner->AddComponent<AABBCollider>();
		aabbCollider->SetSize(129, 129, 1);

		rigid = owner->AddComponent<Rigidbody2D>();
		rigid->SetGravity(true);

		owner->GetTransform().SetPosition(0, 200);
	}

	void Test2QApp_TestPlayer::OnUpdate()
	{
		animFramText->SetText(L"현재 애니메이션 프레임 : " + std::to_wstring(idleBitmap->GetFrame()));

		//if (input->IsKeyPressed('M')) // IGameObjectQuery로 게임 오브젝트 찾기 테스트
		//{
		//	GameObject* sun = query->FindByName("Sun11");
		//	if (sun != nullptr)
		//	{
		//		DebugUtility::Print("--- Found Sun !!");
		//	}
		//	else
		//	{
		//		DebugUtility::Print("--- Target Sun is not exist");
		//	}
		//}

		if (input->IsKeyPressed('N'))
		{
			fsmInstance->SetTrigger("attack");
		}

		HandleCameraInput();
		HandleHitInput();
		HandleMoveInput();
		HandlePlayerCameraInput();
		HandleAnimationInput();

		std::wstring str = L"x : ";
		str += std::to_wstring(owner->GetTransform().GetPosition().x);
		str += L" y : ";
		str += std::to_wstring(owner->GetTransform().GetPosition().y);
		playerPosText->SetText(str);
	}

	void Test2QApp_TestPlayer::OnDestroy()
	{
		delete idleState;
		delete moveState;
		delete hitState;
	}

	void Test2QApp_TestPlayer::HandleMoveInput()
	{
		if (input == nullptr) return;

		Vector2 position = owner->GetTransform().GetPosition();
		Vector2 moveVec = { 0,0 };

		if (input->IsKeyDown(VK_RIGHT))
		{
			moveVec.x += speed;
		}
		if (input->IsKeyDown(VK_LEFT))
		{
			moveVec.x -= speed;
		}
		if (input->IsKeyDown(VK_UP))
		{
			moveVec.y += speed;
		}
		if (input->IsKeyDown(VK_DOWN))
		{
			moveVec.y -= speed;
		}

		// fsm 움직임 갱신
		if (moveVec.x == 0 && moveVec.y == 0)
		{
			fsmInstance->SetFloat("speed", 0);
		}
		else
		{
			fsmInstance->SetFloat("speed", 1);
		}

		owner->GetTransform().SetPosition(position.x + moveVec.x, position.y + moveVec.y);
	}

	void Test2QApp_TestPlayer::HandlePlayerCameraInput()
	{
		if (input == nullptr) return;

		Vector2 inputVec = { 0,0 };

		if (input->IsKeyDown('K'))
		{
			inputVec.y -= 1.0f;
		}
		if (input->IsKeyDown('I'))
		{
			inputVec.y += 1.0f;
		}
		if (input->IsKeyDown('J'))
		{
			inputVec.x -= 1.0f;
		}
		if (input->IsKeyDown('L'))
		{
			inputVec.x += 1.0f;
		}

		Vector2 positionVec = playerMainCam->GetTransform().GetPosition();
		Vector2 moveVec = { inputVec.x * camSpeed, inputVec.y * camSpeed };

		playerMainCam->GetTransform().SetPosition(positionVec.x + moveVec.x, positionVec.y + moveVec.y);
	}

	void Test2QApp_TestPlayer::HandleHitInput()
	{
		// 체력 이벤트 인풋
		if (input->IsKeyPressed('H'))
		{
			int dmg = 1;
			OnHit(dmg);
		}
		else if (input->IsKeyPressed('J'))
		{
			hpComp->ChangeStat(maxHp);

			std::wstring hpStr = L"Hp : ";
			hpStr += std::to_wstring(hpComp->GetValue());
			hpText->SetText(hpStr);

			fsmInstance->SetBool("isDead", false); // fsm 사망상태 탈출
		}
	}

	void Test2QApp_TestPlayer::HandleCameraInput()
	{
		// 카메라 설정 인풋
		if (input->IsKeyPressed('Y'))
		{
			playerMainCam->SetPriority(1);
		}
		else if (input->IsKeyPressed('U'))
		{
			playerMainCam->SetPriority(11);
		}
	}

	void Test2QApp_TestPlayer::HandleAnimationInput()
	{
		//if (input->IsKeyPressed('1'))
		//{
		//	idleBitmap->SetAnimationClip(L"../Resource/Json/Attack_Front_anim.json");
		//}
		//if (input->IsKeyPressed('2'))
		//{
		//	idleBitmap->SetAnimationClip(L"../Resource/Json/Attack_Up_anim.json");
		//}
		//if (input->IsKeyPressed('3'))
		//{
		//	idleBitmap->SetAnimationClip(L"../Resource/Json/Idle_Right_anim.json");
		//}
	}

	void Test2QApp_TestPlayer::OnHit(int dmg)
	{
		int currentHp = hpComp->GetValue();

		// set Text
		std::wstring str = L"Hp : ";
		str += std::to_wstring(hpComp->GetValue());
		hpText->SetText(str);

		// check hp
		if (currentHp <= 0)
		{
			// fsm 사망상태 활성화
			fsmInstance->SetBool("isDead", true);
			fsmInstance->SetTrigger("dead");
		}
		else
		{
			OnHitAction.Invoke(currentHp - dmg);
			fsmInstance->SetTrigger("hit"); // fsm 피격 상태 활성화
		}
	}

	// idle
	void IdleState::OnStateEnter()
	{
		player->GetRenderer()->SetAnimationClip(L"../Resource/Json/Idle_Right_anim.json");
	}

	void IdleState::OnStateUpdate()
	{
	}

	void IdleState::OnStateExit()
	{
	}

	// move
	void MoveState::OnStateEnter()
	{
		player->GetRenderer()->SetAnimationClip(L"../Resource/Json/Move_Front_anim.json");
	}

	void MoveState::OnStateUpdate()
	{
	}

	void MoveState::OnStateExit()
	{
	}

	// hit
	void HitState::OnStateEnter()
	{
		player->GetRenderer()->SetAnimationClip(L"../Resource/Json/Hit_Normal_anim.json");
	}

	void HitState::OnStateUpdate()
	{
	}

	void HitState::OnStateExit()
	{
	}

	// dead
	void DeadState::OnStateEnter()
	{
		player->GetRenderer()->SetAnimationClip(L"../Resource/Json/Dead_Normal_anim.json");
	}

	void DeadState::OnStateUpdate()
	{
	}

	void DeadState::OnStateExit()
	{
	}

	// attack
	void AttackState::OnStateEnter()
	{
		player->GetRenderer()->SetAnimationClip(L"../Resource/Json/Attack_Front_anim.json");
	}

	void AttackState::OnStateUpdate()
	{
	}

	void AttackState::OnStateExit()
	{
	}
}