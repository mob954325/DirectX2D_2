#include "RenderSystem.h"

void RenderSystem::Regist(RenderComponent* comp)
{
	components.push_back(comp);
	comp->SetRenderManager(renderManager);
}

void RenderSystem::UnRegist(RenderComponent* comp)
{
	std::vector<RenderComponent*>::iterator it = components.begin();

	for (; it != components.end(); it++)
	{
		if (comp == *it)
		{
			components.erase(it);
			break;
		}
	}
}

void RenderSystem::ClearAll()
{
	components.clear(); // 리스트 내용만 제거
}

void RenderSystem::Update(D2DRenderManager* manager)
{
	assert(manager && "D2DRenderManager is nullptr");

	for (RenderComponent* comp : components)
	{
		comp->Render(manager);
	}
}
