#include "Systems/CollisionSystem.h"

void CollisionSystem::Register(CollisionComponent* comp)
{
	components.push_back(comp);
}

void CollisionSystem::UnRegister(CollisionComponent* comp)
{
	std::vector<CollisionComponent*>::iterator it = components.begin();

	for (; it != components.end(); it++)
	{
		if (comp == *it)
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

void CollisionSystem::FixedUpdate()
{
	for (CollisionComponent* comp : components)
	{
		comp->FixedUpdate(components);
	}
}

CollisionSystem::~CollisionSystem()
{
	if (!components.empty())
	{
		components.clear();
	}
}
