#include "PhysicSystem.h"

void PhysicSystem::Register(PhysicComponent* comp)
{
	components.push_back(comp);
}

void PhysicSystem::UnRegister(PhysicComponent* comp)
{
	auto it = components.begin();

	for (; it != components.end();)
	{
		if (*it == comp)
		{
			components.erase(it);
			break;
		}
	}
}

void PhysicSystem::ClearAll()
{
	components.clear();
}

void PhysicSystem::FixedUpdate()
{
	for (auto comp : components)
	{
		comp->FixedUpdate();
	}
}

PhysicSystem::~PhysicSystem()
{
	auto it = components.begin();

	for (; it != components.end();)
	{
		it = components.erase(it);
	}

	components.clear();
}
