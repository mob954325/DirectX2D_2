﻿#include "GameObject.h"
#include "RenderSystem.h"
#include "ScriptSystem.h"

class RenderComponent;
class ScriptComponent;
GameObject::GameObject()
{
	transform = AddComponent<Transform>();
}

GameObject::~GameObject()
{
	std::vector<Component*>::iterator it = components.begin();
	for (; it != components.end();)
	{
		(*it)->OnDestroy();
		it = components.erase(it);
	}

	components.clear();
}

void GameObject::RegisterComponentWithScriptSystem(Component* comp)
{
	if (ScriptComponent* sc = dynamic_cast<ScriptComponent*>(comp))
	{
		Singleton<ScriptSystem>::GetInstance().Regist(sc);
	}
	else if (RenderComponent* rc = dynamic_cast<RenderComponent*>(comp))
	{
		Singleton<RenderSystem>::GetInstance().Regist(rc);
	}
}