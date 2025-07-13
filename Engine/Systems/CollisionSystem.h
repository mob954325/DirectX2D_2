#pragma once
#include "Utils/Singleton.h"
#include "Components/Collision/CollisionComponent.h"
#include <Components/Physics/PhysicComponent.h>

class CollisionSystem : public Singleton<CollisionSystem>
{
public:
	friend class  Singleton<CollisionSystem>;

	void Register(CollisionComponent* comp);
	void UnRegister(CollisionComponent* comp);
	void ClearAll();

	void FixedUpdate();
private:
	CollisionSystem() = default;
	~CollisionSystem();

	std::vector<CollisionComponent*> components;
};

