#pragma once
#include "Component.h"

class D2DRenderManager;
class ResourceManager;

class RenderComponent : public Component
{
public:
	RenderComponent() = default;
	virtual ~RenderComponent() = default;

	virtual void Render(D2DRenderManager* manager) = 0;
	void SetRenderManager(D2DRenderManager* pManager) { renderManager = pManager; }
	void SetResourceManager(ResourceManager* pManager) { resourceManager = pManager; }

protected:	
	D2DRenderManager* renderManager{}; // NOTE : 나중에 제거할 것
	ResourceManager* resourceManager{};
};