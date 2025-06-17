#pragma once
#include "Component.h"
//#include "D2DRenderManager.h"

class D2DRenderManager;
class RenderComponent : public Component
{
public:
	RenderComponent() = default;
	~RenderComponent() = default;

	void OnStart() override {};

	virtual void Render(D2DRenderManager* manager) = 0;
	void SetRenderManager(D2DRenderManager* pManager) { renderManager = pManager; }

protected:	
	D2DRenderManager* renderManager{};
};