#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/Logic/InputSystem.h"
#include "Components/Camera/Camera.h"

namespace Test_2QApp
{
	class FreeCamera : public MonoBehavior
	{
	public:
		FreeCamera() {};
		~FreeCamera() {};

		void OnStart() override;
		void OnUpdate() override;
		void OnDestroy() override;

	private:
		Camera* camera{};
		InputSystem* inputSystem{};

		float cameraMoveSpeed = 5.0f;
	};
}