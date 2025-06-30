#include "RenderSystem.h"
#include "GameObject.h"

RenderSystem::~RenderSystem()
{
	if (!renderComponentGroup.empty())
	{
		renderComponentGroup.clear();
	}
}

void RenderSystem::Register(RenderComponent* comp)
{
	renderComponentGroup[comp->owner->GetRenderLayer()].push_back(comp);
	comp->SetRenderManager(renderManager);
	comp->SetResourceManager(resourceManager);
}

void RenderSystem::UnRegist(RenderComponent* comp)
{
	auto groupIt = renderComponentGroup.find(comp->owner->GetRenderLayer());
	auto comps = (*groupIt).second;
	auto it = comps.begin();

	for (; it != comps.end(); it++)
	{
		if ((*it) == comp) // 컴포넌트 찾음
		{
			comps.erase(it);
			break;
		}
	}
}

void RenderSystem::InitializeRenderLayers()
{
	for (int i = 0; i < EngineData::RenderLayer::LayerCount; i++)
	{
		renderComponentGroup[(EngineData::RenderLayer)i] = std::vector<RenderComponent*>();
	}
}

/// <summary>
/// 컴포넌트 리스트만 제거
/// </summary>
/// <remarks>
/// 각 컴포넌트들은 씬에서 게임오브젝트를 해제할 때 같이 제거되므로 리스트 내용만 제거 되도록 처리
/// </remarks>
void RenderSystem::ClearAll()
{
	renderComponentGroup.clear();
}

void RenderSystem::Update(D2DRenderManager* manager)
{
	assert(manager && "D2DRenderManager is nullptr");

	for (auto group : renderComponentGroup)
	{
		for (auto comp : group.second)
		{
			comp->Render(manager);
		}
	}
}