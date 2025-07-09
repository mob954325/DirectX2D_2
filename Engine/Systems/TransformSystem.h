#pragma once
#include "Utils/Singleton.h"
#include "Components/Base/Transform.h"

class TransformSystem : public Singleton<TransformSystem>
{
public:
	friend class Singleton<TransformSystem>;

	void Register(Transform* pTransform);
	void Unregister(Transform* pTransform);
	void Update();
private:
	TransformSystem() = default;
	~TransformSystem();

	std::vector<Transform*> components;
};