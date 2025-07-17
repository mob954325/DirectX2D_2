#include "Systems/CollisionSystem.h"

void CollisionSystem::Register(CollisionComponent* comp)
{
	components.push_back(comp);
}

void CollisionSystem::UnRegister(CollisionComponent* comp)
{
	auto it = components.begin();

	for (; it != components.end(); it++)
	{
		if (*it == comp)
		{
			components.erase(it);
			break;
		}
	}
}

void CollisionSystem::ClearAll()
{
	components.clear();
}

void CollisionSystem::FixedUpdate(std::vector<CollisionInfo>& outInfos)
{
	for (CollisionComponent* comp : components)
	{
		comp->FixedUpdate(components, outInfos);
	}

	EventUpdate(outInfos);
}

void CollisionSystem::EventUpdate(std::vector<CollisionInfo>& infos)
{
	std::set<Pair> currPairs;

	// 충돌 쌍 정규화 -> 이벤트 중복호출 방지용
	auto MakeKey = [](GameObject* a, GameObject* b) -> Pair
		{
			return (a < b) ? Pair(a, b) : Pair(b, a);
		};

	// 현재 충돌 쌍 저장
	for (auto it = infos.begin(); it != infos.end(); it++)
	{
		currPairs.insert(MakeKey(it->a, it->b));
	}

	// enter/stay
	for (const auto& pair : currPairs)
	{
		bool wasInPrev = prevPairs.find(pair) != prevPairs.end();
		auto* a = pair.first;
		auto* b = pair.second;

		if (wasInPrev)
		{
			CallEvent(a, b, "Stay");
		}
		else
		{
			CallEvent(a, b, "Enter");
		}
	}

	// exit
	for (const auto& pair : prevPairs)
	{
		if (currPairs.find(pair) == currPairs.end())
		{
			CallEvent(pair.first, pair.second, "Exit");
		}
	}

	// prev 갱신
	prevPairs = std::move(currPairs);
}

void CollisionSystem::CallEvent(GameObject* a, GameObject* b, const std::string& type)
{
	auto* collisionA = a->GetComponent<CollisionComponent>();
	auto* collisionB = b->GetComponent<CollisionComponent>();

	bool aTrigger = collisionA && collisionA->IsTrigger();
	bool bTrigger = collisionB && collisionB->IsTrigger();

	auto DoCall = [&](GameObject* caller, GameObject* target, bool trigger)
		{
			if (trigger)
			{
				if (type == "Enter") caller->OnTriggerEnter(target);
				else if (type == "Stay") caller->OnTriggerStay(target);
				else if (type == "Exit") caller->OnTriggerExit(target);
			}
			else
			{
				if (type == "Enter") caller->OnColliderEnter(target);
				else if (type == "Stay") caller->OnColliderStay(target);
				else if (type == "Exit") caller->OnColliderExit(target);
			}
		};

	DoCall(a, b, aTrigger);
	DoCall(b, a, bTrigger);
}

CollisionSystem::~CollisionSystem()
{
	if (!components.empty())
	{
		components.clear();
	}
}
