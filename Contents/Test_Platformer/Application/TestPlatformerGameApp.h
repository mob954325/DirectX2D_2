#pragma once
#include "Application/Application.h"
#include "Scene/Scene.h"

namespace Test_PlatformerGame
{
	enum SceneType
	{
		Menu = 0,
		Game
	};

	class TestPlatformerGameApp : public Application
	{
	public:
		void Initialize() override;
		void Render() override;
		void Uninitialize() override;
		void Update() override;

	private:
		Scene* menuScene{};
	};
}