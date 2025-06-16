#include "GameSystem.h"

GameSystem::~GameSystem()
{
	std::vector<Component*>::iterator it = components.begin();

	for (; it != components.end(); it++)
	{
		components.erase(it);
	}

	components.clear();
}

void GameSystem::GetRenderManager(D2DRenderManager* manager)
{
	renderManager = manager;
}

void GameSystem::Regist(Component* comp)
{
	components.push_back(comp);
}

void GameSystem::UnRegist(Component* comp)
{
	std::vector<Component*>::iterator it = components.begin();

	for (; it != components.end(); it++)
	{
		if (comp == *it)
		{
			components.erase(it);
			break;
		}
	}
}

void GameSystem::Update()
{
	for (auto comp : components)
	{
		comp->Update();
	}
}

void GameSystem::Render(D2DRenderManager* IRenderer)
{
	assert(renderManager);

	for (Component* comp : components)
	{
		if (IRenderable* renderable = dynamic_cast<IRenderable*>(comp))
		{
			renderable->Render(renderManager);
		}
	}
}