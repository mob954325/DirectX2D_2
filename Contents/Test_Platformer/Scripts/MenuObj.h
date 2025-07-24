#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/Rendering/BitmapRenderer.h"
#include "Components/Rendering/TextRenderer.h"
#include "Components/Logic/InputSystem.h"

// == 주요 이벤트 호출 함수 모음 == 
// void OnCreate() override;
// void OnStart() override;
// void OnFixedUpdate() override;
// void OnUpdate() override;
// void OnDestroy() override;

namespace Test_PlatformerGame
{
	class MenuObj : public MonoBehavior
	{
	public:
		void OnCreate() override;
		void OnStart() override;
		void OnFixedUpdate() override;
		void OnUpdate() override;
		void OnDestroy() override;

	private:
		BitmapRenderer* backGround; // 뒷 배경 
		TextRenderer* menuText;
		InputSystem* input;
	};	
}