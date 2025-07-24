#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/Rendering/AnimationRenderer.h"
#include "Components/Logic/InputSystem.h"
#include "components/Collision/AABBCollider.h"
#include "Components/Physics/Rigidbody2D.h"

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
		AnimationRenderer* anim;
		InputSystem* input;
		AABBCollider* collider;
		Rigidbody2D* rigid;
	};
}
