#pragma once
#include "Core/D2DRenderManager.h"
#include "Core/ScriptSystem.h"

#include "Base/GameObject.h"
#include "BitmapRenderer.h"

// TODO : Bitmap 어떻게 생성할까?

class Sun : public GameObject
{
public:
	Sun(D2DRenderManager* renderManager, ScriptSystem* system) : renderManager(renderManager), system(system){}
	void Start() override;
	void OnDestory() override;

protected:
	D2DRenderManager* renderManager{};
	ScriptSystem* system{};

	BitmapRenderer* bitmapRenderer {};
};

