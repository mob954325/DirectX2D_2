#pragma once
#include "Utils/Singleton.h"
#include "Components/Physics/PhysicComponent.h"

class PhysicSystem : public Singleton<PhysicSystem>
{
public:
	friend class Singleton<PhysicSystem>;

	void Reister(PhysicComponent* comp);
	void UnRegister(PhysicComponent* comp);
	void ClearAll();

	void FixedUpdate();
private:
	PhysicSystem() = default;
	~PhysicSystem();

	std::vector<PhysicComponent*> components;
};