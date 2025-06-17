#pragma once
#include "Core/Scene.h"
#include "Sun.h"

class GameScene : public Scene
{
protected:
	void OnEnterImpl() override;
	void OnExitImpl() override;
	void UpdateImpl() override;

private:
	Sun* m_Sun{};
};