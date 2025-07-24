#pragma once
#include "Scene/SceneManager.h"

namespace Test_PlatformerGame
{
	class MainMenu : public Scene
	{
	protected:
		void OnEnterImpl() override;
		void UpdateImpl() override;
		void OnExitImpl() override;
	private:
		GameObject* menuObj;
	};	
}
