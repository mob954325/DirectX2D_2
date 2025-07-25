﻿#pragma once
#include "Application/Application.h"
#include "Scene/Scene.h"

namespace Test_2QApp
{
	enum SceneType
	{
		Menu = 0,
		Game
	};

	class DemoGameApp : public Application
	{
	public:
		void Initialize() override;
		void Render() override;
		void Uninitialize() override;
		void Update() override;
	};
}