﻿#pragma once
#include "Scene/Scene.h"
#include "Components/Base/GameObject.h"

namespace Test_2QApp
{
	class TestCollisionScene : public Scene 
	{
	protected:
		void OnEnterImpl() override;
		void OnExitImpl() override;
		void UpdateImpl() override;

	private:
		GameObject* player{};
		GameObject* ground{};
		GameObject* rightWall{};
		GameObject* leftWall{};
		GameObject* boxGenerator{};
		GameObject* doorButton{};

		GameObject* m_MainCamera{};
	};
}