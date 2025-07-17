﻿#include "Systems/CollisionSystem.h"
#include "set"

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
	for (auto it = prevPairs.begin(); it != prevPairs.end(); )
	{
		if (it->pair.first->IsMarkedForRemoval() || it->pair.second->IsMarkedForRemoval())
		{
			it = prevPairs.erase(it);
		}
		else
		{
			it++;
		}
	}

	std::set<CollisionPair> currPairs;

	// 충돌 쌍 정규화 -> 이벤트 중복호출 방지용
	auto MakeKey = [](GameObject* a, GameObject* b) -> Pair
		{
			return (a < b) ? Pair(a, b) : Pair(b, a);
		};

	// 현재 충돌 쌍 저장
	for (auto it = infos.begin(); it != infos.end(); it++)
	{
		currPairs.insert(CollisionPair(MakeKey(it->a, it->b), *it));
	}

	// enter/stay
	for (const auto& collisionPair : currPairs)
	{
		bool wasInPrev = prevPairs.find(collisionPair) != prevPairs.end();
		auto* a = collisionPair.pair.first;
		auto* b = collisionPair.pair.second;

		if (wasInPrev)
		{
			CallEvent(a, b, "Stay");
		}
		else
		{
			if (collisionPair.info.penetrationDepth > 0.1f)
			{
				CallEvent(a, b, "Enter");
			}
		}
	}

	// exit
	for (const auto& prev : prevPairs)
	{
		auto it = currPairs.find(prev);
		if (it == currPairs.end())
		{
			if (prev.info.penetrationDepth > 0.1f)
			{
				CallEvent(prev.pair.first, prev.pair.second, "Exit");
			}
		}
	}

	// prevPairs 갱신
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
