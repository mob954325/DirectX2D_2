#include "GameObject.h"
#include "Systems/RenderSystem.h"
#include "Systems/ScriptSystem.h"
#include "Systems/CollisionSystem.h"
#include "Systems/PhysicSystem.h"
#include "Systems/TransformSystem.h"
#include "Systems/MonoBehaviorSystem.h"

GameObject::GameObject()
{
	transform = AddComponent<Transform>(); // GameObject는 무조건 Transform를 하나 소유함
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
	else if (PhysicComponent* pc = dynamic_cast<PhysicComponent*>(comp))
	{
		Singleton<PhysicSystem>::GetInstance().Register(pc);
	}
	else if (MonoBehavior* mb = dynamic_cast<MonoBehavior*>(comp))
	{
		Singleton<MonoBehaviorSystem>::GetInstance().Register(mb);
	}
}

void GameObject::RemoveComponentToSystem(Component* comp)
{
	if (ScriptComponent* sc = dynamic_cast<ScriptComponent*>(comp))
	{
		Singleton<ScriptSystem>::GetInstance().UnRegister(sc);
	}
	else if (RenderComponent* rc = dynamic_cast<RenderComponent*>(comp))
	{
		Singleton<RenderSystem>::GetInstance().UnRegister(rc);
	}
	else if (CollisionComponent* cc = dynamic_cast<CollisionComponent*>(comp))
	{
		Singleton<CollisionSystem>::GetInstance().UnRegister(cc);
	}
	else if (PhysicComponent* pc = dynamic_cast<PhysicComponent*>(comp))
	{
		Singleton<PhysicSystem>::GetInstance().UnRegister(pc);
	}
	else if (Transform* t = dynamic_cast<Transform*>(comp))
	{
		Singleton<TransformSystem>::GetInstance().Unregister(t); // NOTE: 시스템 추가는 addGameObject에서 하고 있음
	}
	else if (MonoBehavior* mb = dynamic_cast<MonoBehavior*>(comp))
	{
		Singleton<MonoBehaviorSystem>::GetInstance().Register(mb);
	}
}