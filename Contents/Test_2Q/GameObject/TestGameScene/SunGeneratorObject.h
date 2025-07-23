#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/Rendering/BitmapRenderer.h"
#include "Components/Logic/InputSystem.h"
#include "Components/Rendering/TextRenderer.h"
#include <vector>

namespace Test_2QApp
{
	class SunGeneratorObject : public MonoBehavior
	{
	public:
		void OnStart() override;
		void OnUpdate() override;
		void OnDestroy() override;

	private:
		std::vector<GameObject*> objects;

		BitmapRenderer* bitmapRenderer{};
		TextRenderer* textRenderer{};
		InputSystem* input{};
	};
}