#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/Rendering/AnimationRenderer.h"
#include "Components/Logic/InputSystem.h"
#include "components/Collision/AABBCollider.h"
#include "Components/Physics/Rigidbody2D.h"
#include "Components/Logic/StatComponent.h"
#include "Components/Rendering/TextRenderer.h"
#include "Utils/EventDelegate.h"

namespace Test_PlatformerGame
{
	class TestPlatformerGame_TestPlayer : public MonoBehavior
	{
	public:
		void OnCreate() override;
		void OnStart() override;
		void OnFixedUpdate() override;
		void OnUpdate() override;
		void OnDestroy() override;

	private:
		void HanldeHpText();
		TextRenderer* hpText;

		AnimationRenderer* anim;
		InputSystem* input;
		AABBCollider* collider;
		Rigidbody2D* rigid;

		StatComponent* hpStat;
		EventDelegate<int> onHit;
		int hp = 0;
	};
}
