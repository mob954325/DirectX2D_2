#pragma once
#include "Utils/Singleton.h"
#include "Components/Base/MonoBehavior.h"

class MonoBehaviorSystem : public Singleton<MonoBehaviorSystem>
{
public:
	friend class Singleton<MonoBehaviorSystem>;

	void Register(MonoBehavior* comp);
	void UnRegister(MonoBehavior* comp);
	void ClearAll();

	void Update();

private:
	MonoBehaviorSystem() = default;
	~MonoBehaviorSystem();

	std::vector<MonoBehavior*> components;
};

