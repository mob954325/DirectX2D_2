#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/Collision/AABBCollider.h"
#include "Components/Physics/Rigidbody2D.h"
#include "Components/Rendering/TextRenderer.h"

namespace Test_2QApp
{
	class PressuerPlate : public MonoBehavior
	{
	public:
		void OnStart() override;
		void OnUpdate() override;
		void OnDestroy() override;

		void OnTriggerEnter(GameObject* collider) override;
		void OnTriggerStay(GameObject* collider) override;
		void OnTriggerExit(GameObject* collider) override;
	private:

		BoxComponent* box{};
		AABBCollider* aabb{};
		TextRenderer* text{};
		TextRenderer* alarmText{};
	};
}
