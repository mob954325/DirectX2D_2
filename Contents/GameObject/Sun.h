#pragma once
#include "Core/D2DRenderManager.h"
#include "Core/GameSystem.h"

#include "Base/GameObject.h"
#include "BitmapRenderer.h"

class Sun : GameObject
{
public:
	Sun(D2DRenderManager* renderManager, GameSystem* system) {}
	void Start() override;

protected:
	D2DRenderManager* renderManager;
	GameSystem* system;

	BitmapRenderer* bitmapRenderer;
};

