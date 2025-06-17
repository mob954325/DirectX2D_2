#include "GameObject.h"

GameObject::GameObject()
{
	transform = new Transform();
}

GameObject::~GameObject()
{
	delete transform;

	std::vector<Component*>::iterator it = components.begin();
	for (; it != components.end(); it++)
	{
		components.erase(it);
	}

	components.clear();
}

void GameObject::RegisterComponentWithSystemManager(Component* comp)
{
	Singleton<SystemManager>::GetInstance().RegisterComponent(comp);
}