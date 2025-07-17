#pragma once
#include "Utils/Singleton.h"
#include "Components/Collision/CollisionComponent.h"
#include "Components/Physics/PhysicComponent.h"
#include "Datas/CollisionInfo.h"
#include "unordered_map"
#include "set"

using Pair = std::pair<GameObject*, GameObject*>;

struct ColliderPair
{
	Pair pair;
	CollisionInfo info;

	ColliderPair(const Pair& p, const CollisionInfo& i = {}) : pair(p), info(i) {}

	bool operator<(const ColliderPair& other) const {
		return pair < other.pair;
	}
};

class CollisionSystem : public Singleton<CollisionSystem>
{
public:
	friend class  Singleton<CollisionSystem>;

	void Register(CollisionComponent* comp);
	void UnRegister(CollisionComponent* comp);
	void ClearAll();

	void FixedUpdate(std::vector<CollisionInfo>& outInfos);
private:
	CollisionSystem() = default;
	~CollisionSystem();

	void EventUpdate(std::vector<CollisionInfo>& infos);
	void CallEvent(GameObject* a, GameObject* b, const std::string& type);

	std::set<Pair> prevPairs;
	std::vector<CollisionComponent*> components;
};

