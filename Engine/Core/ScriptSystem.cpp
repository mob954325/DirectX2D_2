﻿#include "Core/ScriptSystem.h"

ScriptSystem::~ScriptSystem()
{
	std::vector<ScriptComponent*>::iterator it = components.begin();

	for (; it != components.end();)
	{
		it = components.erase(it);
	}

	components.clear();
}

void ScriptSystem::Register(ScriptComponent* comp)
{
	components.push_back(comp);
}

void ScriptSystem::UnRegist(ScriptComponent* comp)
{
	std::vector<ScriptComponent*>::iterator it = components.begin();

	for (; it != components.end(); it++)
	{
		if (comp == *it)
		{
			components.erase(it);
			break;
		}
	}
}

void ScriptSystem::ClearAll()
{
	components.clear();
}

void ScriptSystem::Update()
{
	for (ScriptComponent* comp : components)
	{
		comp->Update();
	}
}