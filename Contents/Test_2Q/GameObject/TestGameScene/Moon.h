﻿#pragma once
#include "Components/Base/MonoBehavior.h"
#include "Components/Rendering/BitmapRenderer.h"

namespace Test_2QApp
{
	class Moon : public MonoBehavior
	{
	public:
		void OnStart() override;
		void OnUpdate() override;
		void OnDestroy() override;

	protected:
		BitmapRenderer* bitmapRenderer{};
	};
}
