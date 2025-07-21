#include "MonoBehaviorSystem.h"

void MonoBehaviorSystem::Register(MonoBehavior* comp)
{
	components.push_back(comp);
}

void MonoBehaviorSystem::UnRegister(MonoBehavior* comp)
{
	for (auto it = components.begin(); it != components.end(); it++)
	{
		if (*it == comp)
		{
			components.erase(it);
			break;
		}
	}
}

void MonoBehaviorSystem::ClearAll()
{
	components.clear();
}

void MonoBehaviorSystem::Update()
{
	for (auto it = components.begin(); it != components.end(); it++)
	{
		if ((*it)->IsActiveSelf())
		{
			(*it)->OnUpdate();
		}
	}
}

MonoBehaviorSystem::~MonoBehaviorSystem()
{
	if (!components.empty())
	{
		ClearAll();
	}
}	
