#pragma once
#include "Scene/Scene.h"
#include "Components/Logic/InputSystem.h"

class TestGameScene : public Scene
{
protected:
	void OnEnterImpl() override;
	void OnExitImpl() override;
	void UpdateImpl() override;

private:
	GameObject* m_TestPlayer;

	GameObject* m_MainCamera{};

	GameObject* m_Sun{};
	GameObject* m_Earth{};
	GameObject* m_Moon{};
	GameObject* m_TextObject{};
	GameObject* m_SunGeneratorObject{};
	GameObject* m_TestAnim{};

	std::vector<GameObject*> objects;
};