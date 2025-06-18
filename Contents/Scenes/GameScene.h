#pragma once
#include "Core/Scene.h"

class GameScene : public Scene
{
protected:
	void OnEnterImpl() override;
	void OnExitImpl() override;
	void UpdateImpl() override;

private:
	GameObject* m_MainCamera{};

	GameObject* m_Sun{};
	GameObject* m_Earth{};
	GameObject* m_Moon{};
	GameObject* m_TextObject{};
};