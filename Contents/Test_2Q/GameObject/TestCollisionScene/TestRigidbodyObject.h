#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/Rendering/BitmapRenderer.h"
#include "Components/Logic/InputSystem.h"
#include "Components/Rendering/BoxComponent.h"
#include "Components/Rendering/TextRenderer.h"
#include "Components/Collision/AABBCollider.h"
#include "Components/Physics/Rigidbody2D.h"

namespace Test_2QApp
{
	class TestRigidbodyObject : public MonoBehavior
	{
	public:
		void OnStart() override;
		void OnUpdate() override;
		void OnFixedUpdate() override;
		void OnDestroy() override;

		void OnColliderEnter(GameObject* collider) override;
		void OnColliderStay(GameObject* collider) override;
		void OnColliderExit(GameObject* collider) override;
		void OnTriggerEnter(GameObject* collider) override;
		void OnTriggerStay(GameObject* collider) override;
		void OnTriggerExit(GameObject* collider) override;

	private:

		void HandleMoveInput();
		void HandleDynamicMoveInput();

		BitmapRenderer* sprite;
		InputSystem* input;
		Rigidbody2D* rigid;
		TextRenderer* playerPosText{};
		TextRenderer* GuideText{};
		TextRenderer* showTypeText{};

		BoxComponent* box{};
		AABBCollider* aabb{};

		float physicSpeed = 2000;
		float normalSpeed = 1000;
	};

}