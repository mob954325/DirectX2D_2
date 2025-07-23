#pragma once
#include "Scene/Scene.h"
#include "Components/Base/GameObject.h"

namespace Test_2QApp
{
	class MenuScene : public Scene
	{
	protected:
		void OnEnterImpl() override;
		void OnExitImpl() override;
		void UpdateImpl() override;

	private:
		GameObject* menuObj;
	};
}