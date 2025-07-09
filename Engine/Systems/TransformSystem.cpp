#include "TransformSystem.h"

void TransformSystem::Register(Transform* pTransform)
{
	components.push_back(pTransform);
}

void TransformSystem::Unregister(Transform* pTransform)
{
	auto it = components.begin();
	for (; it != components.end();)
	{
		if (*it == pTransform)
		{
			components.erase(it);
			break;
		}

		it++;
	}
}

void TransformSystem::Update()
{	
	for (auto comp : components)
	{
		comp->CalculateFinalMatrix();
	}

	for (auto comp : components)
	{
		comp->ResetDirty();
	}
}

TransformSystem::~TransformSystem()
{
	components.clear();
}
