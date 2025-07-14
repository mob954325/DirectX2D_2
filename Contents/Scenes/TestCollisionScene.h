#pragma once
#include "Scene/Scene.h"
#include "Components/Base/GameObject.h"

class TestCollisionScene : public Scene 
{
protected:
	void OnEnterImpl() override;
	void OnExitImpl() override;
	void UpdateImpl() override;

private:
	GameObject* player{};
	GameObject* ground{};

	GameObject* m_MainCamera{};
};

