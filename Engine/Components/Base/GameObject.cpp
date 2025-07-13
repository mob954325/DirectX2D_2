#include "GameObject.h"
#include "Systems/RenderSystem.h"
#include "Systems/ScriptSystem.h"
#include "Systems/CollisionSystem.h"

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
		RemoveComponentToSystem(*it);
		it = components.erase(it);
	}

	components.clear();
}

void GameObject::RemoveComponent(Component* targetComp)
{
	for (auto it = components.begin(); it != components.end();)
	{
		if (*it == targetComp)
		{
			RemoveComponentToSystem(*it);
			delete* it;
			it = components.erase(it);
		}
		else
		{
			++it;
		}
	}
}

void GameObject::DispatchComponentToSystem(Component* comp)
{
	if (ScriptComponent* sc = dynamic_cast<ScriptComponent*>(comp))
	{
		Singleton<ScriptSystem>::GetInstance().Register(sc);
	}
	else if (RenderComponent* rc = dynamic_cast<RenderComponent*>(comp))
	{
		Singleton<RenderSystem>::GetInstance().Register(rc);
	}
	else if (CollisionComponent* cc = dynamic_cast<CollisionComponent*>(comp))
	{
		Singleton<CollisionSystem>::GetInstance().Register(cc);
	}
}

void GameObject::RemoveComponentToSystem(Component* comp)
{
	if (ScriptComponent* sc = dynamic_cast<ScriptComponent*>(comp))
	{
		Singleton<ScriptSystem>::GetInstance().UnRegist(sc);
	}
	else if (RenderComponent* rc = dynamic_cast<RenderComponent*>(comp))
	{
		Singleton<RenderSystem>::GetInstance().UnRegist(rc);
	}
	else if (RenderComponent* pc = dynamic_cast<RenderComponent*>(comp))
	{
		Singleton<RenderSystem>::GetInstance().Register(pc);
	}
}