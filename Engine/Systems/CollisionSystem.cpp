#include "Systems/CollisionSystem.h"

void CollisionSystem::Register(CollisionComponent* comp)
{
	components.push_back(comp);
}

void CollisionSystem::UnRegister(CollisionComponent* comp)
{
	auto it = components.begin();

	for (; it != components.end(); it++)
	{
		if (*it == comp)
		{
			components.erase(it);
			break;
		}
	}
}

void CollisionSystem::ClearAll()
{
	components.clear();
}

void CollisionSystem::FixedUpdate(std::vector<CollisionInfo>& outInfos)
{
	for (CollisionComponent* comp : components)
	{
		comp->FixedUpdate(components, outInfos);
	}
}

CollisionSystem::~CollisionSystem()
{
	if (!components.empty())
	{
		components.clear();
	}
}
