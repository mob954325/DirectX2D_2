#pragma once
#include "Core/Scene.h"

class MenuScene : public Scene
{
protected:
	void OnEnterImpl() override;
	void OnExitImpl() override;
	void UpdateImpl() override;

private:
};