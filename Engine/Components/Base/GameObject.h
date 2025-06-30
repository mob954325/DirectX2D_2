#pragma once
#include "pch.h"
#include "Utils/Singleton.h"
#include "Component.h"
#include "Transform.h"
#include "Core/EngineData.h"

/// <summary>
/// 모든 게임 오브젝트가 상속받는 클래스로 Component만 담고 Component관련 함수만 포함되어있음
/// </summary>
class GameObject
{
public:
	GameObject();
	virtual ~GameObject();

	/// <summary>
	/// Update 실행 전 한 번 실행되는 함수
	/// </summary>
	virtual void Start() = 0;

	/// <summary>
	/// 업데이트 실행
	/// </summary>
	virtual void Update() = 0;

	/// <summary>
	/// 씬 종료시 실행될 함수
	/// </summary>
	virtual void OnDestroy() = 0;

	Transform* transform = {};

	template <typename T>
	T* AddComponent()
	{
		static_assert(std::is_base_of<Component, T>::value, "T must derive from Component");

		T* comp = new T;
		comp->owner = this;
		components.push_back(comp);

		DispatchComponentToSystem(comp);
		comp->OnStart();

		return comp;
	}

	template <typename T>
	T* GetComponent()
	{
		for (Component* comp : components)
		{
			if (typeid(*comp) == typeid(T))
			{
				return static_cast<T*>(comp);
			}
		}
	}

	void RemoveComponent(Component* targetComp)
	{
		for (auto it = components.begin(); it != components.end();)
		{
			if (*it == targetComp)
			{
				delete* it;
				it = components.erase(it);
			}
			else
			{
				++it;
			}
		}
	}

	// 오브젝트 제거 관련
	void MarkForRemoval() { shouldRemove = true; };				// 제거할 오브젝트라고 마킹
	bool IsMarkedForRemoval() const { return shouldRemove; }

	// 오브젝트 추가 관련
	void SetEarlyCreated() { earlyCreated = false; };			// 추가된 오브젝트라고 마킹
	bool IsEarlyCreated() const { return earlyCreated; }
	
	// get/set
	EngineData::RenderLayer GetRenderLayer() const { return renderLayer; }
	int GetRenderLayerIndex() const { return (int)renderLayer; }

protected:
	EngineData::RenderLayer renderLayer = EngineData::RenderLayer::None;

private:
	void DispatchComponentToSystem(Component* comp);

	std::vector<Component*> components; // 컴포넌트를 담는 컨테이너
	bool shouldRemove = false;
	bool earlyCreated = true;
};

